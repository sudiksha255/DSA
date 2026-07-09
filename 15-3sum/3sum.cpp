class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> ans;
           sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size();i++){
            //if the first no. is greater than 0 then no possibility that the sum of three digits would be 0 since array is sorted and all digits would be grater 
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                if(sum>0) right--;
                else if(sum<0) left++;
                else {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right&&nums[left]==nums[left-1]) left++;
                    while(left<right&&nums[right]==nums[right+1]) right--;

                }
            }
            
          }return ans;
    }
};