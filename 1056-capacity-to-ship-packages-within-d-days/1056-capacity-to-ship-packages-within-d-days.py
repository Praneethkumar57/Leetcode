class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        low = max(weights)
        high = sum(weights)
        index = high
        while(low<=high):
            mid = (low + high)//2
            cnt = 0
            s = 0
            for val in weights:
                s= s+ val
                if(s>mid):
                    cnt = cnt + 1
                    s = val
            cnt = cnt + 1
            if(cnt<=days):
                index = mid
                high = mid - 1
            else:
                low = mid + 1
        return(index)