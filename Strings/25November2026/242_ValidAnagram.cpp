class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        vector<int> ans(256, 0);
        for(int i=0; i < s.size(); i++){
            ans[ s[i] ] ++; 
        }

        for(int i =0; i< t.size(); i++){
            if(ans[ t[i] ] != 0) ans[t[i]] --;
            else break;
        }

        for(int i=0; i<256; i++) {
            if(ans[i] != 0) return false;
        }


        return true;
    }
};