#include<iostream>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // O(N) time and space complexity
    Node* copyRandomList(Node* head) {
    Node* curr = head;
        unordered_map<Node* ,Node* > old_to_new;
        while(curr){
            old_to_new[curr] = new Node(curr->val);
            curr = curr ->next;
        }
        curr = head;
        while(curr){
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }
        return old_to_new[head];
    }
};

class Solution {
public:
    // O(N) time and O(1) space complexity
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* mover = head;
        while(mover){
            Node* temp = new Node(mover->val);
            temp->next = mover->next;
            mover->next = temp;
            mover = temp->next;
        }
        //assign random 
        mover = head;
        while(mover){
            if(mover->random)
                mover->next->random = mover->random->next;
            mover = mover->next->next;
        }
        Node* newHead = head->next;
        mover = head;
        Node* mover2 = newHead;
        while(mover&&mover2){
            mover->next = mover->next->next;
            if(mover2->next)
                mover2->next = mover2->next->next;
            mover = mover->next;
            mover2 = mover2->next;
        }
        return newHead;
        
    }
};
