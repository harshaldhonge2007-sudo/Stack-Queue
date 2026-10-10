
class MinStack {
public:
    stack<long long> st;
    long long minVal = INT_MAX;

    MinStack() {
    }

    void push(int value) {
        if (st.empty()) {
            minVal = value;
            st.push(value);
        } 
        else {
            if (value >= minVal) {
                st.push(value);
            } 
            else {
                st.push(2LL * value - minVal);
                minVal = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long n = st.top();
        st.pop();

        if (n < minVal) {
            minVal = 2 * minVal - n;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long n = st.top();

        if (n < minVal) {
            return (int)minVal;
        }

        return (int)n;
    }

    int getMin() {
        return (int)minVal;
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