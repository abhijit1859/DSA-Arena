
class Solution {
    public boolean buddyStrings(String s, String goal) {

        if(s.length()!=goal.length())return false;

        if(s.equals(goal)){
            return checkFreq(s);
        }   

        ArrayList<Integer> list=new ArrayList<>();

        for(int i=0;i<s.length();i++){

            if(s.charAt(i)!=goal.charAt(i)){
                list.add(i);
            }
        }

        // System.out.println(list.size());
        if(list.size()!=2)return false;

        String swapped = swap(list.get(0),list.get(1),s);
        // System.out.println(swapped);

        if(swapped.equals(goal))return true;

        return false;
    }


    private String swap(int i,int j,String s){
        
        char arr[]=s.toCharArray();

        char temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        StringBuilder sb=new StringBuilder();
        for(int idx=0;idx<arr.length;idx++){
            sb.append(arr[idx]);
        }

        return sb.toString();

    }


    private boolean checkFreq(String s){

        int freq[]=new int[26];

        for(char ch:s.toCharArray()){
            freq[ch-'a']++;

            if(freq[ch-'a']>1){
                return true;
            }
        }
        return false;
    }
}