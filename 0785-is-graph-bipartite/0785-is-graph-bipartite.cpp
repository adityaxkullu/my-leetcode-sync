class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>> &graph, int node, int c, vector<int> &color) {
        color[node] = c;

        for(int j = 0; j < graph[node].size(); j++) {
            int neigh = graph[node][j];

            if(color[neigh] != -1 && color[neigh] == c) res = false;
            if(color[neigh] == -1) {
                dfs(graph, neigh, 1 - c, color);
            }
        }

        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                dfs(graph, i, 0, color);
            }
        }

        return res;
        
    }
};