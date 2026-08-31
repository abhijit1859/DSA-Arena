/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index=1;
        int firstC=-1;
        int lastC=-1;

        int minDistance=INT_MAX;

        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr->next!=nullptr){
            if((curr->val>prev->val&&curr->val>curr->next->val)||(curr->val<prev->val&&curr->val<curr->next->val)){
                if(firstC==-1){
                    firstC=index;
                }else{
                    minDistance=min(minDistance,index-lastC);
                }
                lastC=index;
            }
            prev=curr;
            curr=curr->next;
            index++;
        }

        if(firstC==lastC){
            return {-1,-1};
        }

        return {minDistance,lastC-firstC};
    }
};