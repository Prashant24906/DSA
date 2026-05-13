class Solution {
public:
    bool check (string a,string b){
        cout<<a<<" "<< b<<endl;
        for(int i = 0;i<=a.size()-b.size();i++){
            if(a.substr(i,b.size())==b){
                return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int repeat = 1;
        string temp1 = a;
        while(a.size()<b.size()){
            repeat++;
            a+=temp1;
        }    
        if(a.find(b)!=string::npos)return repeat;
        repeat++;
        a+=temp1;
        if(a.find(b)!=string::npos)return repeat;
        return -1;
    }
};
