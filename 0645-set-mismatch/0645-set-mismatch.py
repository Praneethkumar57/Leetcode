class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)+1
        arr = n*[0]
        for val in nums:
            arr[val]=arr[val]+1
        # index1=,index2
        for i in range(1,len(arr)):
            if(arr[i]==2):
                index1=i
            if(arr[i]==0):
                index2 = i
        return([index1,index2])