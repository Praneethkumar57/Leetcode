class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        xor = 0
        for val in nums:
            xor = xor ^ val
        return(xor)