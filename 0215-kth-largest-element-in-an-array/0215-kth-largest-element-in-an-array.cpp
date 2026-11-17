class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x:nums) {pq.push(x);};
        int top=0;
        while(k>0){
            top=pq.top();
            pq.pop();
            k--;
        }
        return top;
    }
};