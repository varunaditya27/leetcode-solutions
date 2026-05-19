class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int idx1 = 0;
        int idx2 = 0;

        while (idx1 < len1 && idx2 < len2) {
            if (nums1[idx1] == nums2[idx2]) {
                return nums1[idx1];
            }

            else if (nums1[idx1] > nums2[idx2]) {
                idx2++;
            }

            else {
                idx1++;
            }
        }

        return -1;
    }
};
