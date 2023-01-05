class Solution {
public:
    //Normal dfs but using, three sets.
    bool dfs(int v , vector<vector<int>> &adj , vector<int> &visited){
        visited[v] = 1;
        for(int u : adj[v]){
           if(!visited[u]){
              visited[u] = 1; 
              if(dfs(u , adj , visited)) return true;
           //If the node is 1, it means we have a cycle.
           }else if(visited[u] == 1){
               return true;
           }
        }
        //All neighbors visited.
        visited[v] = 2;
        return false;
    } 

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        // Three sets, not visited = 0 , partial visited = 1 , all visited = 2.
        vector<int>visited(numCourses, 0);
        
        // building the graph
        for(int i=0; i<prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i] && dfs(i , adjList , visited)) return false;
        }
        return true;
    }
};