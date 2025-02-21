def subset(ind,n,arr,temp,res):
    if(ind>=n):
        res.append(temp[:])
        return
    
    temp.append(arr[ind])
    subset(ind+1,n,arr,temp,res)

    temp.pop()
    subset(ind+1,n,arr,temp,res)

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        temp =[]
        res = []
        subset(0,n,nums,temp,res)
        return res
        