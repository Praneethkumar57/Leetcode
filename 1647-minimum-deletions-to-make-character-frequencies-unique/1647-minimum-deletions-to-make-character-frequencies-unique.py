class Solution:
    def minDeletions(self, s: str) -> int:
        count = 0
        dic = {}
        for val in s:
            if(val not in dic.keys()):
                dic[val]=1
            else:
                dic[val] = dic[val]+1
        arr = [dic[x] for x in dic]
        print(arr)
        # for i in range(len(arr)-1):
        #     for j in range(len(arr)):
        #         if(i!=j):
        #             if(arr[i]==arr[j] and arr[i]!=0):
        #                 arr[j]=arr[j]-1
        #                 count = count+1

        max_ele = max(arr) 
                    
        while(max_ele != 0):
            in_cnt = 0
            for i in range(len(arr)):
                if(arr[i]==max_ele and in_cnt==0):
                    in_cnt = 1
                elif(arr[i]==max_ele and in_cnt!=0):
                    arr[i] = arr[i]-1
                    count = count + 1
            max_ele = max_ele-1
        print(arr)
        return(count)