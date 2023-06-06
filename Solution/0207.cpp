// Reference: https://medium.com/@ryanyang1221/leetcode-challenge-5-29-course-schedule-%E4%B8%89%E9%83%A8%E6%9B%B2%E5%A4%A7%E7%A6%AE%E5%8C%85-%E4%B8%8A-64d17fa5b1ba

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> graph;
        int numVisit = 0;
        
        // Initialization
        for(int i=0; i<numCourses; ++i){
            indegree[i] = 0;
            vector<int> g;
            graph[i] = g;
        }
        
        for(int i=0; i<prerequisites.size(); ++i){
            indegree[prerequisites[i][0]] += 1;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> queue;
        for(int i=0; i<numCourses; ++i){
            if(indegree[i] == 0)
                queue.push_back(i);
        }
        
        while(queue.size() > 0){
            int course = queue.back();
            queue.pop_back();
            numVisit += 1;
            if(graph[course].size() != 0){
                for(int i=0; i<graph[course].size(); ++i){
                    indegree[graph[course][i]] -= 1;
                    if(indegree[graph[course][i]] == 0)
                        queue.push_back(graph[course][i]);
                }
            }
        }
        
        return numVisit == numCourses;
    }
};