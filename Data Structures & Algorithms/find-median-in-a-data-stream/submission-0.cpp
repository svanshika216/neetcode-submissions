class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder() {}

    int signum(int a, int b){
        if(a==b) {
            return 0;
        }
        else if(a>b) {
            return 1;
        }
        else {
            return -1;
        }
    }
    
    void addNum(int num) {
        switch(signum(left.size(), right.size())){
            case 0: if(left.empty() || num <= left.top()){
                left.push(num);
            }
            else{
                right.push(num);
            }
            break;

            case 1: if(num >= left.top()){
                right.push(num);
            }
            else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            break;

            case -1: if(num <= right.top()){
                left.push(num);
            }
            else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            break;
        }
    }
    
    double findMedian() {
        switch(signum(left.size(), right.size())){
            case 0: 
                return (left.top() + right.top())/2.0;
            case 1: 
                return left.top();
            case -1: 
                return right.top();
        }
        return 0;
    }
};
