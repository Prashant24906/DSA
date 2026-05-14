class Solution {
public:
    int strStr(string haystack, string needle) {
        // --- APPROACH 1: Z-ALGORITHM ---
        string s = needle+'#' + haystack;
        int n = s.size();
        vector<int> Z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r)
                Z[i] = min(r - i + 1, Z[i - l]);
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
                Z[i]++;
            if (Z[i] > 0 && i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
        }
        for(int i = 0;i<Z.size();i++){
            if(Z[i]==needle.size()){
                return i - needle.size()-1;
            }
        }
        return -1;
    }
};
