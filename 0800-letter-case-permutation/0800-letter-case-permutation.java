class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> list = new ArrayList<>();
       
        permute(s,0,list);
       return list;
    }
    private static void permute(String s,int index,List<String> list){
        
        for(int i=index;i<s.length();i++){
            char ch = s.charAt(i);
            if(Character.isLetter(ch)){
                char flipped = Character.isLowerCase(ch)?
                Character.toUpperCase(ch):Character.toLowerCase(ch);
                String newStr = s.substring(0, i) + flipped + s.substring(i + 1);

                permute(newStr, i + 1,list);
            }
           
        }
        list.add(s);
         
    }
}