class Solution {
  public:
  void helper(int n,vector<string> &ans,int index,string temp,string s){
        if(index==n){
            if(temp!="")ans.push_back(temp);
            return ;
        }
        helper(n,ans,index+1,temp+s[index],s);
        helper(n,ans,index+1,temp,s);
  }
    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        vector<string> ans;
        helper(n,ans,0,"",s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};