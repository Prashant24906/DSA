class Solution {
public:
    int countPrimes(int l,int r) {
        vector<int>prime(r+1,1);
        int cnt = 0;
        for(int i = 2;i*i<=r;i++){
            if(prime[i]==1){
                for(int j = i*i;j<=r;j+=i){
                    prime[j] = 0;
                }
            }
        }
        for(int i = l;i<=r;i++){
            if(i==1) continue;
            if(prime[i]==1)cnt++;
        }
        return cnt;
    }
};