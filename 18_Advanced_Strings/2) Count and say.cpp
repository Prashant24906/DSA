class Solution {
public:
    string solve(string& s){ 
        int i = 0;
        string temp = "";
        while(i<s.size()){
            int j = i;
            int cnt = 0;
            while(j<s.size()&&s[j]==s[i]){
                cnt++;
                j++;
            }
            temp+=cnt+'0';
            temp+=s[i];
            i = j;
        }
        cout<<temp<<" ";
        return temp;
    }
    string countAndSay(int n) {
        if (n==1) return "1";
        string s = "11";
        for(int i = 2;i<n;i++){
            s = solve(s);
        }
        return s;
    }
};
