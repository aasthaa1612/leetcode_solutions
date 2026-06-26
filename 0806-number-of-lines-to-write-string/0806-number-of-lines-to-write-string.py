class Solution(object):
    def numberOfLines(self, widths, s):
        """
        :type widths: List[int]
        :type s: str
        :rtype: List[int]
        """
        lines = 1
        curr_width = 0

        for ch in s:
            w = widths[ord(ch) - ord('a')]

            if curr_width + w > 100:
                lines += 1
                curr_width = w
            else:
                curr_width += w

        return [lines, curr_width]