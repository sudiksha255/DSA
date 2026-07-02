class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int  end=nums.size()-1;
       int start=0;
           for(int i=start;i<end;i++){
               for (int j=i+1;j<end+1;j++){
                   if(nums[i]+nums[j]==target){
                       return {i,j};
                   }
               }
           }return {};

    }
};