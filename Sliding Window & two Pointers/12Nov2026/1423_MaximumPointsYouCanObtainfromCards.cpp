class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int maxSum =0, lsum=0, sum=0;
        for(int i=0; i<k; i++) lsum += arr[i];

        maxSum = lsum;
        sum = lsum;
        int rind = arr.size()-1;

        for(int i=k-1; i>=0; i--){
            sum -= arr[i];
            sum += arr[rind];

            rind--;
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};