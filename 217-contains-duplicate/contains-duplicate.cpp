class Solution {
public:
// using unordered map(Hash Map) , TC->O(n) 
    bool containsDuplicate(vector<int>& nums) {
   sort(nums.begin(),nums.end());
        int i=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i++]==nums[j]){
                    return true;
                }
            }
        
        return false;
    }
};