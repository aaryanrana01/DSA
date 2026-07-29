// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // vector<vector<int>>finalAns;
//         set<vector<int>> st;

//         for(int i=0; i<nums.size(); i++){

//             for(int j=i+1; j<nums.size(); j++){

//                 for(int k=j+1; k<nums.size(); k++){
//                     vector<int> ans;
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         vector<int> ans = {nums[i], nums[j], nums[k]};
//                         sort(ans.begin(), ans.end());

//                         st.insert(ans);
//                     }

//                 }

//             }
//         }

//         vector<vector<int>>finalAns(st.begin(), st.end());
//         return finalAns;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>>st;

//         for(int i=0; i<n; i++){
//             set<int> hashset;
//             for(int j=i+1; j<n; j++){
//                 int third = -(nums[i]+ nums[j]);
//                 if(hashset.find(third) != hashset.end()){
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end());

//                     st.insert(temp);

//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>>finalAns(st.begin(), st.end());
//         return finalAns;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i =0; i<n; i++){
            if(i >0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;

                }
            }
        }
        return ans;
    }
};