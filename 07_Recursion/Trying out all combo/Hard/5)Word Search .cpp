class Solution {
public:
    bool helper(string s,vector<string>& wordDict,int index){
        if(index==s.size()) return true;
        if(index>s.size()) return false;
        for(int i = 0;i<wordDict.size();i++){
            if(wordDict[i]==s.substr(index,wordDict[i].size())){
            bool ans = helper(s,wordDict,index+wordDict[i].size());
            if(ans==true) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s,wordDict,0);
    }
};
