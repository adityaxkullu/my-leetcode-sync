class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int low = 0, maxFreq = 0, res = 0;

        for(int high = 0; high < n; high++) {
            freq[s[high] - 'A']++;
            maxFreq = max(maxFreq, freq[s[high]-'A']);

            while((high - low + 1) - maxFreq > k) {
                freq[s[low] - 'A']--;
                low++;
            }

            res = max(res, high - low + 1);     
        }

        return res;

        
    }
};