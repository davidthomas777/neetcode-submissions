class Solution:
    def search(self, nums: List[int], target: int) -> int:
        r_node = len(nums)
        l_node = 0
        while l_node < r_node:
            middle = int((r_node + l_node) / 2)
            if nums[middle] == target:
                return middle
            elif nums[middle] <= target:
                l_node = middle + 1
            else:
                r_node = middle
        return -1
        
