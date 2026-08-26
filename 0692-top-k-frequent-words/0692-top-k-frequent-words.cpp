class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> m;
        
        // count frequency
        for(string str : words) {
            m[str]++;
        }

        // create bucket
        vector<vector<string>> bucket(n + 1);

        for(auto x : m) {
            bucket[x.second].push_back(x.first);
        }
        
        // sort every bucket lexicographically
        for(int f = 1; f <= n; f++) {
            sort(bucket[f].begin(), bucket[f].end());
        }

        vector<string> res;

        // traverse from highest frequency to smallest
        for(int i = n; i > 0; i--) {
            for(string x : bucket[i]) {
                res.push_back(x);

                if(res.size() == k) return res;
            }
        }

        return res;    
    }
};