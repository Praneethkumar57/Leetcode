class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        dic = {}
        for i in range(len(items1)):
            dic[items1[i][0]] = items1[i][1]
        for i in range(len(items2)):
            if(items2[i][0] not in dic.keys()):
                dic[items2[i][0]] = items2[i][1]
            else:
                dic[items2[i][0]] = dic[items2[i][0]]+items2[i][1]
        arr = list(dic.keys())
        arr.sort()
        arr1 = [[]]
        for vals in arr:
            arr1.append([vals,dic[vals]])

        return arr1[1:]
        