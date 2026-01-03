class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char c:s){
            map[c]++;
        }
        int n=s.size();

        vector<vector<int>> bucket(n+1);
        for(auto &it:map){
            bucket[it.second].push_back(it.first);
        }
        string result;

        for(int i=n;i>0;i--){
            for(char c:bucket[i]){
                result.append(i,c);
            }
        }

        return result;
    }
};