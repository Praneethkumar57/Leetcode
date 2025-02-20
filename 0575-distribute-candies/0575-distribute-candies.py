class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        dic = {}
        for val in candyType:
            if(val not in dic.keys()):
                dic[val]=1
        arr = [dic[x] for x in dic.keys()]
        val = len(candyType)//2
        if(len(arr)>val):
            return val
        else:
            return(len(arr))