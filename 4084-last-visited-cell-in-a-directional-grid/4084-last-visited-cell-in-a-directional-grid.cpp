class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> arr = {0, 0};

        unordered_map<int, unordered_map<int, bool>> mp;
        mp[0][0] = true;

        while (true) {
            int r = arr[0];
            int c = arr[1];

            int nr = r, nc = c;

            if (grid[r][c] == 'L') nc--;
            else if (grid[r][c] == 'R') nc++;
            else if (grid[r][c] == 'U') nr--;
            else if (grid[r][c] == 'D') nr++;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                return arr;

            if (mp[nr][nc])
                return arr;

            mp[nr][nc] = true;
            arr = {nr, nc};
        }
    }
};