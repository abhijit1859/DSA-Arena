class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        checkMinimum(s, 0, temp);
        return result;
    }

    void checkMinimum(string s, int index, vector<string>& temp) {
        if (index >= s.size()) {
            result.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPallin(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                checkMinimum(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    bool isPallin(string &s,int start,int end){
   
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};