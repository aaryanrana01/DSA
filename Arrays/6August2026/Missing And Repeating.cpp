// class Solution {
//   public:
//     vector<int> findTwoElement(vector<int>& arr) {
//         // code here
//         int missingNumber = 0;
//         int reptNumber = 0;
//         int n = arr.size();
//         vector<int>hashArray(n+1, 0);
        
//         for(int i= 0; i<n; i++){
//             hashArray[ arr[i] ] += 1;
//         }
//         for(int i= 1; i <= n; i++){
//             if(hashArray[i] == 0) missingNumber = i;
//             if(hashArray[i] == 2) reptNumber = i;
            
//         }
//         vector<int>ans({reptNumber, missingNumber});
//         return ans;
//     }
// };

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long S = 0;
        long long S2 = 0;
        long long SN = (1LL * n*(n+1) )/2;
        long long S2N = ( 1LL * n*(n+1)*(2*n + 1)) / 6;
        
        // int val1 = S - SN;
        // int val2 = S2- S2N;
        
        for(int i =0 ; i< n; i++){
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];   // or rather use 1LL
        }
        
        long long val1 = S - SN;
        long long val2 = S2- S2N;
        val2 = val2/val1;
        
        long long x = (val2+val1)/2;
        long long y = x- val1;
        
        return {(int)x, (int)y};
    }
};