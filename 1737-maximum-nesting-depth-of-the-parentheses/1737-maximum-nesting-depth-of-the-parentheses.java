class Solution {
    public int maxDepth(String s) {
        Stack<Character> stack = new Stack<>();
        int current=0;
        int max=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                stack.push('(');
                current++;
                max=Math.max(current,max);

            }else if(s.charAt(i)==')'){
                stack.push(')');
                current--;
                max=Math.max(current,max);
            }
            if(s.charAt(i)=='('||s.charAt(i)==')'){
                stack.push(s.charAt(i));
            }

        }
        
        System.out.println(max);
        return max;
    }

}