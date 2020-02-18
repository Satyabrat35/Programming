class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        int ct=1;
        int j=0;int i=0;
        while(i<k-1 && ct<k){
            if(nums[i] == nums[ct]){
                
                //cout<<ct<<' ';
                ct+= 1;
                j += 1;
            }
            else {
                nums[i+1] = nums[ct];
                //cout<<i<<' '<<ct<<' ';
                i += 1;
                ct+= 1;
                
            }
        }
        
        return k-j;
    }
};