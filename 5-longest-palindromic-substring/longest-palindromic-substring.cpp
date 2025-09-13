class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int resLen=0;
        for(int start=0;start<s.length();start++){
            for(int end=start;end<s.length();end++){
                int l=start,r=end;
                while(l<r&&s[l]==s[r]){
                    l++;
                    r--;
                }
                if(l>=r&&resLen<(end-start+1)){
                    res=s.substr(start,end-start+1);
                    resLen=end-start+1;
                }
            }
        }
        return res;
    }
};