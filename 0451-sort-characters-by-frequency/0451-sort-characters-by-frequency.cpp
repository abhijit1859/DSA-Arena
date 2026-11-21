class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char x:s){
            freq[x]++;
        }
        priority_queue<pair<int,char>> pq;

        for(auto it:freq){
            pq.push({it.second,it.first});
        }

        string ans="";

        while(!pq.empty()){
            auto [frequency,charac]=pq.top();
            pq.pop();
            ans+=string(frequency,charac);

        }
        return ans;

    }
};