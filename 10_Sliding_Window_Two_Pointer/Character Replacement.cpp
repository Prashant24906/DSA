class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        int maxfreq = 0;
        int temp = k;
        for(int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            maxfreq = max(maxfreq,mp[s[r]]);
            while(r-l+1-maxfreq>k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
