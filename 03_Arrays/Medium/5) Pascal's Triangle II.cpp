class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        long long int a = 1;
        vector<int> ans;
        ans.push_back(1);
        for(int i = 1;i<rowIndex;i++){
            a = a* (rowIndex-i);
            a = a/i;
            ans.push_back(a);
        }
        return ans;
    }
};
