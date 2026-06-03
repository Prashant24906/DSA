class Solution {
public:
    void helper(int n,string s,vector<string> &ans,int open,int close){
        if(open==0&&close==0){
            ans.emplace_back(s);
            return ;
        }
         if(open>0)
            helper(n,s+"(",ans,open-1,close);
        if(close>open){
             helper(n,s+")",ans,open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,"(",ans,n-1,n);
        return ans;
    }
};
