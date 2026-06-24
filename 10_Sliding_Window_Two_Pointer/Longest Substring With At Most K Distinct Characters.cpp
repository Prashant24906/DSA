class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        vector<int> characters(26,0);
        int uniques = 0;
        int l = 0,maxi = 0;
        bool uniquesGreater = false;
        for(int r = 0;r<n;r++){
            if(characters[s[r]-'a']==0){
                uniques++;
            }
            characters[s[r]-'a']++;
            while(uniques>k){
                characters[s[l]-'a']--;
                if(characters[s[l]-'a']==0){
                    uniques--;
                }
                l++;
            }
            if(uniques == k)
                maxi = max(maxi, r-l+1);
        }
        return uniques==k?maxi:-1;
    }
};
