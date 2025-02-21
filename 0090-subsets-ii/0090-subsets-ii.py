def subsets(ind,n,arr,temp,res):
    if(ind>=n):
        temp2 =temp[:]
        temp2.sort()
        if(temp2 not in res):
            res.append(temp2)
        return
    
    temp.append(arr[ind])
    subsets(ind+1,n,arr,temp,res)

    temp.pop()
    subsets(ind+1,n,arr,temp,res)


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        temp = []
        res = []
        subsets(0,n,nums,temp,res)
        return(res)