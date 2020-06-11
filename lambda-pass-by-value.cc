#include <iostream>
#include <vector>

int main()
{
  int n;
  [&](){n = 10;}();

  [vn = n]() mutable {
    vn += 10;
    std::cout << vn << "\n";  // "20"
    }();

  [&vn = n]() {
    vn += 10;
    std::cout << vn << "\n";  // "20"
    }();

  //// Error: a by-value capture cannot be modified in a non-mutable lambda
  // [=](){n += 10;}();
  std::cout << n << "\n";  // "20"

  [vn = std::move(n)]() mutable {
    vn += 30;
    std::cout << vn << "\n"; // "50"
    }();

  std::cout << n << "\n";  // "20" -- not destroyed by std::move

  // Trying vector, that's destroyed by std::move
  std::vector<int> vecn{1, 2, 3, 4};
  [vvecn = std::move(vecn)]() mutable {
    vvecn[3] += 40;
    std::cout << vvecn[3] << "\n"; // "44"
    }();

  std::cout << vecn[3] << "\n"; // seg fault, vecn destroyed by std::move!

}
