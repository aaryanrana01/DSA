class Solution {
public:
    int solve(vector<int>&coins, int ind, int amount, vector<vector<int>>&dp){
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
            return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int pick = 0;
        if(coins[ind] <= amount) pick = solve(coins, ind, amount-coins[ind], dp);
        int notPick = solve(coins, ind-1, amount, dp);

        return dp[ind][amount] = pick + notPick;

    }
    int change(int amount, vector<int>& coins) {
        // int n= coins.size();
        // vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        // return solve(coins, n-1, amount, dp);
        int n = coins.size();
        vector<vector<long long>>dp(n, vector<long long>(amount+1, 0));

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(int ind = 1; ind < n; ind++){
            for(int amo = 0; amo <= amount; amo++){

                long long pick = 0;
                if(coins[ind] <= amo) pick = dp[ind][amo-coins[ind]];
                long long notPick = dp[ind-1][amo];

                dp[ind][amo] = pick + notPick;
            }
        }
        return dp[n-1][amount];
    }
};