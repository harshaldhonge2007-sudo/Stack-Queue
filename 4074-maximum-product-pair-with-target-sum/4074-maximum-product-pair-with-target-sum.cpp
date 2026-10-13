
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int maxP = INT_MIN;
        vector<int> ans = {-1, -1};

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target &&
                    nums[i] > nums[j]) {

                    int product = nums[i] * nums[j];

                    if (product > maxP) {
                        maxP = product;
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
        }

        return ans;
    }
};
