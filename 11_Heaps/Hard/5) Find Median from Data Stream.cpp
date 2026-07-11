class MedianFinder {
public:
    priority_queue<int> first;
    priority_queue<int,vector<int>,greater<int>> second;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first.empty()){
            first.push(num);
            return ;
        }
        if(second.empty()){
            if(first.top()>num){
                second.push(first.top());
                first.pop();
                first.push(num);
            }
            else
                second.push(num);
            return ;
        }
        if(num<second.top())
            first.push(num);
        else{
            second.push(num);
        }
        if(second.size()<first.size()){
            second.push(first.top());
            first.pop();
        }
        if((second.size()-first.size())>1){
            first.push(second.top());
            second.pop();
        }
    }
    
    double findMedian() {
        if(second.empty()) return first.top();
        if(first.size()==second.size()){
            double ans = ((double)first.top()+(double)second.top())/2;
            return ans;
        }
        return second.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
