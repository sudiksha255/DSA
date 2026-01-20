class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()||s.length()<t.length()) return "";

        unordered_map<char,int> requiredCharT,currWindowS;
        for(char ch:t){
            requiredCharT[ch]++;
        }
        int left=0,newIndex=0,windowSize=INT_MAX;
        int haveChar=0,needChar=requiredCharT.size();
        for(int right=0;right<s.size();right++){
            char ch=s[right];
            currWindowS[ch]++;

            if(requiredCharT.count(ch)&&currWindowS[ch]==requiredCharT[ch]){
               haveChar++;
            }
            while(haveChar==needChar){
                char ch=s[left];
                
                if(right-left+1<windowSize){
                    windowSize=right-left+1;
                    newIndex=left;
                }
                currWindowS[ch]--;
                if(requiredCharT.count(ch)&& currWindowS[ch]<requiredCharT[ch]){
                    haveChar--;
                }
                left++;
            }
        }
            return windowSize==INT_MAX?"":s.substr(newIndex,windowSize);
        

    }
};