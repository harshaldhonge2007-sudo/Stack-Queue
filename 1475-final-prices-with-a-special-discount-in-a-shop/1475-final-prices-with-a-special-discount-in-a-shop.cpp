
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for (int i = prices.size() - 1; i >= 0; i--) {
            int price = prices[i];

            while (!st.empty() && prices[i] < st.top()) {
                st.pop();
            }

            if (!st.empty()) {
                prices[i] -= st.top();
            }

            st.push(price);
        }

        return prices;
    }
};
