class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse(n), pse(n);
        vector<int> nge(n), pge(n);

        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if (st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            minSum += arr[i] * leftMin * rightMin;
            maxSum += arr[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};