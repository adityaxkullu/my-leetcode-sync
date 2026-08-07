class MinStack {
public:
    stack<long long> s;
    long long minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minVal = val;
            return;
        }

        if(val < minVal) {
            long long newVal = 1ll * 2 * val - minVal;
            s.push(newVal);
            minVal = val;
        }else {
            s.push(val);
        }
        
    }
    
    void pop() {
        if(s.top() < minVal) {
            minVal = 2 * minVal - s.top();
        }
        s.pop();     
    }
    
    int top() {
        if(s.top() < minVal) {
            return minVal;
        }
        return s.top(); 
    }
    
    int getMin() {
        return minVal;  
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */