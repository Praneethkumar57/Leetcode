class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1 = len(nums1)
        n2 = len(nums2)
        arr3 = []
        i =0
        j =0
        while(i<n1 and j<n2):
            if(nums1[i]<=nums2[j]):
                arr3.append(nums1[i])
                i = i+1
            else:
                arr3.append(nums2[j])
                j = j+1
        while(i<n1):
            arr3.append(nums1[i])
            i = i+1
        while(j<n2):
            arr3.append(nums2[j])
            j = j+1
        n = n1 + n2
        if(n % 2 ==1):
            return(arr3[n//2])
        else:
            mid = n//2
            return((arr3[mid]+arr3[mid-1])/2)