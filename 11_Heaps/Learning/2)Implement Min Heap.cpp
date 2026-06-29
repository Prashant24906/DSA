class minHeap {
  private:


  public:
    vector<int> heap = {-1};
    int heapsize = 0;
    int small(int leftindex,int rightindex){
        if(rightindex>heapsize) return leftindex;
        return heap[leftindex]>heap[rightindex]?rightindex:leftindex;
    }
    void push(int x) {
        heap.push_back(x);
        heapsize++;
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

    void pop() {
        if(heapsize == 0) return ;
        swap(heap[1],heap[heapsize]);
        heap.pop_back();
        heapsize--;
        int index = 1;
        while(index*2<=heapsize){
            int leftindex = index*2;
            int rightindex = index*2 + 1;
            int smaller = small(leftindex,rightindex);
            if(heap[smaller]<heap[index]){
            swap(heap[index],heap[smaller]);
            index = smaller;
            }
            else return ;
        }
    }

    int peek() {
        if(heapsize == 0) return -1;
        else return heap[1];
    }

    int size() {
        return heapsize;
    }
};
