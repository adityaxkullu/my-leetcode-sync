class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        unordered_map<int, int> m;
        int low = 0, high = 0, ans = INT_MIN;

        for(int high = 0; high < n; high++) {
            m[f[high]]++;

            while(m.size() > 2) {
                m[f[low]]--;

                if(m[f[low]] == 0) {
                    m.erase(f[low]);
                }

                low++;
            }

            ans = max(ans, high - low + 1);
        }

        return ans;
        
    }
};