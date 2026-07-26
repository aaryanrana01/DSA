// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for(int i=0; i<n; i++){
//             int sum = 0;
//             for(int j=i;j<n; j++){
//                 sum += nums[j];

//                 if(sum == k) count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long, int> mpp;
        int n = nums.size();
        int count =0;
        int prefixSum = 0;
        int right = 0;
        // mpp[0] = 1 makes like sooo much easy now you don't have to handle prefixSum == k wala case seperately
        mpp[0] = 1;    // without even picking anything the prefixSum is still 0.

        while(right < n){
            prefixSum += nums[right];

            // if(prefixSum == k){
            //     count++;
            //     mpp[prefixSum] = 1;
            //     right++;
            //     continue;
            // }
            long long remSum = prefixSum - k;
            if(mpp.find(remSum) != mpp.end()) count = count + mpp[remSum];

            //if-else nahi lagaya tha 
            if(mpp.find(prefixSum) != mpp.end()){
                mpp[prefixSum]++;
            }
            else mpp[prefixSum] = 1;
            right++;
        }
        return count;
    }
};