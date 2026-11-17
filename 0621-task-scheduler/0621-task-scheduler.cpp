class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char,int> freq;
        for(char c:tasks){
            freq[c]++;
        }
        for(auto &it:freq){
            pq.push(it.second);
        }

        queue<pair<int,int>> cooldown;
        
        int time=0;
        while(!pq.empty()||!cooldown.empty()){
            if(!cooldown.empty()&&cooldown.front().second<=time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if(!pq.empty()){
                int remaining=pq.top();
                pq.pop();
                remaining--;
                if(remaining>0){
                    cooldown.push({remaining,time+n+1});
                }
            }
            time++;
        }
        return time;
    }
};