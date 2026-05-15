// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int arr[10] = {0};
int t = -1;
int top(){
    if(t == -1){
        cout<<"No element in stack"<<endl;
        return -1;
    }
    return arr[t];
}
void push(int num){
    if(t==9){
        cout<<"Stack overflow!!"<<endl;
        return ;
    }
    t++;
    arr[t] = num;
}
void pop(){
    if(t == -1){
        cout<<"Stack underflow!!\n";
        return ;
    }
    t--;
}
void size(){
    cout<<t+1<<endl;
    
}
int main() {
    pop();
    cout<<top()<<endl;
    push(2);
    cout<<top()<<endl;
    cout<<top()<<endl;
    size();
    return 0;
}
