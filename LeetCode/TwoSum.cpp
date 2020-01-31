class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       //sort(nums.begin(),nums.end());
       unordered_map<int,int> mp;
       unordered_map<int,int>::iterator it;
        int k = nums.size();
        //vector<int> z;
        for(int i=0;i<k;i++){
            int p = target - nums[i];
            it = mp.find(p);
            if(it != mp.end() && it->second != i){
                return {i, it->second};
            }
            mp[nums[i]]=i;
        }
        return {}; 
    }
};