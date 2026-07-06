class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cap=0;
        unordered_map<int,int> mp;
        int maxLen=0;
        int left=0;
        for(int right=0;right<fruits.size();right++){
            mp[fruits[right]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;

            }
            maxLen=max(right-left+1,maxLen);
        }
        return maxLen;
    }
};