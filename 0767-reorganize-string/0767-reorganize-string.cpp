class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(char c:s){
            mp[c]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(pq.size()>=2){
            auto first=pq.top();
            pq.pop();
            auto second=pq.top();
            pq.pop();
            ans+=first.second;
            ans+=second.second;
            first.first--;
            second.first--;
            if(first.first>0) pq.push({first.first,first.second});
            if(second.first>0) pq.push({second.first,second.second});
        }

        if(!pq.empty()){
            auto last=pq.top();
            if(last.first>1) {
                return "";
            }
            ans+=last.second;
        }
        return ans;

    }
};