class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        for(char ch:s){
            if(ch>='A'&&ch<='Z'){
                res.push_back(ch-'A'+'a');
            }
            else if(ch>='0'&&ch<='9'||ch>='a'&&ch<='z'){
                res.push_back(ch);
            }
            else{
                continue;
            } 
        }
        int start=0,end=res.size()-1;
        while(start<end){
        if(res[start]==res[end]){
            start++;
            end--;
        }
        else return false;
        }
        return true;
    }
};