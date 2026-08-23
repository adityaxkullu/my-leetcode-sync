class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int n = a.size();
        int target = n - k + 1;
        priority_queue<int> pq;

        int i;
        for(int i = 0; i < target; i++) {
            pq.push(a[i]);
        }

        for(int i = target; i < n; i++) {
            if(a[i] >= pq.top()) continue;

            pq.pop();
            pq.push(a[i]);
        }

        return pq.top();
        
    }
};