class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int final_ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            long long ans = 1LL * mid * mid;

            if(ans <= x){
                final_ans = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }

        return final_ans;
    }
};