class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        copy_list = nums[:]
        result_list = []
        for n in nums:
            copy_list.remove(n)
            result = 1
            for number in copy_list:
                result *= number
            result_list.append(result)
            copy_list = nums[:]
        return result_list

        
