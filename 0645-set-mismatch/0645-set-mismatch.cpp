class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        int n = a.size();
        vector<int> freq(n + 1, 0);

        for(int i : a) {
            freq[i]++;
        }

        int duplicate, missing;

        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2) duplicate = i;
            if(freq[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};