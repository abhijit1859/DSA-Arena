class Solution {
    public boolean judgeSquareSum(int c) {
        
 int[] arr = new int[2];
int num = (int)Math.sqrt(c);

int left = 0;
int right = num;

while (left <= right) {
    long sum = 1L * left * left + 1L * right * right; // use long multiplication
    if (sum == c) {
        arr[0] = left;
        arr[1] = right;
        return true;
    } else if (sum > c) {
        right--;
    } else {
        left++;
    }
}
        return false;
    }
}