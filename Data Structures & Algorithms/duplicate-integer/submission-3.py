class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        existing_nums = []
        for num in nums:
            if num not in existing_nums:
                existing_nums.append(num)
            elif num in existing_nums:
                return True
        return False