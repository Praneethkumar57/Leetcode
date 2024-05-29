class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        for val in arr:
            if(val<=k):
                k = k + 1
            else:
                break
        return(k)