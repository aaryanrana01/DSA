class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        vector<int> hash(256, -1);
        int maxLen = 0, len = 0;
        int n = s.size();

        for(int r=0; r<n; r++){
            if( hash[s[r]] != -1 ){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }

            hash[s[r]] = r;
            len = r-l+1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
        
    }
};