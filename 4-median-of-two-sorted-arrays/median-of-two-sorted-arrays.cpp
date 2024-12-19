class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = n1;
        int lft = (n1 + n2 + 1) / 2; // number of elements to the left of median
        int n = n1 + n2;
        while (l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = lft - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if (l1 > r2)
                r = mid1 - 1;
            else if (l2 > r1)
                l = mid1 + 1;
            else {
                if (n & 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }

        return 0;
    }
};