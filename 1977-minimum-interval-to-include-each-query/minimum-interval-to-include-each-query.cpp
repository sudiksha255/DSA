class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>qs;
        qs.reserve(queries.size());
        for(int i=0;i<(int)queries.size();i++){
            qs.push_back({queries[i],i});
        }
        sort(qs.begin(),qs.end());
        
        vector<int>ans(queries.size(),-1);
        using P=pair<int,int>;
        priority_queue<P,vector<P>,greater<P>> pq;
        int i=0;
        for(auto[q,idx]:qs ){
            while(i<(int)intervals.size()&&intervals[i][0]<=q){
                int L=intervals[i][0],R=intervals[i][1];
                pq.push({R-L+1,R});
                i++;
            }
            while(!pq.empty()&&pq.top().second<q) pq.pop();

            if(!pq.empty()) ans[idx]=pq.top().first;
        }
        return ans;
    }
};