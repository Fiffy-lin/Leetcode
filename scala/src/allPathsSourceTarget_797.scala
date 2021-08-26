/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/25
 */
object allPathsSourceTarget_797 {
  import scala.collection.mutable
  val res: mutable.ArrayBuilder[List[Int]] = Array.newBuilder[List[Int]]
  def allPathsSourceTarget(graph: Array[Array[Int]]): List[List[Int]] = {
    val dest = graph.length - 1
    backtrace(0, dest, List(0), graph)
    res.result().toList
  }
  def backtrace(cur: Int, dest: Int, path: List[Int], graph: Array[Array[Int]]): Unit = {
    if (cur == dest) { res.addOne(path) }
    else {
      for (next <- graph(cur)) {
        backtrace(next, dest, path :+ next, graph)
      }
    }
  }
}
