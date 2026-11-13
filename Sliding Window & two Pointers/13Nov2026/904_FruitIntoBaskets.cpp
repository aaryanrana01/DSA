class Solution {
public:
    int totalFruit(vector<int>& nums) {
        
        int r =0, l=0;
        int k = 2;
        unordered_map<int, int>mpp;
        int maxLen = 0;

        while(r < nums.size()){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);

                l++;

            }

            if(mpp.size() <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};