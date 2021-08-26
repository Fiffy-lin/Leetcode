/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/20
 */
object reverseStr_541 {
  def reverseStr(s: String, k: Int): String = {
//    def helper(toRev: String): String = {
//      toRev.length match {
//        case len if len > 2 * k => toRev.slice(0, k).reverse + toRev.slice(k, 2 * k) + helper(toRev.splitAt(2 * k)._2)
//        case len if len > k => toRev.splitAt(k)._1.reverse + toRev.splitAt(k)._2
//        case _ => toRev.reverse
//      }
//    }
//    helper(s)
    val sBuilder = new StringBuilder
    for (i <- 0 until s.length by 2 * k) {
      val revEnd = math.min(s.length, i + k)
      val nonRevEnd = math.min(s.length, i + 2 * k)
      sBuilder ++= s.slice(i, revEnd).reverse
      sBuilder ++= s.slice(revEnd, nonRevEnd)
    }
    sBuilder.result()
  }

  def main(args: Array[String]): Unit = {
    println(reverseStr("leetcode", 2))
  }
}
