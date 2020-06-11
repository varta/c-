#include "multifile-cpp.h"
#include <cassert>
#include <iostream>

VectorEndpoints::VectorEndpoints(const std::vector<int>& v) {
    assert(v.size() > 1);
    a_ = *v.begin();
    b_ = *(v.end()-1);
}

void VectorEndpoints::vectorEndpoints_() {
    std::cout << "{" << a_ << ", " << b_ << "}";
}
