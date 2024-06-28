class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    // Step 1: Initialize degree array and compute degrees
    vector<int> degree(n, 0);
    for (auto& road : roads) {
        degree[road[0]]++;
        degree[road[1]]++;
    }
    
    // Step 2: Create a list of (degree, city) pairs and sort by degree descending
    vector<pair<int, int>> city_degrees;
    for (int i = 0; i < n; ++i) {
        city_degrees.push_back({degree[i], i});
    }
    sort(city_degrees.rbegin(), city_degrees.rend()); // sort by degree descending
    
    // Step 3: Assign values from 1 to n based on sorted degrees
    vector<int> values(n);
    int current_value = n; // Start assigning values from n down to 1
    for (int i = 0; i < n; ++i) {
        values[city_degrees[i].second] = current_value--;
    }
    
    // Step 4: Calculate total importance
    long long total_importance = 0;
    for (auto& road : roads) {
        total_importance += values[road[0]] + values[road[1]];
    }
    
    return total_importance;
    }
};