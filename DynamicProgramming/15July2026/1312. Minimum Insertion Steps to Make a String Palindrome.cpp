class Solution {
public:
    int minInsertions(string s) {

        //write the solution to find the longest palindromic subsequence
        string t =s;
        reverse(t.begin(), t.end());
        int n= s.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        //fill the dp table for finding the length of LCS
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){

                if(s[i-1] == t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        //Total len of string se subtract the lcs length
        int lcs = dp[n][n];
        return n- lcs;
        
    }
};