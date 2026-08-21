class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        generate(s,0,0,"");
        return ans;
    }

    void generate(string s,int idx,int parts,string curr){
        if(parts==4){
            if(idx==s.length()){
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }
        for(int len=1;len<=3;len++){
            if(idx+len>s.length()) break;
            string part=s.substr(idx,len);
            if(isValid(part)){
                generate(s,idx+len,parts+1,curr+part+".");
            }
        }
    }

    bool isValid(string s){
        if(s.length()>1&&s[0]=='0') return false;
        int num=stoi(s);
        return num>=0&&num<=255;
    }
};