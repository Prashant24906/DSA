// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int arr[10] = {0};
int first = -1;
int last = -1;
int top(){
    if(first == -1){
        cout<<"No element in queue"<<endl;
        return -1;
    }
    return arr[first];
}
void push(int num){
    if(last==9){
        cout<<"queue overflow!!"<<endl;
        return ;
    }
    if(first==-1)
        first = 0;
    last++;
    arr[last] = num;
}
int pop(){
    if(first == -1){
        cout<<"queue underflow!!\n";
        return -1;
    }
    int temp = arr[first++];
    if(first>last){
        first = -1;
        last = -1;
    }
    return temp;
}
void size(){
    cout<<last-first+1<<endl;
}
int main() {
    push(2);
    cout<<top()<<endl;
    pop();
    cout<<top()<<endl;
    cout<<top()<<endl;
    size();
    return 0;
}
