class Solution {
    public String removeOccurrences(String s, String part) {
        if (!s.contains(part)) {
    return s;
}
         
        int index = s.indexOf(part);
        if(index!=-1){
            return removeOccurrences(s.substring(0, index) + s.substring(index + part.length()),part);
        }else{
            return s;
        }

        
    }
}
