class MinStack {
public:
    std::stack<int> s;
    std::stack<int> ms;

    MinStack() {
        // Constructor
    }
    
    void push(int val) {
        s.push(val);
        if (ms.empty() || ms.top() >= val) {
            ms.push(val);
        }
    }
    
    void pop() {
        int val = s.top();
        s.pop();
        if (val == ms.top()) {
            ms.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */