class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        vector<int> res;
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
            }
            cout << ref << endl;
            q.pop_front();
            res.push_back(ref);
            completedCount++;
        }

        completedCount += q.size();
        if (completedCount != numCourses) {
            return {};
        }

        int remaining = q.size();
        for (int i = 0; i < remaining; i++) {
            res.push_back(q.front());
            q.pop_front();
        }

        return res;
    }
};
