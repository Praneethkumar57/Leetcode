class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        nums = [[]]
        i = 0
        j = 0
        while(i<len(nums1) and j<len(nums2)):
            val1 = nums1[i][0]
            val2 = nums2[j][0]
            if(val1 == val2):
                nums.append([val1,nums1[i][1]+nums2[j][1]])
                i = i+1
                j = j+1
            elif(val1<val2):
                nums.append([val1,nums1[i][1]])
                i = i+1
            else:
                nums.append([val2,nums2[j][1]])
                j = j+1
        
        while(i<len(nums1)):
            val1 = nums1[i][0]
            nums.append([val1,nums1[i][1]])
            i = i+1
        while(j<len(nums2)):
            val1 = nums2[j][0]
            nums.append([val1,nums2[j][1]])
            j = j+1
        return nums[1:]