class Solution {
public:
//for storing prerequisites
unordered_map<int,vector<int>> prerequisiteMap;
//for detecting a cycle
unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //creates a node for every couse even if it does not have a prerequisite
        for(int i=0;i<numCourses;i++){
            prerequisiteMap[i]={};
        }
        //adds the prerequisites
        for(const auto& prereq:prerequisites){
           prerequisiteMap[prereq[0]].push_back(prereq[1]);
        }
        // run dfs on each couse
        for(int c=0;c<numCourses;c++){
        //if cycle found return false
            if(!dfs(c)) return false;
        }
        return true;
    }
    bool dfs(int course){
        //if exist in visited => cycle detected return false
        if(visited.count(course)) return false;
        //if does not exist in map => already processed or empty return true
        if(prerequisiteMap[course].empty()) return true;
        //add course to visted
        visited.insert(course);
        for(int prereq:prerequisiteMap[course]){
          if(!dfs(prereq)) return false;
        }
        //remove couse from visited => checked its prerequisite
        visited.erase(course);
        //remove prereq from the map and mark it as clear
        prerequisiteMap[course].clear();

        return true;
    }
};