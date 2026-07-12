class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        rows = len(matrix)
        cols = len(matrix[0])

        top, bottom = 0, rows - 1
        left, right = 0, cols - 1

        result = []

        while top <= bottom and left <= right:
            # Top row
            for j in range(left, right + 1):
                result.append(matrix[top][j])
            top += 1

            # Right column
            for i in range(top, bottom + 1):
                result.append(matrix[i][right])
            right -= 1

            # Bottom row
            if top <= bottom:
                for j in range(right, left - 1, -1):
                    result.append(matrix[bottom][j])
                bottom -= 1

            # Left column
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    result.append(matrix[i][left])
                left += 1

        return result        