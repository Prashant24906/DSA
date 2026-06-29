// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

class minTomax{
    public: 
  void heapify(vector<int>& heap,int i){
     int n = heap.size();
     
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if(left<n && heap[largest]<heap[left]){
      largest = left;
    }
    if(right<n&&heap[largest]<heap[right]){
      largest = right;
    }
    if(largest!=i){
      swap(heap[largest],heap[i]);
      heapify(heap,largest);
    }
  }
  void minheap(vector<int>& heap){
    //For 0 based indexing
    int n = heap.size();
    for (int i = (n - 2) / 2; i >= 0; --i){
      heapify(heap,i);
    }
  }
};

int main() {
    minTomax m;
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    m.minheap(arr);
    for(auto it: arr) cout<<it<<" ";
    return 0;
}
