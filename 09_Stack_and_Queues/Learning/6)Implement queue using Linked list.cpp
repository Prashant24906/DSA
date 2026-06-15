// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(){
        data = -1;
        next = nullptr;
    }
};
node* head = nullptr;
node* last = nullptr;
int top(){
    if(head == nullptr){
        cout<<"No element in queue"<<endl;
        return -1;
    }
    return head->data;
}
void push(int num){
   node* temp = new node();
   temp->data = num;
   if(head==nullptr){
       head = temp;
       last = temp;
       return ;
   }
   last->next = temp;
   last = temp;
}
void pop(){
    if(head==nullptr){
        cout<<"stack underflow\n";
        return ;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    if(head == nullptr)
        last = nullptr;
}
int size(){
    int cnt = 0;
    if(head == nullptr) return 0;
    node* mover = head;
    while(mover!=last->next){
        mover = mover->next;
        cnt++;
    }
    return cnt;
}
void printlist(){
    node* mover = head;
    if(head==nullptr){
        cout<<"Stack is empty\n";
        return ;
    }
    while(mover!=last->next){
        cout<<mover->data<<" ";
        mover = mover->next;
    }

}
int main() {
    push(2);
    push(4);
    push(5);
    push(6);
    cout<<top()<<endl;
    pop();
    cout<<top()<<endl;
    printlist();
    cout<<endl;
    cout<<top()<<endl;
    cout<<size();
    return 0;
}
