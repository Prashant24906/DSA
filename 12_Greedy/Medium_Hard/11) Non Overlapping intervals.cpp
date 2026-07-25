class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> total;
        for (int i = 0; i < intervals.size(); i++) {
            total.push_back({intervals[i][1], i, intervals[i][0]});
        }
        sort(total.begin(), total.end());
        int count = 0;
        int LastEnd = INT_MIN;
        for (auto it : total) {
            if (it[2] >= LastEnd) {
                LastEnd = it[0];
            }
            else
                count++;
        }
        return count;
    }
};
