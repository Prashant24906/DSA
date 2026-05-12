class Solution {
public:
bool isPalindrome(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}
    void helper(string s, vector<vector<string>>& ans,vector<string>& arr,string t,int index){
        if(index==s.size()){
            ans.push_back(arr);
            return ;
        }
        t = "";
        for(int i = index;i<s.size();i++){
            t+=s[i];
            if(isPalindrome(t)){
            arr.push_back(t);
            helper(s,ans,arr,t,i+1);
            arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
        if(s.size()==1){
            ans.push_back({s});
            return ans;
        }
        vector<string> arr;
        string temp = "";
        helper(s,ans,arr,temp,0);
        return ans;
    }
};