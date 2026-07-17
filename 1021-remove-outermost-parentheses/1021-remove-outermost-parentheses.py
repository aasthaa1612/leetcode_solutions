class Solution(object):
    def removeOuterParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = []
        count = 0

        for ch in s:
            if ch == '(':
                if count > 0:
                    ans.append(ch)
                count += 1
            else:
                count -= 1
                if count > 0:
                    ans.append(ch)

        return "".join(ans)        