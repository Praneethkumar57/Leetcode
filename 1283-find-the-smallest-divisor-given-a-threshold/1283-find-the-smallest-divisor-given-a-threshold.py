import math
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        low = 1
        high = max(nums)
        index = -1
        while(low<=high):
            mid = (low + high)//2
            s = 0
            for val in nums:
                s =s + math.ceil(val/mid)
            if(s<=threshold):
                index = mid
                high = mid -1
            else:
                low = mid + 1
        return(index)
            
