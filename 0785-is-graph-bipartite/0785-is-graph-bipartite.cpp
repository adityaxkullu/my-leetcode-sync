class Solution {
public:
    bool res = true;
    void bfs(vector<vector<int>> &graph, int node, int c, vector<int> &color) {
        queue<int> q;

        q.push(node);
        color[node] = c;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int j = 0; j < graph[curr].size(); j++) {
                int neigh = graph[curr][j];

                if(color[neigh] != -1 && color[neigh] == color[curr]) {
                    res = false;
                }

                if(color[neigh] == -1) {
                    color[neigh] = 1 - color[curr];
                    q.push(neigh);
                }
            }
        }

        return;    
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                bfs(graph, i, 0, color);
            }
        }

        return res;
        
    }
};