class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def first():
            left, right = 0, len(nums) - 1
            ans = -1

            while left <= right:
                mid = (left + right) // 2

                if nums[mid] == target:
                    ans = mid
                    right = mid - 1      # Keep searching left
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1

            return ans

        def last():
            left, right = 0, len(nums) - 1
            ans = -1

            while left <= right:
                mid = (left + right) // 2

                if nums[mid] == target:
                    ans = mid
                    left = mid + 1       # Keep searching right
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1

            return ans

        return [first(), last()]      