class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)+1
        val =n*[0]
        for vals in nums:
            val[vals]=1
        c =0
        for ind in val:
            if(ind==0):
                return c
            c=c+1