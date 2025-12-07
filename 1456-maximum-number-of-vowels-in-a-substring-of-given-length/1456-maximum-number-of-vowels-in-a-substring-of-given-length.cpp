class Solution {
public:
    int maxVowels(string s, int k) {
        int size=max_vowel(s.substr(0,k));
        cout << size;

        int maxSize=size;
        for(int i=1;i<s.size();i++){
            size=max_vowel(s.substr(i,k));
            maxSize=max(maxSize,size);
            cout << maxSize << " ";
        }
        return maxSize;
        
    }
    int max_vowel(string str){
        int vowel=0;
        for(int i=0;i<str.size();i++){
            int c=str[i];
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                vowel++;
            }
        }
        return vowel;
    }
};