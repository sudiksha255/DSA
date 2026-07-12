class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagramGroup;
        for(auto word:strs){
        vector<char>count(26,0);
        for(char c:word){
            count[c-'a']++;
        }
        string key;
        for(int i=0;i<26;i++){
            key+=to_string(count[i])+'#';
        }
        anagramGroup[key].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto& group:anagramGroup){
            ans.push_back(group.second);
        }
        return ans;
    }
};