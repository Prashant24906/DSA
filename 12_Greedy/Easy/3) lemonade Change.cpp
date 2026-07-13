class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0,ten = 0;
        for(int i = 0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                ten++;
                if(five==0) return false;
                five--;
            }
            else{
                if(ten>0){
                    if(five==0) return false;
                    ten--;
                    five--;
                }
                else{
                    if(five<3) return false;
                    five-=3;
                }
            }
        }
        return true;
    }
};
