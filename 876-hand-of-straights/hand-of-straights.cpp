class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return 0;
        sort(hand.begin(),hand.end());
        map<int,int> freq;
        for(int h:hand){
            freq[h]++;
        }
        for(auto f:freq){
            int card=f.first;
            int count=f.second;
            if(count>0){
                for(int i=0;i<groupSize;i++){
                    int nextCard=card+i;
                    if(freq[nextCard]<count) return false;
                    freq[nextCard]-=count;
                }
            }
        }
        return true;
    }
};