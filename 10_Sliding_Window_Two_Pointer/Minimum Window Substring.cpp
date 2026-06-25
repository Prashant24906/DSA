class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int mini = s.size();
        int minLen = INT_MAX;
        int formed = 0;
        string ans = s;
        int l = 0;
        int left = 0,right = 0;
        if (m > n)
            return "";
        for (auto it : t) {
            need[it]++;
        }
        for (int r = 0; r < n; r++) {
            if (need.find(s[r]) != need.end()) {
                window[s[r]]++;
                if (window[s[r]] == need[s[r]])
                    formed++;
            }
            while (formed == need.size()) {
                if (need.find(s[l]) == need.end()) {
                    l++;
                    continue;
                }
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    left = l;
                    right = r;
                    // ans = s.substr(l, r - l + 1);
                }
                window[s[l]]--;
                if(window[s[l]] < need[s[l]])
                    formed--;
                l++;
            }
        }
        return minLen==INT_MAX?"":s.substr(left, right-left+1);
    }
};
