class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        int completedCount = 0;

        for (auto prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            indegrees[prerequisite[0]]++;
        }

        deque<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push_back(i);
            }
        }

        while (!q.empty()) {
            int ref = q.front();
            for (int neighbour: graph[ref]) {
                indegrees[neighbour]--;
                if (indegrees[neighbour] == 0) {
                    q.push_back(neighbour);
                }
                cout << neighbour;
            }
            cout << ref << endl;
            q.pop_front();
            completedCount++;
        }

        completedCount += q.size();

        if (completedCount == numCourses) {
            return true;
        }

        return false;
    }
};
