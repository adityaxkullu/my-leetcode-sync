class Solution {
public:
    int findDist(vector<int>& p) {
        int d = p[0] * p[0] + p[1] * p[1];
        return d;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < points.size(); i++) {
            int dist = findDist(points[i]);

            pq.push({dist, i});
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while(k--) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
        
        
    }
};