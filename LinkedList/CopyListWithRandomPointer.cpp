#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* random;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};
int main()

{
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