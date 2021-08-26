/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/23
 */
object getMaximumGenerated_1646 {
  def getMaximumGenerated(n: Int): Int = {
    if (n == 0) return 0
    var maxVal = 1
    val arr = Array.ofDim[Int](n + 1)
    arr(1) = 1
    for (i <- arr.indices) {
      if (2 * i >= 2 && 2 * i <= n) {
        arr(2 * i) = arr(i)
        maxVal = math.max(maxVal, arr(2 * i))
      }
      if ((2 * i + 1) >= 2 && (2 * i + 1) <= n) {
        arr(2 * i + 1) = arr(i) + arr(i + 1)
        maxVal = math.max(maxVal, arr(2 * i + 1))
      }
    }
    maxVal
  }

  def main(args: Array[String]): Unit = {
    println(getMaximumGenerated(7))
  }
}
