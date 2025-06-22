class Solution {
    public int maxDepth(String s) {
       
        int current=0;
        int max=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                
                current++;
                max=Math.max(current,max);

            }else if(s.charAt(i)==')'){
                
                current--;
                max=Math.max(current,max);
            }
            

        }
        
        System.out.println(max);
        return max;
    }

}