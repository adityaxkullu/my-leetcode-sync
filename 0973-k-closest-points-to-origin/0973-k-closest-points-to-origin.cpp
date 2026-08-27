class Solution {
public:
    int findDist(vector<int>& p) {
        int d = p[0] * p[0] + p[1] * p[1];
        return d;
    }

    int partition(vector<vector<int>> &points, int low, int high) {
        int pivotDist = findDist(points[high]);
        
        int i = low;
        for(int j = low; j < high; j++) {
            if(findDist(points[j]) <= pivotDist) {
                swap(points[i], points[j]);
                i++;
            }
        }

        swap(points[i], points[high]);

        return i;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       int low = 0, high = points.size() - 1;

       while(low <= high) {
        int pivotIdx = partition(points, low, high);

        if(pivotIdx == k - 1) break;

        if(pivotIdx > k - 1) {
            high = pivotIdx - 1;
        }else {
            low = pivotIdx + 1;
        }

       }

       return vector<vector<int>>(points.begin(), points.begin() + k);
        
    }
};