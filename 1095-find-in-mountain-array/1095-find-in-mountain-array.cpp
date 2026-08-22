/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr) {

        int n = mountainArr.length();

        int low = 0;
        int high = n - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }

    int binarySearchIncreasing(MountainArray &mountainArr,
                               int low, int high, int target) {

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            if (value < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int binarySearchDecreasing(MountainArray &mountainArr,
                               int low, int high, int target) {

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            // Decreasing order
            if (value > target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    } 



    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // 1. Find peak
        int peak = findPeak(mountainArr);

        // 2. Search increasing part
        int left = binarySearchIncreasing(
            mountainArr, 0, peak, target
        );

        if (left != -1)
            return left;

        // 3. Search decreasing part
        int right = binarySearchDecreasing(
            mountainArr, peak + 1, n - 1, target
        );

        return right;
        
        
    }
};