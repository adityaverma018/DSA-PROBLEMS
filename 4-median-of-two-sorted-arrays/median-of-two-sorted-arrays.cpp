#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2; 
        
        int lo = 0, hi = m;
        
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; 
            int j = half - i;           
            
           
            int nums1Left  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int nums1Right = (i < m) ? nums1[i]     : INT_MAX;
            int nums2Left  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int nums2Right = (j < n) ? nums2[j]     : INT_MAX;
            
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                
                if (total % 2 == 1) {
                    return static_cast<double>(max(nums1Left, nums2Left));
                } else {
                    return (max(nums1Left, nums2Left) + 
                            min(nums1Right, nums2Right)) / 2.0;
                }
            } else if (nums1Left > nums2Right) {
                hi = i - 1;   
            } else {
                lo = i + 1;   
            }
        }
        
        throw invalid_argument("Input arrays are not sorted properly");
    }
};