class Solution {
    public boolean rotateString(String s, String goal) {
        for(int i=0;i<s.length();i++){

            String rotated = rotate(s,i);
            System.out.println(rotated);
            if(rotated.equals(goal)){
                return true;
            }
            
        }
        return false;
    }

    private static String rotate(String s,int d){
        int length=s.length();
        return s.substring(length-d) + s.substring(0,length-d);
    }
}