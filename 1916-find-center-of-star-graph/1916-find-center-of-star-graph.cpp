#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;

        // Count degrees of each node
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
        }

        // Find the node with degree edges.size() (n - 1 in this case)
        for (auto& entry : degree) {
            if (entry.second == edges.size()) {
                return entry.first;
            }
        }

        return -1; // Not found (though according to problem statement, always one center)
    }
};