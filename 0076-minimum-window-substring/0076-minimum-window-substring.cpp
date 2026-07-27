class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for(int i = 0; i < t.length(); i++) {
            freq[t[i]]++;
        }
        int low = 0, start = 0, res = s.length() + 1;
        int count = t.length();

        for(int high = 0; high < s.length(); high++) {
            if(freq[s[high]] > 0) {
                count--;
            }
            freq[s[high]]--;

            while(count == 0) {
                int len = high - low + 1;

                if(res > len) {
                    res = len;
                    start = low;
                }

                freq[s[low]]++;

                if(freq[s[low]] > 0) {
                    count++;
                }

                low++;
               
            }

        }

        return (res == s.length() + 1) ? "" : s.substr(start, res);


    }
};