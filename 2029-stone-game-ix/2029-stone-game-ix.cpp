class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]={0,0,0};
        for(int x:stones){
            cnt[x%3]++;
        }

        if(cnt[1]==0&&cnt[2]==0){
            return false;
        }

        if(cnt[1]>0&&cnt[2]>0){
            if(cnt[0]%2==0&&cnt[1]!=cnt[2]){
                return true;
            }
            if(cnt[0]%2==1&&abs(cnt[1]-cnt[2])>2){
                return true;
            }
        }
        if (cnt[1] == 0 || cnt[2] == 0) {
            return max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 == 1;
        }
        return abs(cnt[1]-cnt[2])>2 || cnt[0]%2==0;
    }
};