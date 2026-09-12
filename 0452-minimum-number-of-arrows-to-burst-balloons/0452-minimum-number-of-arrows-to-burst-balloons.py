class Solution(object):
    def findMinArrowShots(self, points):
        points.sort(key=lambda x: x[1])

        arrows = 0
        end = float('-inf')

        for start, finish in points:
            if start > end:
                arrows += 1
                end = finish

        return arrows       