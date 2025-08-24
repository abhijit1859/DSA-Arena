class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int srow=0,scol=0,erow=matrix.length-1,ecol=matrix[0].length-1;
        while(srow<=erow&&scol<=ecol){
            //top
            for(int i=scol;i<=ecol;i++){
                list.add(matrix[srow][i]);
            }
            //right
            for(int i=srow+1;i<=erow;i++){
                list.add(matrix[i][ecol]);
            }
            //bottom
            for(int i=ecol-1;i>=scol;i--){
                if(srow==erow){
                    break;
                }
                list.add(matrix[erow][i]);
            }
            //left
            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol){
                    break;
                }
                list.add(matrix[i][scol]);
            }
            srow++;scol++;erow--;ecol--;
        }
        System.out.println(list);
        return list;
    }
}