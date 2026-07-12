class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int left = intervals[0][0];
        int right = intervals[0][1];

        for(int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start <= right) {
                right = max(end, right);
            } else {
                ans.push_back({left,right});

                left = start;
                right = end;
            }
        }
        ans.push_back({left, right});

        return ans;
    }
};