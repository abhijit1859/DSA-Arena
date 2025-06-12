class Solution {
    public boolean checkIfPangram(String sentence) {
        String dummy= "";
        for(int i=0;i<sentence.length();i++){
            char ch = sentence.charAt(i);

            if (Character.isLetter(ch) && !dummy.contains(String.valueOf(ch))) {
                dummy += ch;
            }
        }
        if(dummy.length()==26){
            return true;
        }else{
            return false;
        }
    }
}