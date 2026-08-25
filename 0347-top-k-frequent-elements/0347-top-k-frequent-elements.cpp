class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
       int n = a.size();

       // count frequency
       unordered_map<int, int> freq;

       for(int x : a) {
        freq[x]++;
       }
       
       // create bucket;
       vector<vector<int>> bucket(n + 1);

       for(auto i : freq) {
        int element = i.first;
        int frequency = i.second;

        bucket[frequency].push_back(element);
       }

       // traverse the bucket array
       vector<int> res;

       for(int frequency = n; frequency >= 1; frequency--) {
        for(int element : bucket[frequency]) {
            res.push_back(element);

            if(res.size() == k) return res;
        }
       }

       return res;

        
    }
};