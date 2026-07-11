class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        write = 0
        read = 0
        n = len(chars)

        while read < n:
            curr = chars[read]
            count = 0

            while read < n and chars[read] == curr:
                read += 1
                count += 1

            chars[write] = curr
            write += 1

            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1

        return write        