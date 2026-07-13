class Solution {
public:
    // vector<int> dpMax;
    // vector<int> dpMin;
    // vector<bool> vis;

    // pair<int, int> solve(vector<int>& nums, int ind) {
        // if (ind == 0) {
        //     vis[ind] = true;
        //     return {nums[0], nums[0]};
        // }
        // if (vis[ind]) {
        //     return {dpMax[ind], dpMin[ind]};
        // }
        // auto prev = solve(nums, ind - 1);
        // int prevMax = prev.first;
        // int prevMin = prev.second;

        // int a = nums[ind];
        // int b = nums[ind] * prevMax;
        // int c = nums[ind] * prevMin;

        // dpMax[ind] = max(a, max(b, c));
        // dpMin[ind] = min(a, min(b, c));

        // vis[ind] = true;
        // return {dpMax[ind], dpMin[ind]};
    // }
    int maxProduct(vector<int>& nums) {
        // int n = nums.size();
        // dpMax.resize(n);
        // dpMin.resize(n);
        // vis.assign(n, false);
        // int ans = INT_MIN;

        // for (int i = 0; i < n; i++) {
        //     auto p = solve(nums, i);
        //     ans = max(ans, p.first);
        // }
        // return ans;



        // int n = nums.size();
        // vector<int> dpMax(n, 0);
        // vector<int> dpMin(n, 0);

        // dpMax[0] = nums[0];
        // dpMin[0] = nums[0];

        // int ans = nums[0];

        // for(int i=1; i<n; i++){

        //     int a = nums[i];
        //     int b = nums[i] * dpMax[i-1];
        //     int c = nums[i] * dpMin[i-1];

        //     dpMax[i] = max(a, max(b,c));
        //     dpMin[i] = min(a, min(b,c));

        //     ans = max(ans, dpMax[i]);

        // }
        // return ans;

        int n = nums.size();

        int dpMax = nums[0];
        int dpMin = nums[0];

        int ans = nums[0];

        for(int i=1; i<n; i++){

            int a = nums[i];
            int b = nums[i] * dpMax;
            int c = nums[i] * dpMin;

            dpMax = max(a, max(b,c));
            dpMin = min(a, min(b,c));

            ans = max(ans, dpMax);

        }
        return ans;
    }
};