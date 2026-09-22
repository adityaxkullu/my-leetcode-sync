class Solution {
public:
    bool ans = true;

    void dfs(vector<vector<int>> &adj, int node, int c, vector<int> &color) {
        color[node] = c;

        for(int j = 0; j < adj[node].size(); j++) {
            int neigh = adj[node][j];

            if(color[neigh] != -1 && color[neigh] == c) ans = false;
            if(color[neigh] == -1) {
                dfs(adj, neigh, 1 - c, color);
            }
        }

        return;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < dislikes.size(); i++) {
            int src = dislikes[i][0];
            int dest = dislikes[i][1];

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }

        vector<int> color(n + 1, -1);

        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                dfs(adj, i, 0, color);
            }
        }

        return ans;    
    }
};