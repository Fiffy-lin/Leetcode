// 给你一个二进制串 s  （一个只包含 0 和 1 的字符串），我们可以将 s 分割成 3 个 非空 字符串 s1, s2, s3 （s1 + s2 + s3 = s）。

// 请你返回分割 s 的方案数，满足 s1，s2 和 s3 中字符 '1' 的数目相同。

// 由于答案可能很大，请将它对 10^9 + 7 取余后返回。

 

// 示例 1：

// 输入：s = "10101"
// 输出：4
// 解释：总共有 4 种方法将 s 分割成含有 '1' 数目相同的三个子字符串。
// "1|010|1"
// "1|01|01"
// "10|10|1"
// "10|1|01"
// 示例 2：

// 输入：s = "1001"
// 输出：0
// 示例 3：

// 输入：s = "0000"
// 输出：3
// 解释：总共有 3 种分割 s 的方法。
// "0|0|00"
// "0|00|0"
// "00|0|0"
// 示例 4：

// 输入：s = "100100010100110"
// 输出：12
 

// 提示：

// s[i] == '0' 或者 s[i] == '1'
// 3 <= s.length <= 10^5


class Solution {
public:
    int numWays(string s) {
        long long cnt=0;
        for(const char x:s)
            if(x=='1')
                cnt++;
        if(cnt==0){
            return ((s.length()-1)*(s.length()-2)/2)%(long long)(pow(10,9)+7);
        }
        if(cnt<3||cnt%3)
            return 0;
        cnt/=3;
        long long zero1=0,zero2=0,ones=0;
        for(const char x:s){
            if(x=='1')
                ones++;
            if(ones>=cnt&&ones<(cnt+1))
                zero1++;
            else if(ones>=2*cnt&&ones<(2*cnt+1))
                zero2++;
        }
        int res=zero1*zero2%(long long)(pow(10,9)+7);
        return res;
    }
};