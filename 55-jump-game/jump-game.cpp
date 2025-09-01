class Solution {
public:
unordered_map<int,bool> mem;
    bool canJump(vector<int>& nums) {
        return dfs(nums,0);
    }
    bool dfs(vector<int>&nums,int i){
      if(mem.count(i)) return mem[i];  
      if(i==nums.size()-1) return true;
      if(nums[i]==0) return false;
      int end=min((int)nums.size()-1,i+nums[i]);
      for(int j=i+1;j<=end;j++){
        if(dfs(nums,j)){
        mem[i]=true;
        return true;
        }
      }
      mem[i]=false;
      return false;
    }

};