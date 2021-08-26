import scala.collection.mutable.{ArrayBuffer, Map => MutableMap}

class TreeNode(var _value: Int) {
  var value: Int = _value
  var left: TreeNode = null
  var right: TreeNode = null
}

var parentMap = MutableMap[Int, TreeNode]()


def findParent(root: TreeNode): Unit = {
  if (root != null) {
    if (root.left != null) {
      parentMap += root.left.value -> root
      findParent(root.left)
    }
    if (root.right != null) {
      parentMap += root.right.value -> root
      findParent(root.right)
    }
  }
}
def findAns(cur: TreeNode, from: TreeNode, dis: Int, target: Int, answer: ArrayBuffer[Int]): Unit = {
  if (cur == null) {}
  else if (dis == target) {
    answer += cur.value
  }
  else {
    if (cur.left != from) {
      findAns(cur.left, cur, dis + 1, target, answer)
    }
    if (cur.right != from) {
      findAns(cur.right, cur, dis + 1, target, answer)
    }
    if (parentMap.getOrElse(cur.value, null) != null && parentMap(cur.value) != from) {
      findAns(parentMap(cur.value), cur, dis + 1, target, answer)
    }
  }
}
def distanceK(root: TreeNode, target: TreeNode, k: Int): List[Int] = {
  val answer = new ArrayBuffer[Int]
  findParent(root)
  findAns(target, null, 0, k, answer)
  if (answer.isEmpty)
    List()
  else
    answer.toList
}
val node = new TreeNode(1)
distanceK(node, node, 0)

val hashmap = scala.collection.mutable.Map[Int, Int]()
def singleNumber(nums: Array[Int]): Int = {
  hashmap.clear()
  nums.foreach(r => hashmap(r) = hashmap.getOrElse(r, 0) + 1)
  hashmap.find(_._2 == 1).get._2
}