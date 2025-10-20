class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%2!=0) return false;
        unordered_set<int> dp;
        dp.insert(0);
        int target=sum/2;
        
    for(int i=nums.size()-1;i>0;i--){
       unordered_set<int> nextDp; 
       for(int t:dp){
        if(t+nums[i]==target){
            return true;
        }
        nextDp.insert(t+nums[i]);
        nextDp.insert(t);
       }
       dp=nextDp;
    }
    return false;
    }
};