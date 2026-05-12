class Solution {
  public:
    int helper(int n,char last,int len){
        if(len == n) return 1;
        if(last=='1'){
            return helper(n,'0',len+1);
        }
        else{
            return helper(n,'1',len+1)+helper(n,'0',len+1);
        }
    }
    int countStrings(int n) {
        return helper(n,'1',1)+helper(n,'0',1);
    }
};