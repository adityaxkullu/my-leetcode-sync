class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();

        if(n <= 2) {
            return n;
        }

        int i = 0, j = i + 2, res = 2;

        while(j < n) {
            if(a[j] == a[i]) {
                j++;
                continue;
            }

            a[i + 2] = a[j];
            i++;
            j++;
            res++;
        }

        return res;    
    }
};