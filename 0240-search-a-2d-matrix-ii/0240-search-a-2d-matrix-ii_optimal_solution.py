class Solution(object):
    def searchMatrix(self, matrix, target):
        n = len(matrix)
        row = 0
        m = len(matrix[0])
        col = m-1
        while(row<n and col>=0):
            if(matrix[row][col]==target):
                return(True)
            elif(matrix[row][col]<target):
                row = row + 1
            else:
                col = col -1
        return(False)
        