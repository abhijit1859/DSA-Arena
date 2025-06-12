class Solution {
    public int compress(char[] chars) {
        String s = "";
        int count=1;
       
        for(int i=1;i<chars.length;i++){
           
            if(chars[i]==(chars[i - 1])){
                count++;
            }else{
                 s+=chars[i-1];
                 if (count > 1) {
                    s += count;
                }
                count = 1;
            }
            
          
          
            
        }
        
        s += chars[chars.length - 1];
        if (count > 1) {
            s += count;
        }
        
        for(int i=0;i<s.length();i++){
            chars[i] = s.charAt(i);
        }
        System.out.println(Arrays.toString(chars));

        return s.length();
        
       
    
    }
}