class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        int st = 0, end = a.size() - 1;

        while(st < end) {
            int mid = st + (end - st)/2;
            int count = 0;

            for(int val : a) {
                if(val <= mid) {
                    count++;
                }
            }

            if(count > mid) {
                end = mid;
            } else {
                st = mid + 1;
            }
        }

        return st;    
    }
};