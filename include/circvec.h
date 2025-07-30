//
// Created by Theodore on 7/26/2025.
//

#ifndef CIRCVEC_H
#define CIRCVEC_H
#include <vector>

// Vector class that allows accessing elements in a circular way. 0 indexed.
// Example: get(-1) would get the last element, get(-2) would get the
// second to last element, etc. If it has a size of 6, get(7) would
// return the second element (7-6 = 1).

template<typename T>
class circvec
{
    std::vector<T> v;
public:
    explicit circvec(std::vector<T> v) : v(v) {}

    std::vector<T> vec()
    {
        return v;
    }

    int circIdx(int idx)
    {
        const int n = v.size();
        idx = (abs(idx) % n) * (abs(idx)/idx);
        return (idx + n) % n;
    }

    T get(const int idx)
    {
        return v.at(circIdx(idx));
    }

    void erase(const int idx)
    {
        v.erase(v.begin() + circIdx(idx));
    }

    unsigned long long size()
    {
        return v.size();
    }
};

#endif //CIRCVEC_H
