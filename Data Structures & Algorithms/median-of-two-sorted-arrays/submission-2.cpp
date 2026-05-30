class Solution {
public:
    int findKthSmall(vector<int>& nums1, vector<int>& nums2, int k){
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;

        while(true){
            if(i == m){
                return nums2[j + k - 1];
            }

            if(j == n){
                return nums1[i + k - 1];
            }

            if(k == 1){
                return min(nums1[i], nums2[j]);
            }

            int half = k / 2;
            
            int newI = min(i + half, m) - 1;
            int newJ = min(j + half, n) - 1;

            int pivot1 = nums1[newI];
            int pivot2 = nums2[newJ];

            if(pivot1 <= pivot2){
                int removed = newI - i + 1;
                i = newI + 1;
                k -= removed;
            }else{
                int removed = newJ - j + 1;
                j = newJ + 1;
                k -= removed;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if(total % 2 == 1){
            return (double)findKthSmall(nums1, nums2, total / 2 + 1);
        }else{
            int a = findKthSmall(nums1, nums2, total / 2);
            int b = findKthSmall(nums1, nums2, total / 2 + 1);
            return ((double)a + b) / 2.0 ;
        }

    }
};
