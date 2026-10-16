class StockSpanner {
public:
    vector<int> prices;
    stack<int> indices;

    StockSpanner() {
    }

    int next(int price) {
        prices.push_back(price);
        int i = prices.size() - 1;

        while (!indices.empty() &&
               prices[indices.top()] <= price) {
            indices.pop();
        }

        int span;

        if (indices.empty()) {
            span = i + 1;
        } else {
            span = i - indices.top();
        }

        indices.push(i);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */