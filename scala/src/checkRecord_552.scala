/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/18
 */
object checkRecord_552 {
  private val mod = 1000000007
  def checkRecord(n: Int): Int = {
    // First dimension 0-n:day; second dimension 0-1:A; third dimension 0-2:L
    val dp = Array.ofDim[Int](n + 1, 2, 3)
    dp(0)(0)(0) = 1
    val ans = dp.tail.scanLeft(dp(0)) { case (prev, curr) =>
      val P = curr.zip(prev).map { case (oneDArrCurr, oneDArrPrev) =>
        oneDArrPrev.zip(oneDArrCurr).map { case (prevVal, currVal) => (prevVal + currVal) % mod }
      }
      prev(0).foreach { prevVal =>
        P(1)(0) += prevVal
        P(1)(0) %= mod
      }
      P.zip(prev).map { case (oneDArrCurr, oneDArrPrev) =>
        oneDArrCurr.head +: oneDArrCurr.tail.zip(oneDArrPrev).map { case (currVal, prevVal) =>
          (prevVal + currVal) % mod
        }
      }
    }
    for (i <- Range.inclusive(1, n)) {
      // if today is P
      for (j <- Range(0, 2); k <- Range(0, 3)) {
        dp(i)(j)(0) += dp(i - 1)(j)(k)
        dp(i)(j)(0) %= mod
      }
      // if today in A, only record with 0 A is accepted
      for (k <- Range(0, 3)) {
        dp(i)(1)(0) += dp(i - 1)(0)(k)
        dp(i)(1)(0) %= mod
      }
      // if today in L, only record with 0-1 L is accepted
      for (j <- Range(0, 2); k <- Range(0, 2)) {
        dp(i)(j)(k + 1) += dp(i - 1)(j)(k)
        dp(i)(j)(k + 1) %= mod
      }
    }
    var res = 0
    for (j <- Range(0, 2); k <- Range(0, 3)) {
      res += ans(n)(j)(k)
      res %= mod
    }
    res
  }

  def main(args: Array[String]): Unit = {
    println(checkRecord(2))
  }
}
