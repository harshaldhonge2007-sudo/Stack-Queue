class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i = 0, j = 0;
        int r = 0, c = 0;

        while (i < n && j < m && i >= 0 && j >= 0) {

            if (grid[i][j] == '0') {
                return {r, c};
            }

            r = i;
            c = j;

            if (grid[i][j] == 'R') {
                j++;
            }
            else if (grid[i][j] == 'L') {
                j--;
            }
            else if (grid[i][j] == 'U') {
                i--;
            }
            else {
                i++;
            }

            grid[r][c] = '0';
        }

        return {r, c};
    }
};