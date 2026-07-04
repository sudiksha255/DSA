class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0, n =intervals.size();
        //interval=[1,2][3,4][5,6],[8,10],[11,12]
        //newinterval=[4,9]
        vector<vector<int>> result;
        while(i<n&&intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        while(i<n&&newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
return result;

    }
};