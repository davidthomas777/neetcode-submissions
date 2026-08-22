#include <algorithm>
#include <stack>
class MinStack {
public:
    // main stack for tracking values LIFO order
    std::stack<int> main_stack;
    // min_stack which keeps the minimum element on the top
    std::stack<int> min_stack;
    
    void push(int val) {
        // append main stack
        main_stack.push(val);
        // if min stack is empty, or the value is less then the current top, append to 
        // min stack
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        // if the min stack is the same as the main, pop the top
        if (main_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        // pop main regardless
        main_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
