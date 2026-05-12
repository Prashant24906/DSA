/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
        Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* head = new Node(-1);
        Node* mover = head;
        while (list1 != nullptr && list2 != nullptr) {
            if ((list1->data) < (list2->data)) {
                Node* temp = new Node(list1->data);
                mover->bottom = temp;
                mover = mover->bottom;
                list1 = list1->bottom;
            } 
            else {
                Node* temp = new Node(list2->data);
                mover->bottom = temp;
                mover = mover->bottom;
                list2 = list2->bottom;
            }
        }
        while (list1 != nullptr) {
            Node* temp = new Node(list1->data);
            mover->bottom = temp;
            mover = mover->bottom;
            list1 = list1->bottom;
        }
        while (list2 != nullptr) {
            Node* temp = new Node(list2->data);
            mover->bottom = temp;
            mover = mover->bottom;
            list2 = list2->bottom;
        }
        return head->bottom;
    }
    Node *flatten(Node *root) {
        Node* head1 = root;
        Node* head2 = root->next;
        while(head2){
            head1 = mergeTwoLists(head1,head2);
            head2 = head2->next;
        }
        return head1;
    }
};