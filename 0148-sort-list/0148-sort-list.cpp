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
    ListNode* sortList(ListNode* head) {
        vector<int> cont;
        ListNode* temp=head;
        while(temp!=nullptr){
            cont.push_back(temp->val);
            temp=temp->next;
        }

        temp=head;
        sort(cont.begin(),cont.end());
        for(int i=0;i<cont.size();i++){
            temp->val=cont[i];
            temp=temp->next;
        }
       
        return head;
        
    }
};