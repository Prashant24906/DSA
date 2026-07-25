class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        } 
        vector<vector<int>> NewIntervals;
        int i = 0;
        while(i<n&&intervals[i][1]<newInterval[0]){
            NewIntervals.push_back(intervals[i++]);
        }
        while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        NewIntervals.push_back(newInterval);
        while(i<n){
            NewIntervals.push_back(intervals[i++]);
        }
        return NewIntervals;
    }
};
