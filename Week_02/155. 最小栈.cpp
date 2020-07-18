class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m_valueStack.push(x);
        if (m_minValueStack.empty()) {
            m_minValueStack.push(x);
        } else {
            int minValue = m_minValueStack.top();
            if (x < minValue) {
                m_minValueStack.push(x);
            } else {
                m_minValueStack.push(minValue);
            }
        }
    }
    
    void pop() {
        if (!m_valueStack.empty()) {
            m_valueStack.pop();
            m_minValueStack.pop();
        }
    }
    
    int top() {
        return m_valueStack.top();
    }
    
    int getMin() {
        return m_minValueStack.top();
    }

private:
    stack<int> m_minValueStack;
    stack<int> m_valueStack;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */