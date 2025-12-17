class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> c;
        for(int i=0;i<sentence.length();i++){
            c.insert(sentence[i]);
        }

        if(c.size()==26){
            return true;
        }else{
            return false;
        }
    }
};