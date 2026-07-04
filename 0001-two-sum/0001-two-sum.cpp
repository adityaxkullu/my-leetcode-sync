class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({a[i], i});
        }

        sort(arr.begin(), arr.end());

        int st = 0, end = n - 1;

        while(st < end) {
            if(arr[st].first + arr[end].first == target) {
                return {arr[st].second, arr[end].second};
            } else if(arr[st].first + arr[end].first > target) {
                end--;
            } else {
                st++;
            }
        }

        return {};


       
        
    }
};