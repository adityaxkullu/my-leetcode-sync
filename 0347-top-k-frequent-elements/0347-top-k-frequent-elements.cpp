class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int x : nums) {
            freq[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto i : freq) {
            pair<int, int> curr = {i.second, i.first};

            if(pq.size() < k){
                pq.push(curr);
                continue;
            }

            if(curr.first < pq.top().first) {
                continue;
            }else {
                pq.pop();
                pq.push(curr);
            }    
        }

        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
        
    }
};