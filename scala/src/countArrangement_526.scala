/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/16
 */
object countArrangement_526 {
  def countArrangement(N: Int): Int = {
//    (1 to n).permutations.count(r => r.zip(1 to n).forall { case (x, y) => (x % y == 0) || (y % x == 0) })
    val res = Array.fill(1 << N)(0)
    res(0) = 1
    (0 until (1 << N)).foreach(i => {
      var idx = 1
      (0 until N).foreach(j => if (((i >> j) & 1) > 0) idx += 1)
      (1 to N).foreach(k =>
        if (!(((i >> (k - 1)) & 1) > 0) && (k % idx == 0 || idx % k == 0))
          res(i | (1 << (k - 1))) += res(i)
      )
    })
    res((1 << N) - 1)
  }
  def main(args: Array[String]): Unit = {
    println(countArrangement(11))
  }
}
