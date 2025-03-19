#pragma once

#include <ctime>
#include <random>
#include <chrono>
#include <vector>
#include <numeric>
#include <iomanip>
#include "randint.h"

template <class T>
std::vector<T> randarr(int lsz, int rsz, T lai, T rai) {
    std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    int sz = randint<int>(lsz, rsz);
    std::vector<T> ans(sz);
    for (int i = 0; i < sz; i++) {
        ans[i] = randint<T>(lai, rai);
    }
    return ans;
}

std::vector<int> randperm(int lsz, int rsz, bool zero_index = false) {
    int sz = randint<int>(lsz, rsz);
    std::vector<int> ans(sz);
    iota(ans.begin(), ans.end(), (int)zero_index);
    for (int i = 1; i < sz; i++) {
        int swp = randint<int>(0, i);
        std::swap(ans[swp], ans[i]);
    }
    return ans;
}