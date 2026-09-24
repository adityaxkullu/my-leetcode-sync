class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n) {
        if(i < 0 || i >= n || j < 0 || j >= n) return false;

        return true;
    }

    bool bfs(vector<vector<int>> &grid, int mid) {
        int n = grid.size();

        vector<vector<int>> visited(n, vector<int>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            if(row == n - 1 && col == n - 1) return true;

            for(int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if(valid(r, c, n) && visited[r][c] == false && mid >= grid[r][c]) {
                    q.push({r, c});
                    visited[r][c] = true;
                }

            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int low = grid[0][0];
        int high = n * n - 1;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(bfs(grid, mid)) {
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }

        return ans;
        
    }
};