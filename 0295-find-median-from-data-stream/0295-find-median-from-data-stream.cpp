class MedianFinder {
public:
    priority_queue<int>first;
    priority_queue<int,vector<int>,greater<int>>second;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first.empty() || first.top()>=num){
            first.push(num);
        }
        else
            second.push(num);
        
        while(first.size()>second.size()+1){
            second.push(first.top());
            first.pop();
        }
        while(second.size()>1+first.size()){
            first.push(second.top());
            second.pop();
        }
    }
    
    double findMedian() {
        if(first.size()==second.size()){
            return (first.top()+second.top())/2.0;
        }
        if(second.size() < first.size())
            return first.top();

        if(second.size() > first.size())
            return second.top();
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */