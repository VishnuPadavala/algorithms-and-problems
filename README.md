# algorithms-and-problems
class Solution {
public:
    int longestPalindromeSubseq(string s) {
         string s1;
        for(char ch:s){
            s1+=ch;
        }
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int size=fun(s.size()-1,s.size()-1,s,s1,dp);
        return size;
    }
    int fun(int n1,int n2,string &a,string &b,vector<vector<int>>&dp){
        if(n1<0||n2<0)return 0;
        if(dp[n1][n2]!=-1)return dp[n1][n2];
        if(a[n1]==b[n2]){
            return dp[n1][n2]=1+fun(n1-1,n2-1,a,b,dp);
        }
        return dp[n1][n2]=max(fun(n1-1,n2,a,b,dp),fun(n1,n2-1,a,b,dp));
    }
};
