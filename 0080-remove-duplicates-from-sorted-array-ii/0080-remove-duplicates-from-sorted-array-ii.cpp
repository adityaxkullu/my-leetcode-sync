class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();

        if(n <= 2) return n;

        int i = 0;

        for(int j = i + 2; j < n; j++) {
            if(a[j] != a[i]) {
                a[i + 2] = a[j];
                i++;
            }
        }

        return i + 2;
        
    }
};