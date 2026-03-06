// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        vector<string>ans;
        string s="";
        fun(s,open,close,ans);
        return ans;
    }
    void fun(string s,int open,int close,vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open==close){
            string s1=s;
            s1.push_back('(');
            fun(s1,open-1,close,ans);
        }
        else if(open==0){
            string s1=s;
            s1.push_back(')');
            fun(s1,open,close-1,ans);
        }
        else{
            string s1=s,s2=s;
            s1.push_back(')');
            s2.push_back('(');
            fun(s1,open,close-1,ans);
            fun(s2,open-1,close,ans);
        }
    }
};
