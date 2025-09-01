class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        //if n does not exist in visited
        while(visited.find(n)==visited.end()){
            visited.insert(n);
            n=sumOfSquare(n);
            if(n==1) return true;
        }
        return false;
    }
    int sumOfSquare(int n){
        int output=0;
        while(n>0){
            int digit=n%10;
            digit=digit*digit;
            output+=digit;
            n=n/10;
        }
        return output;
    }
};