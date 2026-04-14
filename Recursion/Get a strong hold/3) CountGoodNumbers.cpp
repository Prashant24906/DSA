class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long b,long long e,long long ans){
        if(e==0) return ans;
        if(e&1) return power(b,e-1,(ans*b)%MOD);
        else return power((b*b)%MOD,e/2,ans);
    }
    int countGoodNumbers(long long n) {
        long long temp = power(20,n/2,1);
        return n&1? (temp*5)%MOD:temp%MOD; 
    }
};