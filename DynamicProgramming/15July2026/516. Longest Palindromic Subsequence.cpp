// class Solution {
// public:
//     int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>>&dp){
//         if(ind1 == 0 || ind2 == 0) return 0;
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

//         if(s[ind1-1] == t[ind2-1]) return  1 + solve(ind1-1, ind2-1, s, t, dp);
//         else return max( solve(ind1-1, ind2, s, t, dp), solve(ind1, ind2-1, s, t, dp));

//     }
//     int longestPalindromeSubseq(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());

//         int n= s.size();
//         vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
//         return solve(n,n,s,t,dp);
        
//     }
// };


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n= s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int i =1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);

            }
        }

        return dp[n][n];
        
        
    }
};