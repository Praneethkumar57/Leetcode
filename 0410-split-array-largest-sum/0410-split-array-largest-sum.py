def func(nums, mid):
    length = 1
    work = 0
    for i in range(len(nums)):
        if(work + nums[i]<= mid):
            work = work + nums[i]
        else:
            length = length + 1
            work = nums[i]
    return length

class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        low = max(nums)
        high = sum(nums)
        if(k > len(nums)):
            return(-1)
        while(low<=high):
            mid = (low + high)//2
            length = func(nums, mid)
            if(length > k):
                low = mid + 1
            else:
                high = mid - 1
        return (low)
