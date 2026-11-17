class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // if(nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());

        // int count = 1;
        // int maxCount = 1;
        // for(int i=0; i<nums.size()-1; i++){
        //     if(nums[i+1] == nums[i]) continue;

        //     if(nums[i+1] == nums[i]+1){
        //         count++;
        //         maxCount = max(count, maxCount);
        //     }
        //     else count = 1;
        // }

        // return maxCount;

        unordered_set<int> st;
        int maxLen = 0;

        for(int it: nums) st.insert(it);

        for(int x: st){
            int num  = x;

            int count = 1;
            if(st.find(num-1) == st.end()){

                while(st.find(num+1) != st.end()){
                    count++;
                    num++;
                    //maxLen = max(count, maxLen);
                }
            }

            maxLen = max(count, maxLen);
        }


        return maxLen;

    }
};