class Solution(object):
    def searchMatrix(self, matrix, target):
        for val in matrix:
            if target in val:
                return True
        return False
        