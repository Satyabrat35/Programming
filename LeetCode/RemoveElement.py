
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = len(nums)
        ct = 0
        for i in range(0,k):
            if val != nums[i]:
                nums[ct] = nums[i]
                ct=ct+1
                
        return ct
        