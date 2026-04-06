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
  //O(n*m*log(n*m)) time | O(n*m) space
    Node* build(vector<int>& array){
        Node* ans = new Node(-1);
        Node* mover = ans;
        for(int i = 0;i<array.size();i++){
            Node* temp = new Node(array[i]);
            mover->bottom = temp;
            mover = mover->bottom;
        }
        return ans->bottom;
    }
    Node *flatten(Node *root) {
        vector<int> array;
        Node* vertical = root;
        Node* horizontal = root;
        while(horizontal){
            while(vertical){
                array.push_back(vertical->data);
                vertical = vertical->bottom;
            }
            horizontal = horizontal->next;
            vertical = horizontal;
        }
        sort(array.begin(),array.end());
        Node* ans = build(array);
        return ans;
    }
};
//O(n*m) time | O(1) space
class Solution{
    public:
        Node *flatten(Node *root){
            Node* mover = root;
            while(mover){
                
            }
        }
    }
