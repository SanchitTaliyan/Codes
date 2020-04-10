#include<iostream>
#include<stack>

using namespace std;
class MinStack {
    stack<int> s;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        
        if(min.empty()) {
            min.push(x);
        }
        else {
            if(min.top() >= x) {
                min.push(x);
            }
        }
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        
        if(top == min.top()) {
            min.pop();
        }
    }
    
    int top() {
        if(s.empty()) return INT_MAX;
        return s.top();
    }
    
    int getMin() {
        if(min.empty()) {
            //std::cout << "Stack underflow!! ";
			return -1;
        }
        
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */