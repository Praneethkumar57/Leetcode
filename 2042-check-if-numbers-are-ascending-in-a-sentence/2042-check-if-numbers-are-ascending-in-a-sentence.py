class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        low = 0
        arr = []
        for i in range(len(s)):
            if(s[i]==' '):
                high = i
                arr.append(str(s[low:high]))
                low = i+1
        arr.append(str(s[low:]))
        prev = -1
        for val in arr:
            if(val.isnumeric()):
                if(int(val)>prev):
                    prev = int(val)
                else:
                    return False
        return True      