class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        set<int> st;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                st.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};
