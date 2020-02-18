class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        int count = 0;
        for(int i=0;i<k;i++){
            if(val != nums[i]){
                nums[count++] = nums[i];
            }
        }
    
        return count;
    }
};