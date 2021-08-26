/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/24
 */
object findCheapestPrice_787 {
  def findCheapestPrice(n: Int, flights: Array[Array[Int]], src: Int, dst: Int, k: Int): Int = {
    //DP Array, first dimension accounts for time of transit: 0-k
    //          second dimension accounts for city: 0-n-1
    val prices = Array.fill(k + 1, n)(Int.MaxValue)
    for (triplet <- flights) {
      if (triplet(0) == src) {
        prices(0)(triplet(1)) = triplet(2)
      }
    }
    for (transit <- Range.inclusive(1, k)) {
      for (triplet <- flights) {
        if (prices(transit - 1)(triplet(0)) != Int.MaxValue) {
          prices(transit)(triplet(1)) =
            math.min(prices(transit - 1)(triplet(0)) + triplet(2), prices(transit)(triplet(1)))
        }
      }
    }
    var ans = Int.MaxValue
    for (transit <- Range.inclusive(0, k)) {
      ans = math.min(ans, prices(transit)(dst))
    }
    if (ans == Int.MaxValue) {
      -1
    } else {
      ans
    }
  }

  def main(args: Array[String]): Unit = {
    println()
  }
}
