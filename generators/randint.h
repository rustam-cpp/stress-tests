#pragma once

#include <ctime>
#include <random>
#include <chrono>

template <class T>
T randint(T l, T r) {
    std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    T rnd = rng() % (r - l + 1);
    rnd = abs(rnd) + l;
    return rnd;
}