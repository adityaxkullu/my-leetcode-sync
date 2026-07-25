class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int low = 0, res = 0;
        unordered_map<int, int> m;

        for(int high = 0; high < n; high++) {
            m[s[high]]++;
            int k = high - low + 1;

            while(m.size() < k) {
                m[s[low]]--;

                if(m[s[low]] == 0) {
                    m.erase(s[low]);
                }

                low++;
                k = high - low + 1;
            }

            res = max(res, k);
        }

        return res;
        
    }
};