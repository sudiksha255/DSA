class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for(auto & pre:prerequisites){
            indegree[pre[0]]++;
            adjList[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
          if(indegree[i]==0){
            q.push(i);
          }
        }
        int finish=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            finish++;
        for(int nei:adjList[node]){
            indegree[nei]--;
            if(indegree[nei]==0){
                q.push(nei);
            }        
        }
    }
    return finish==numCourses;
    }
};