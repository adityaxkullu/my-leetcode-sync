class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0, count = 0;
        while(i < n && j < m) {
            int p = a[i];
            int t = b[j];

            if(p <= t) {
                count++;
                i++;
                j++;
            }else {
                j++;
            }
        }

        return count;    
    }
};