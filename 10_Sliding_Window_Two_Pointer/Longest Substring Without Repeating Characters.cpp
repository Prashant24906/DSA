class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> characters(256,-1);
        int maxi = 0;
        int l = 0;
        int r = 0;
        while(r<s.size()){
            if(characters[s[r]]!=-1){
                l = max(characters[s[r]] + 1, l);
            }
            int len = r - l + 1;
            
            maxi = max(len, maxi);
            
            characters[s[r]] = r;
            r++;
        }
        return maxi;        
    }
};
