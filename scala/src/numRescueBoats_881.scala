/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/26
 */
object numRescueBoats_881 {
  def numRescueBoats(people: Array[Int], limit: Int): Int = {
    var (first, last, ans) = (0, people.length - 1, 0)
    val sortedPeople = people.sorted
    while (first <= last) {
      if (sortedPeople(last) + sortedPeople(first) > limit) {
        last -= 1
      } else {
        last -= 1
        first += 1
      }
      ans += 1
    }
    ans
  }
}
