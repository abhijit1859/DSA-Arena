/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *listA=headA;
        ListNode *listB=headB;
        while(listA!=listB){
            listA=(listA!=nullptr)?listA->next:headB;
            listB=(listB!=nullptr)?listB->next:headA;

        }
        return listA;
    }
};