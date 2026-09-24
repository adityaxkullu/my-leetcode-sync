class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }

    bool bfs(vector<vector<int>> &heights, int limit) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            if(row == n - 1 && col == m - 1) return true;

            for(int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if(valid(r, c, n, m) && visited[r][c] == false) {
                    int diff = abs(heights[row][col] - heights[r][c]);

                    if(diff <= limit) {
                        visited[r][c] = true;
                        q.push({r, c});
                    }
                }
            }
        }

        return false;

    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int low = 0;
        int high = 1000000;

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(bfs(heights, mid)) {
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return ans;

    }
};