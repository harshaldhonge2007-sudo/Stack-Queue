
class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n % 2 != 0) {
            return false;
        }

        int a = 0;
        int b = 1;
        int c = a + b;

        while (c <= n / 2) {
            if (a + b + c == n) {
                return true;
            }

            a = b;
            b = c;
            c = a + b;
        }

        return false;
    }
};
