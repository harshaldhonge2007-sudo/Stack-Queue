
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int right = n - 1;
        int MaxArea = 0;

        while (left < right) {
            int width = right - left;
            int tall = min(height[left], height[right]);
            int area = tall * width;
            MaxArea = max(MaxArea, area);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return MaxArea;
    }
};
