class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        for val in nums:
            if val == target:
                return(True)
        return(False)