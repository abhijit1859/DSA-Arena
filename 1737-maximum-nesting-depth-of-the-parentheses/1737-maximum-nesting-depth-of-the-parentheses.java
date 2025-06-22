class Solution {
    public int maxDepth(String s) {
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('||s.charAt(i)==')'){
                stack.push(s.charAt(i));
            }

        }
        int max=0;
        int n=0;
        while(!stack.isEmpty()){
            if(stack.pop()==')'){
                n+=1;
                max=Math.max(n,max);
            }else{
                n-=1;
            }
        }
        System.out.println(max);
        return max;
    }

}