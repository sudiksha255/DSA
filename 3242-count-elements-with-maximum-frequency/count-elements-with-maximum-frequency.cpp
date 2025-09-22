class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n:nums){
            freq[n]++;
        }
        int max_freq=0;
        for(auto& p:freq){
            max_freq=max(max_freq,p.second);
        }
        int result=0;
        for(auto& p:freq){
            if(p.second==max_freq){
                result+=p.second;
            }
        }
        return result;
    }
};