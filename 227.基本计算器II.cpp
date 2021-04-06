// https://leetcode-cn.com/problems/basic-calculator-ii/

// https://leetcode-cn.com/problems/basic-calculator-ii/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    map<char,int> prio;
    stack<long long> nums;
    stack<char> op;
    void calc(){
        long long num1,num2,res;
        num2=nums.top();
        nums.pop();
        num1=nums.top();
        nums.pop();
        switch(op.top()){
            case '+':
                res=num1+num2;
                nums.push(res);
                break;
            case '-':
                res=num1-num2;
                nums.push(res);
                break;
            case '*':
                res=num1*num2;
                nums.push(res);
                break;
            case '/':
                res=num1/num2;
                nums.push(res);
                break;
            case '^':
                res=pow(num1,num2);
                nums.push(res);
                break;
            case '%':
                res=num1%num2;
                nums.push(res);
        }
        op.pop();
    }
    int calculate(string s) {
        prio['+']=0;
        prio['-']=0;
        prio['*']=1;
        prio['/']=1;
        prio['^']=2;
        prio['%']=2;
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        nums.push(0);
        for(int i=0;i<s.length();++i){
            if(!isdigit(s[i])){
                if(s[i]=='('){
                    op.push(s[i]);
                }
                else if(s[i]==')'){
                    while(op.top()!='(')
                        calc();
                    op.pop();
                }else{
                    if(op.empty()||prio[s[i]]>prio[op.top()])
                        op.push(s[i]);
                    else{
                        while(!op.empty()&&op.top()!='('&&prio[s[i]]<=prio[op.top()])
                            calc();
                        op.push(s[i]);
                    }
                }
            }else{
                long long num=s[i]-'0';
                int j=i+1;
                while(isdigit(s[j])){
                    num=num*10+s[j]-'0';
                    j++;
                }
                i=j-1;
                nums.push(num);
            }
        }
        while(!op.empty())
            calc();
        return int(nums.top());
    }
};

int main(){
    Solution solution;
    cout<<solution.calculate("(1+(4+5+2)-3)+(6+8)");
    return 0;
}
