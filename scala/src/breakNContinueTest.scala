/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/23
 */
object breakNContinueTest {
  import scala.util.control.Breaks.{ break, breakable }
  def main(args: Array[String]): Unit = {
    // testing break
    breakable {
      for (i <- Range(0, 5)) {
        if (i == 3) {
          break
        }
        println(i)
      }
    }
    // testing continue
    for (i <- Range(0, 5)) {
      breakable {
        if (i == 3) {
          break
        }
        println(i)
      }
    }
  }
}
