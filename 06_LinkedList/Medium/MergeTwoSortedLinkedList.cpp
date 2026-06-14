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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* mover = head;
        while (list1 != nullptr && list2 != nullptr) {
            if ((list1->val) < (list2->val)) {
                ListNode* temp = new ListNode(list1->val);
                mover->next = temp;
                mover = mover->next;
                list1 = list1->next;
            } 
            else {
                ListNode* temp = new ListNode(list2->val);
                mover->next = temp;
                mover = mover->next;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr) {
            ListNode* temp = new ListNode(list1->val);
            mover->next = temp;
            mover = mover->next;
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            ListNode* temp = new ListNode(list2->val);
            mover -> next = temp;
            mover = mover->next;
            list2 = list2->next;
        }
        return head->next;
    }
};
