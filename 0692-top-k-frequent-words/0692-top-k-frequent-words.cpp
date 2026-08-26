class Solution {
public:
    struct cmp{
        bool operator()(pair<int, string> &a, pair<int, string> &b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        } 
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for(string x : words) {
            freq[x]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for(auto i : freq) {
            pq.push({i.second, i.first});
        }

        vector<string> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
        
    }
};