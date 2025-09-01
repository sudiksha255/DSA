class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //bi->ai
        vector<int> indegree(numCourses,0);
        vector<vector<int>>adjList(numCourses);
        vector<int>result;
        for(auto & pre:prerequisites){
            indegree[pre[0]]++;
            adjList[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(int nei:adjList[node]){
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        if(result.size()!=numCourses) return {};
        return result;
    }
};