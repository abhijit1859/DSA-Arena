class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;
        int twenties=0;
        for(int bill:bills){
            if(bill==5){
                fives++;
            }else if(bill==10){
                if(fives>0){
                    fives--;
                    tens++;
                }else{
                    return false;
                }
            }else{
                if(tens>0&&fives>0){
                    tens--;
                    fives--;
                    twenties++;
                }else if(fives>=3){
                    fives-=3;
                    twenties++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};