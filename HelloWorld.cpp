#include <cstdio>
#include <experimental/coroutine>
#include "generator.hpp"

using namespace std;
using namespace std::experimental;
generator<int> Hello() {
  for (auto ch : "Hello, World\n")
    co_yield ch;
}

int main() {
  for (auto ch : Hello())
    printf("%c\n", ch);
}
