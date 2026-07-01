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
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<ListNode* ,vector<ListNode*>,Compare> pq;
        ListNode* head = new ListNode(-1);
        ListNode* mover = head;
        for(int i = 0;i<lists.size();i++){
            ListNode* temp = lists[i];
            if(temp!=nullptr)
                pq.push(temp);
        }
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            mover->next = temp;
            mover = mover->next;
            temp = temp->next;
            if(temp!=nullptr) pq.push(temp);
            mover->next = nullptr;
        }
        return head->next;
    }
};
