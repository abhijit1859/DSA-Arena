class Solution {
    public boolean checkIfPangram(String sentence) {
        String dummy= "";
        Set<Character> letters = new HashSet<>();
        for(int i=0;i<sentence.length();i++){
            char ch = sentence.charAt(i);

            letters.add(ch);
        }
        if(letters.size()==26){
            return true;
        }else{
            return false;
        }
    }
}