#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>


namespace std {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        os << "{";
        for (auto v: vec) {
            os << v << ',';
        }
        os << "}";
        return os;
    }
}
template <typename T> void
partition_lomuto(typename std::vector<T>::iterator begin,
                 typename std::vector<T>::iterator end,
                 T part) {
  for (auto it = begin; it < end; ++it) {
    std::cout << "processing " << it - begin << ":" << *it << std::endl;
    if (*it >= part) {
      auto jt = it + 1;
      std::cout << jt - begin << ":" << *jt << std::endl;
      for (; jt < end; ++jt) {
        if (*jt < part) {
          std::cout << "swapping " << jt - begin << ':' << *jt << " <-> "
                    << it - begin << ':' << *it << " for partitioning by " << part << std::endl;
          std::swap(*jt, *it);
          break;
        }
      }
    }
  }
}

int main() {
    std::vector<int> a(50);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(-100, 100);

    std::generate(a.begin(), a.end(), [&distrib, &gen]() { return distrib(gen); } );
    std::vector<int> b(a.begin(), a.end());
    std::cout << a << std::endl;

    auto partition_by = *a.begin();
    partition_lomuto<int>(a.begin(), a.end(), partition_by);
    std::cout << a << std::endl;

    auto it = a.begin();
    for (; (it < a.end()) && (*it < partition_by); ++it) { }
    for (; it < a.end(); ++it) {
      assert(*it >= partition_by);
    }
    return 0;
}
