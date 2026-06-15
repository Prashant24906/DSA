// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int arr[10] = {0};
int first = -1;
int last = -1;
int queuesize = 0;
int top(){
    if(first == -1){
        cout<<"No element in queue"<<endl;
        return -1;
    }
    return arr[first];
}
void push(int num){
    if(queuesize==10){
        cout<<"queue overflow!!"<<endl;
        return ;
    }
    queuesize++;
    if(first==-1)
        first = 0;
    last = (last+1)%10;
    arr[last] = num;
}
int pop(){
    if(queuesize == 0){
        cout<<"queue underflow!!\n";
        return -1;
    }
    queuesize--;
    int temp = arr[first];
    first = (first+1)%10;
    if(queuesize==0){
        first = -1;
        last = -1;
    }
    return temp;
}
void Size(){
    cout<<queuesize<<endl;
}
int main() {
    push(2);
    cout<<top()<<endl;
    pop();
    cout<<top()<<endl;
    cout<<top()<<endl;
    Size();
    return 0;
}
