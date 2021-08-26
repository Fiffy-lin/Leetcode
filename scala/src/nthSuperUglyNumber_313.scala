import scala.collection.SortedSet

/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/09
 */
object nthSuperUglyNumber_313 {
  def nthSuperUglyNumber(n: Int, primes: Array[Int]): Int = {
    def f(ugly: SortedSet[Long]): LazyList[Long] = {
      ugly.head #:: f(ugly.tail ++ primes.map(_ * ugly.head))
    }
    f(SortedSet(1))(n - 1).toInt
  }

  def main(args: Array[String]): Unit = {
    println(nthSuperUglyNumber(12, Array(2, 7, 13, 19)))
  }
}
