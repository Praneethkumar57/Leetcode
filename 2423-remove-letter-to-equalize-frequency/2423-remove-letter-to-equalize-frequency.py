class Solution:
    def equalFrequency(self, word: str) -> bool:
        dic1 = {}
        arr = []
        for val in word:
            if(val not in dic1.keys()):
                dic1[val]=1
            else:
                dic1[val]= dic1[val]+1
        arr = [dic1[x] for x in dic1.keys()]
        for i in range(len(arr)):
            flag = 0
            arr[i] = arr[i]-1
            if(arr[i]!=0):
                val = arr[i]
            else:
                val = max(arr)
            for j in range(len(arr)):
                if(arr[j]!=0 and arr[j]!=val):
                    flag = 1
                    arr[i]=arr[i]+1
                    break
            if(flag == 0):
                return True
        return False