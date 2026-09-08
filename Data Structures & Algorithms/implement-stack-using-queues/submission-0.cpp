class MyStack {
public:
    std::queue<int> q;
    MyStack() {}
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        // iterate through size
        for (int i = 0; i < size; i++) {
            // push element that is first in FIFO order to the back
            q.push(q.front());
            // pop first in line from front. so now the first in the line is at the back
            q.pop();
        }
    }
    
    int pop() {
        if (!q.empty()) {
            int res = q.front();
            q.pop();
            return res;
        }
        return -1;
    }
    
    int top() {
        return q.empty() ? -1 : q.front();
    }
    
    bool empty() {
        return q.empty() ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */