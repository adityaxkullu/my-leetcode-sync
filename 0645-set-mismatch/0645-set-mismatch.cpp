class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        int n = a.size();
        int duplicate, missing;

        for(int i = 0; i < n; i++) {
            int x = abs(a[i]);

            if(a[x - 1] < 0) {
                duplicate = x;
            }else {
                a[x - 1] = -a[x - 1];
            }
        }

        for(int i = 0; i < n; i++) {
            if(a[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};