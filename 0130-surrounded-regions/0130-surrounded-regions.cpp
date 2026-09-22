class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool valid(int m, int n, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) return false;

        return true;
    }

    void dfs(vector<vector<char>> &adj, int m, int n, int i, int j) {
        adj[i][j] = '#';

        for(int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if(valid(m, n, row, col) && adj[row][col] == 'O') {
                dfs(adj, m, n, row, col);
            }
        }

        return;
    }

    void solve(vector<vector<char>>& adj) {
        int m = adj.size();
        int n = adj[0].size();

        int i, j;

        for(int j = 0; j < n; j++) {
            if(adj[0][j] == 'O') {
                dfs(adj, m, n, 0, j);
            }

            if(adj[m - 1][j] == 'O') {
                dfs(adj, m, n, m - 1, j);
            }
        }

        for(int i = 0; i < m; i++) {
            if(adj[i][0] == 'O') {
                dfs(adj, m, n, i, 0);
            }

            if(adj[i][n - 1] == 'O') {
                dfs(adj, m, n, i, n - 1);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][j] == '#') adj[i][j] = 'O';
                else adj[i][j] = 'X';
            }
        }

        return;    
    }
};