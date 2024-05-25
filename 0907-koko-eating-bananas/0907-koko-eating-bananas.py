import math
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 1
        high = max(piles)
        index = -1
        while(low<=high):
            mid = (low + high)//2
            s = 0
            for val in piles:
                s = s + math.ceil(val/mid)
            if(s<=h):
                index = mid
                high = mid - 1
            else:
                low = mid + 1
        return(index)
