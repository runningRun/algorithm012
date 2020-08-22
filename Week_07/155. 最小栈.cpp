class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int x) {
        // cout << "push: " << x << endl;
        // 因为已经将minVal初始化为INT_MAX了，所以这里不需要判断dataStack是否为空
        if (x <= minVal) {
            dataStack.push(minVal);
            minVal = x;
        }
        dataStack.push(x);
    }
    
    void pop() {
        // cout << "pop top: " << dataStack.top() << endl;
        if (minVal == dataStack.top()) {
            dataStack.pop();
            minVal = dataStack.top();
        }
        dataStack.pop();
    }
    
    int top() {
        // cout << "top: " << dataStack.top() << endl;
        return dataStack.top();
    }
    
    int getMin() {
        // cout << "getMin: " << minVal << endl;
        return minVal;
    }

private:
    stack<int> dataStack;
    int minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */