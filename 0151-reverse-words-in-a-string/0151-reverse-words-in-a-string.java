class Solution {
    public String reverseWords(String s) {
        String s1 = s.trim();
        String[] arr = s1.split(" ");
        String s2="";
        
        int left=0;
        int right = arr.length-1;

        for(int i=arr.length-1;i>=0;i--){
         if(arr[i]==""){
                continue;
            }
            s2+=arr[i]+" ";
        }
       
        String result = s2.trim();
        return result;
    }
}