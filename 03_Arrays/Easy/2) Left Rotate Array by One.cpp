class Solution {
public:
    void rotate(vector<int>& arr, int d) {
        int n = arr.size();
        d = d%n;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.begin()+d);
    }
};
