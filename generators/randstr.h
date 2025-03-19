#pragma once

#include <vector>
#include "randint.h"

std::string randstr(int l, int r) {
    int len = randint<int>(l, r);
    std::string ans = "";
    for (int i = 0; i < len; i++) {
        ans += randint<char>('a', 'z');
    }
    return ans;
}

std::string randstr(int l, int r, std::string pattern) {
    int len = randint<int>(l, r);
    std::vector<char> chars;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == '-') {
            for (char j = pattern[i-1]; j <= pattern[i+1]; j++) {
                chars.push_back(j);
            }
        } else if ((i+1 < pattern.size() && pattern[i+1] == ' ') || i == pattern.size() - 1) {
            chars.push_back(pattern[i]);
        }
    }
    std::string ans = "";
    for (int i = 0; i < len; i++) {
        ans += chars[randint<int>(0, chars.size() - 1)];
    }
    return ans;
}

std::string randstr(int l, int r, std::string pattern, std::string special) {
    int len = randint<int>(l, r);
    std::vector<char> chars;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == '-') {
            for (char j = pattern[i-1]; j <= pattern[i+1]; j++) {
                chars.push_back(j);
            }
        } else if (i+1 < pattern.size() && pattern[i+1] == ' ') {
            chars.push_back(pattern[i]);
        }
    }
    for (int i = 0; i < special.size(); i++) {
        chars.push_back(special[i]);
    }
    std::string ans = "";
    for (int i = 0; i < len; i++) {
        ans += chars[randint<int>(0, chars.size() - 1)];
    }
    return ans;
}