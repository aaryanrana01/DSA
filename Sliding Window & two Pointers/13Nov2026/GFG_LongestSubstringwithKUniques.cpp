class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int r =0, l =0, maxLen=0;
        unordered_map<char, int> mpp;
        
        for(int r=0; r<s.size(); r++){
            
            mpp[s[r]]++;
            
            if(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                
                l++;
            }
            
            if(mpp.size() == k) maxLen = max(maxLen, r-l+1);
            
        }
        
        //return (mpp.size() == k)? maxLen : -1;
        //It represents the number of unique characters in the current 
        //window at the end of the loop.
        //But we want to know whether we encountered ANY valid window 
        //during the entire traversal.
        
        
        return maxLen == 0 ? -1 : maxLen;
    }
};