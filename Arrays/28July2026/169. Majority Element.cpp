// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         map<int, int> mpp;

//         for(int i= 0; i<n; i++){
//             mpp[nums[i]]++;
//         }

//         for(auto it: mpp){
//             if(it.second > n/2) return it.first;
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int cnt = 0;
        int n = nums.size();

        for(int i=0; i< n; i++){
            if(cnt == 0){
                element = nums[i];
                cnt = 1;
            }
            else if(element == nums[i]){
                cnt++;           
                // else if isiliye lagaya kyunki 1 baar jb count ho gaya dubara nahi krna caahiye aapko 
            }
            else{
                cnt--;          
                 // jo cancel kr raha hai, uska existance abhi ke liye khatam. Same element kaat bhi de aur agle me add bhi ho jaaye aise nahi ho sakta isiliye isko add nahi kiya. Next element will start the cnt if cnt == 0
            }
        }

        int count = 0;
        for(int i =0; i<n; i++){
            if(element == nums[i]) count++;
        }

        if(count > n/2) return element;
        else return -1;
    }
};