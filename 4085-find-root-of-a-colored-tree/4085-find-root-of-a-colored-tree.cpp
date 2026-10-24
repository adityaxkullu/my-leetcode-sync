class Solution {
public:
    char nextColor(char c) {
        if(c == 'R') return 'B';
        if(c == 'B') return 'W';
        return 'R';
    }

    int findColoredRoot(vector<vector<int>>& edges, string color) {
        int n = color.size();

        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if(color[u] == color[v]) return -1;

            if(nextColor(color[u]) == color[v]) {
                outdegree[u]++;
                indegree[v]++;
            }else {
                outdegree[v]++;
                indegree[u]++;
            }

            if(indegree[u] > 1 || indegree[v] > 1 || outdegree[u] > 2 || outdegree[v] > 2) return -1;
        }

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) return i;
        }

        return -1;    
    }
};