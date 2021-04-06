// https://leetcode-cn.com/problems/open-the-lock/

class Solution {
public:
    string up(string& t,int pos){
        string s=t;
        if(s[pos]=='9')
            s[pos]='0';
        else
            s[pos]++;
        return s;
    }
    string down(string& t,int pos){
        string s=t;
        if(s[pos]=='0')
            s[pos]='9';
        else
            s[pos]--;
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");
        unordered_set<string> inqueue;
        inqueue.insert("0000");
        int step=0;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;++k){
                string cur=q.front();
                q.pop();
                if(find(deadends.begin(),deadends.end(),cur)!=deadends.end())
                    continue;
                if(cur==target)
                    return step;
                for(int i=0;i<4;++i){
                    string upstring=up(cur,i);
                    string downstring=down(cur,i);
                    if(!inqueue.count(upstring)){
                        q.push(upstring);
                        inqueue.insert(upstring);
                    }
                    if(!inqueue.count(downstring)){
                        q.push(downstring);
                        inqueue.insert(downstring);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};