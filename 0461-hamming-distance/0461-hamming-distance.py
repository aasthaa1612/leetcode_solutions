class Solution(object):
    def hammingDistance(self, x, y):
        n = x ^ y
        count = 0

        while n > 0:
            count += n & 1
            n = n >> 1

        return count       