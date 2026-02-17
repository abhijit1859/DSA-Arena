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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        int size=0;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        int pos=size/2;
        cout<<pos<<endl;
        cout<<size;
        temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=del->next;
         
        delete del;

        return head;
    }
};