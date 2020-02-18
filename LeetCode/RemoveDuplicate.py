class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = len(nums)
        i=0
        j=0
        ct=1
        while i<k-1 and ct<k:
            if nums[i] == nums[ct]:
                ct+=1
                j+=1
            else:
                nums[i+1] = nums[ct]
                i+=1
                ct+=1
        return k-j
        