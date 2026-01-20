class Solution {
public:
    string minWindow(string s, string t) {
        if((s.length()<t.length())||(t.empty())) return "";

        unordered_map<char,int> required, window;
        for(char ch:t){
            required[ch]++;
        }
        int totalReqChar=required.size();
        int matchedChar=0;
        int left=0,right=0;

        int windowSize=INT_MAX;
        int startIndex=0;
        while(right<s.size()){
            window[s[right]]++;
            if(required.count(s[right])&&window[s[right]]==required[s[right]]){               matchedChar++;
            }
            while(matchedChar==totalReqChar){
                if(right-left+1<windowSize){
                    windowSize=right-left+1;
                    startIndex=left;
                }
                window[s[left]]--;
                if(required.count(s[left])&&window[s[left]]<required[s[left]]){
                    matchedChar--;
                }
                left++;
            }
            right++;
        }
       return windowSize == INT_MAX ? "" : s.substr(startIndex, windowSize);

    }
};