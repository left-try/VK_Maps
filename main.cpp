#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


int main() {
    std::ifstream is("../graph.txt");
    if (!is) {
        std::cerr << "Unable to open file graph.txt" << std::endl;
        return 1;
    }
    size_t size, m;
    is >> size;
    is >> m;
    std::vector<std::vector<int64_t>> graph;
    graph.resize(size);
    for (size_t i = 0; i < m; ++i) {
        int a, b;
        is >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int64_t start;
    is >> start;
    std::vector<int64_t> dist(size, -1);
    std::queue<int64_t> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        size_t u = q.front();
        q.pop();
        for (auto v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (auto d : dist) {
        std::cout << d << std::endl;
    }
    return 0;
}