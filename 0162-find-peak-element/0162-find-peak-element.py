class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)-1
        if(n == 0): return(0)
        if(nums[0]>nums[1]): return(0)
        if(nums[n]>nums[n-1]): return(n)
        low = 1
        high = n-1
        while(low<=high):
            mid = (low+high)//2
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]):return(mid)
            if(nums[mid+1]>nums[mid]):
                low = mid + 1
            else:
                high = mid - 1
        return -1
        