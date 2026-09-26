class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(int brack=0;brack<knowledge.size();brack++){
            mp[knowledge[brack][0]] = knowledge[brack][1];
        }
        int i=0;
        string ans;
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                string key;
                while(s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if(mp.find(key)!=mp.end()){
                    ans+=mp[key];
                }else{
                    ans+='?';
                }
                i++;
            }else{
                ans+=s[i];
                i++;
            }
        }
        return ans;

    }
};