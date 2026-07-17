class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int i = 0, j = i + 1;
        int res = 1;

        while(j < n) {
            if(a[j] == a[i]) {
                j++;
                continue;
            }

            a[i + 1] = a[j];
            i++;
            j++;
            res++;
        }

        return res;
        
    }
};