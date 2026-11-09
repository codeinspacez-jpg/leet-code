#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto binarySearch = [&](bool isSearchingLeft) {
            int left = 0, right = nums.size() - 1;
            int idx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                if (nums[mid] > target) {
                    right = mid - 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    idx = mid;
                    if (isSearchingLeft) {
                        right = mid - 1; // Look in the left half
                    } else {
                        left = mid + 1;  // Look in the right half
                    }
                }
            }
            return idx;
        };
        
        return {binarySearch(true), binarySearch(false)};
    }
};