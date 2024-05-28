class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        low = min(bloomDay)
        high = max(bloomDay)
        index = -1
        while(low<=high):
            mid = (low + high)//2
            cnt = 0
            bqt = 0
            for val in bloomDay:
                if(val<=mid):
                    cnt = cnt+1
                else:
                    bqt = bqt + (cnt//k)
                    cnt = 0
            bqt = bqt + (cnt//k)
            if(bqt>=m):
                index = mid
                high = mid - 1
            else:
                low = mid + 1
        return(index)