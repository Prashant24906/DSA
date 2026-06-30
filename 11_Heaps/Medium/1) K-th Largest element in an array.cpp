class Solution {
public:
void minheap(vector<int>& heap,int i){
    int n = heap.size();
    int left = 2 * i ;
    int right = 2 * i + 1;
    int smaller = i;
    if(left<n && heap[i]>heap[left]){
      smaller = left;
    }
    if(right<n&&heap[smaller]>heap[right]){
      smaller = right;
    }
    if(smaller!=i){
      swap(heap[smaller],heap[i]);
      minheap(heap,smaller);
    }
  }
    void heapify(vector<int>& heap,int heapsize) {
        int index = heapsize;
        while(index>1){
            int parent = index/2;
            if(heap[index]<heap[parent]){
                swap(heap[index],heap[parent]);
                index = parent;
            }
            else return ;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> heap;
        heap.push_back(-1);
        for (int i = 0; i < k; i++) {
            int heapsize = heap.size();
            heap.push_back(nums[i]);
            heapify(heap, heapsize);
        }
        for (int i = k; i < n; i++) {
            if (heap[1] < nums[i]) {
                heap[1] = nums[i];
                minheap(heap, 1);
            }
        }
        return heap[1];
    }
};
