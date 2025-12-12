class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int left=0;
        int right=people.size()-1;
        int count=0;
        while(left<=right){
            int sum=people[right]+people[left];
            if(sum<=limit){
                left++;
            }
            
            right--;
            count++;

            
        }
        return count;
    }
};