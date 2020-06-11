#pragma once
#include <vector>

struct VectorEndpoints {
    int a_;
    int b_;
    explicit VectorEndpoints(const std::vector<int>& v);
    void vectorEndpoints_();
};
