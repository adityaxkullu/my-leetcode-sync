class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n) {
        if(i < 0 || i >= n || j < 0 || j >= n) return false;

        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> res(n, vector<int>(n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});
        res[0][0] = grid[0][0];

        while(!pq.empty()) {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();

            int time = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(time > res[row][col]) continue;
            if(row == n - 1 && col == n - 1) return time;

            for(int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if(valid(r, c, n)) {
                    int newTime = max(time, grid[r][c]);

                    if(newTime < res[r][c]) {
                        res[r][c] = newTime;
                        pq.push({newTime, {r, c}});
                    }
                }
            }    
        }

        return -1;    
    }
};