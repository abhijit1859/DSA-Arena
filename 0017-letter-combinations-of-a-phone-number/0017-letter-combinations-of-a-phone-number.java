class Solution {
    public List<String> letterCombinations(String digits) {
        
        ArrayList<String> names = new ArrayList<>();
        if(digits.isEmpty()){
            return names;
        }
        pad("",digits,names);
        return names;
    }
    private static void pad(String p,String up,ArrayList<String> list){

        String[] map ={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        if(up.isEmpty()){
            System.out.println(p);
            list.add(p);
            return;
        }

        int digit = up.charAt(0)-'0';
        String letters = map[digit];
        for(int i=0;i<letters.length();i++){
            char ch = letters.charAt(i);
            pad(p+ch,up.substring(1),list);
        }
         
    }
}