#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void log(const std::string& str_)
{
  std::cout << str_ << std::endl;
}

void swap(auto& x, auto& y)
{
  auto temp = x;
  x = y;
  y = temp;
}

auto task_3(std::string surname, std::string name)
{
  return std::pair<std::string, std::string>{ surname, name };
}

constexpr int factorial(int x)
{
  if (x <= 1)
    return x;
  return x * (factorial(x - 1));
}

auto naturals(int N)
{
  std::vector<int> vec(N);

  auto lambda_func = [&]() {
    static int i{ 0 };
    i++;
    return i;
  };

  std::generate(vec.begin(), vec.end(), lambda_func);

  return vec;
}

int main()
{
  std::string str_("STRING");
  log(str_);

  int x1 = 2;
  int x2 = 5;
  swap(x1, x2);
  std::cout << x1 << " " << x2 << std::endl;

  auto [username, name] = task_3("Shumbasov", "Pavel");
  std::cout << username << " " << name << std::endl;

  constexpr int f = factorial(7);
  std::cout << f << std::endl;
  int num;
  std::cout << "Введите число: ";
  std::cin >> num;
  std::cout << factorial(num) << std::endl;

  auto vec = naturals(8);
  for (auto x : vec)
  {
    std::cout << x << " ";
  }
}
