class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto x : freq) {
            pq.push({x.second, x.first});
        }

        string res;
        while(pq.size() >= 2) {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            res += first.second;
            res += second.second;

            first.first--;
            second.first--;

            if(first.first > 0) pq.push(first);
            if(second.first > 0) pq.push(second);

        }

        if(!pq.empty()) {
            auto last = pq.top();

            if(last.first > 1) return "";

            res += last.second;
        }

        return res;

    }
};