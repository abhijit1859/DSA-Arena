class Solution {
    public List<String> generateParenthesis(int n) {
        ArrayList<String> list = new ArrayList<>();
        gen("",n,n,list);
        return list;
    }
   
    private static void gen(String p,int open,int close,ArrayList<String> list){
        if (open == 0 && close == 0) {
            System.out.println(p);
            list.add(p);
            return;
        }
        if(open>0){
             gen(p+'(',open-1,close,list);
        }
       
        if (close > open) {
            gen(p + ')', open, close - 1,list);
        }
    }
}
