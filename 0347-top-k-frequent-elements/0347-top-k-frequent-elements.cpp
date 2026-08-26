class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int, int> freq;

        for(int i : a) {
            freq[i]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto i : freq) {
            pq.push({i.second, i.first});
        }
        
        vector<int> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    
    }
};