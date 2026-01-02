class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> occurances;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            occurances[nums[i]]++;
        }
        for(auto o:occurances){
            if(o.second==(nums.size()/2)) ans=o.first;
        }
      return ans;
    }
};