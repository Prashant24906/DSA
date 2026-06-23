class Solution {
public:
    bool hasMissingChar(vector<int>& arr){
        if(arr[0]==0 ||arr[1]==0||arr[2]==0) return true; 
        return false;
    }
    int numberOfSubstrings(string s) {
        long long n = s.size();
        long long totalPossible = n*(n+1)/2;
        long long NotPossible = 0;
        int l = 0;
        vector<int> c(3,0);
        for(int r = 0;r<n;r++){
            c[s[r]-'a']++;
            bool allin = hasMissingChar(c);
            if(!allin){
                while(!hasMissingChar(c)){
                    c[s[l]-'a']--;
                    l++;
                }
            }
            NotPossible+=(r-l+1);
        } 
        return totalPossible-NotPossible;
    }
};
