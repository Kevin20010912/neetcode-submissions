class MedianFinder {
    int size;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(max_heap.size() < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(size % 2){
            return (double)max_heap.top(); 
        }else{
            return ((double)max_heap.top() + min_heap.top()) / 2;
        }
    }
};
