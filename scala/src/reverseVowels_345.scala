/**
 * Copyright @2021 AI, ZHIHU Inc. (zhihu.com)
 *
 * @author duyilin <duyilin@zhihu.com>
 *         2021/08/19
 */
object reverseVowels_345 {
  private def vowels = "aeiouAEIOU"
  def reverseVowels(s: String): String = {
    val isVowel = vowels.zip(List.fill(10)(true)).toMap
    val len = s.length
    var (i, j) = (0, len - 1)
    val sArr = s.toCharArray
    while (i < j) {
      while (i < len && !isVowel.contains(sArr(i))) {
        i += 1
      }
      while (j > 0 && !isVowel.contains(sArr(j))) {
        j -= 1
      }
      if (i < j) {
        val temp = sArr(i)
        sArr(i) = sArr(j)
        sArr(j) = temp
        i += 1
        j -= 1
      }
    }
    sArr.mkString("")
  }

  def main(args: Array[String]): Unit = {
    println(reverseVowels("Leetcode"))
  }
}
