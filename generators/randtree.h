#pragma once

#include <vector>
#include <algorithm>
#include "randint.h"

std::vector<std::pair <int, int>> randtree(int n) {
    int root = randint<int> (0, n-1);
    std::vector<int> pr(n);
    pr[0] = -1;
    for (int i = 1; i < n; i++) {
        int rnd = i;
        rnd = randint<int>(0, i-1);
        pr[i] = rnd;
    }
    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (pr[i] != -1) ans.push_back({(pr[i] + root) % n, (i + root) % n});
    }
    return ans;
}

std::vector<int> randtreeParents(int root, int n) {
    std::vector<int> pr(n);
    pr[0] = -1;
    for (int i = 1; i < n; i++) {
        int rnd = i;
        rnd = randint<int>(0, i-1);
        pr[i] = rnd;
    }
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[(i + root) % n] = pr[i];
    }
    return ans;
}