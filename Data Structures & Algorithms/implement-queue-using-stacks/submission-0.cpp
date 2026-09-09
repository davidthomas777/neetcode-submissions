class MyQueue {
public:
    stack<int> st;
    stack<int> st2;

    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        // if stack2 is empty
        if (st2.empty()) {
            // while original stack is not empty
            while (!st.empty()) {
                // push to stack2 from stack1 top
                st2.push(st.top());
                // pop from stack 1
                st.pop();
            }
        }
        // if stack2 still has elements, pop from there
        int res = st2.top();
        st2.pop();
        return res;
    }
    
    int peek() {
        if (st2.empty()) {
            while (!st.empty()) {
                st2.push(st.top());
                st.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st2.empty() && st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */