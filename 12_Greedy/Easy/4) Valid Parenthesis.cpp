class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0,maxi = 0;
        for(int i = 0;i<s.size();i++){
            if(maxi<0) return false;
            if(s[i]=='('){
                maxi++;
                mini++;
            }
            else if(s[i]==')'){
                if(mini>0){
                    mini--;
                }
                maxi--;
            }
            else{
                if(mini==0){
                    maxi++;
                }
                else{
                    mini--;
                    maxi++;
                }
            }
        }
        return maxi>=0&&mini==0;
    }
};
