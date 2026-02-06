class Solution {
public:
    vector<string> temp;
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        generate(digits,"",0);
        return temp;
    }

    void generate(string &digits,string curr,int index){
        if(index==digits.size()){
            temp.push_back(curr);
            return;
        }

        string let=mp[digits[index]];

        for(char c:let){
            generate(digits,curr+c,index+1);
        }
    }
};