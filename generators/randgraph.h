#pragma once

#include "randtree.h"
#include <map>

std::vector<std::pair<int, int>> randgraph(int n, int l, int r, bool directed = false, bool self_loops = false) {
    std::vector<std::pair<int, int>> ans;
    std::map<std::pair<int, int>, bool> edges;
    int cnt = randint<int>(l, r);
    for (int i = 0; i < cnt; i++) {
        int u = randint<int>(0, n-1);
        int v = randint<int>(0, n-1);
        while (edges[{u, v}] || (!directed && edges[{v, u}]) || (!self_loops && u == v)) {
            u = randint<int>(0, n-1);
            v = randint<int>(0, n-1);
        }
        ans.emplace_back(u, v);
        edges[{u, v}] = true;
        if (!directed) edges[{v, u}] = true;
    }
    return ans;
}

std::vector<std::pair<int, int>> randconnectedgraph(int n, int l, int r, bool directed = false, bool self_loops = false) {
    std::vector<std::pair<int, int>> ans = randtree(n);
    std::map<std::pair<int, int>, bool> edges;
    for (auto& [u, v] : ans) {
        edges[{u, v}] = true;
        edges[{v, u}] = true;
    }
    int cnt = randint<int>(std::max(0, l-(n-1)), std::max(0, r-(n-1)));
    for (int i = 0; i < cnt; i++) {
        int u = randint<int>(0, n-1);
        int v = randint<int>(0, n-1);
        while (edges[{u, v}] || (!directed && edges[{v, u}]) || (!self_loops && u == v)) {
            u = randint<int>(0, n-1);
            v = randint<int>(0, n-1);
        }
        ans.emplace_back(u, v);
        edges[{u, v}] = true;
        if (!directed) edges[{v, u}] = true;
    }
    return ans;
}

std::vector<std::pair<int, int>> randDAG(int n, int l, int r) {
    std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::vector<int> perm(n);
    std::iota(perm.begin(), perm.end(), 0);
    std::shuffle(perm.begin(), perm.end(), rng);
    std::vector<std::pair<int, int>> ans;
    std::map<std::pair<int, int>, bool> edges;
    int len = randint<int>(l, r);
    for (int i = 0; i < len; i++) {
        int u = randint<int>(0, n-2);
        int v = randint<int>(u+1, n-1);
        edges[{perm[u], perm[v]}] = true;
        ans.emplace_back(perm[u], perm[v]);
    }
    return ans;
}