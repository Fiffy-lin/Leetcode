//https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/

//给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。
//
//每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr = [1,4,1,2] ，那么你可以在中间添加 3 得到 [1,4,3,1,2] 。你可以在数组最开始或最后面添加整数。
//
//请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。
//
//一个数组的 子序列 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的子序列（加粗元素），但 [2,4,2] 不是子序列。
//
//
//
//示例 1：
//
//输入：target = [5,1,3], arr = [9,4,2,3,4]
//输出：2
//解释：你可以添加 5 和 1 ，使得 arr 变为 [5,9,4,1,2,3,4] ，target 为 arr 的子序列。
//示例 2：
//
//输入：target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
//输出：3
//
//
//提示：
//
//1 <= target.length, arr.length <= 105
//1 <= target[i], arr[i] <= 109
//target 不包含任何重复元素。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence
//  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


def lengthOfLIS(nums: Array[Int]): Int = {
  if (nums.isEmpty) return 0
  val n = nums.length
  //d表示长度为 len 的最长上升子序列的末尾元素的最小值
  val d = new Array[Int](n + 1)
  //初始赋值
  d(1) = nums(0)
  //len 记录目前最长上升子序列的长度
  var len = 1
  for (i <- nums.indices) {
    //如果遍历的当前项比d(len)大，最长子序列长度加1
    if (nums(i) > d(len)) {
      //把当前项放入d数组，索引index加1
      len += 1
      d(len) = nums(i)
    } else {
      //在 d[1 ... len]中找满足 d[i−1]<nums[j]<d[i] 的下标 i，并更新 d[i] = nums[j]
      //这是个典型的二分查找问题，即查找第一个大于目标值的索引
      //第一个大于目标值的索引设置为nums(i)，这样此时nums(i) > d(len)，结合另一个分支判断就很好理解
      var l = 1
      var r = len
      while (l <= r) {
        val mid = l + ((r - l) >> 1)
        if (d(mid) < nums(i)) l = mid + 1
        else r = mid - 1
      }
      //此时 l为第一个大于nums(i)的索引，可以证明遍历到当前，长度为l时，最长子序列末尾元素最小值就是nums(i)
      d(l) = nums(i)
    }
  }
  len
}

def minOperations(target: Array[Int], arr: Array[Int]): Int = {
  val numToIdxBuilder = Map.newBuilder[Int, Int]
  for (idx <- target.indices) {
    numToIdxBuilder += (target(idx) -> idx)
  }
  val numToIdx = numToIdxBuilder.result()
  var subIdx = Array[Int]()
  for (value <- arr) {
    if (numToIdx.getOrElse(value, None) != None) {
      subIdx = subIdx :+ numToIdx(value)
    }
  }
  if (subIdx.nonEmpty) {
    target.length - lengthOfLIS(subIdx)
  } else {
    target.length
  }
}

minOperations(Array(1, 3, 8), Array(2, 6))
