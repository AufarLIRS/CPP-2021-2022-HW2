#include <iostream>
#include <string>
#include <tuple>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>

void log(const std::string& arg)
{
  std::cout << arg << std::endl;
}
void Task2()
{
  auto swap = [](auto& a, auto& b) {
    auto t = a;
    a = b;
    b = t;
  };

  int a = 5;
  int b = 6;
  swap(a, b);

  std::cout << a << std::endl;
  std::cout << b << std::endl;

  std::string s1("W");
  std::string s2("B");
  swap(s1, s2);

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
}

auto Credentials(const std::string& name, const std::string& lastName)
{
  return std::tuple<const std::string&, const std::string&>{ name, lastName };
}
void Task3()
{
  auto test{ Credentials("Hello", "World") };

  std::string name{ std::get<0>(test) };
  std::string lastName{ std::get<0>(test) };
}

int factorial(int n)
{
  return n == 1 ? 1 : n * factorial(n - 1);
}
constexpr int factorial_static(int n)
{
  return n == 1 ? 1 : n * factorial_static(n - 1);
}
void Task4()
{
  auto start_static{ std::chrono::high_resolution_clock::now() };

  constexpr auto result_static = factorial_static(12);
  std::cout << result_static << std::endl;

  std::chrono::duration<double> time_static{ std::chrono::high_resolution_clock::now() - start_static };
  std::cout << "static factorial time: " << std::fixed << std::setprecision(6) << time_static.count() << std::endl;

  auto start{ std::chrono::high_resolution_clock::now() };

  auto result = factorial(12);
  std::cout << result << std::endl;

  std::chrono::duration<double> time{ std::chrono::high_resolution_clock::now() - start };
  std::cout << "runtime factorial time: " << std::fixed << std::setprecision(6) << time.count() << std::endl;
}

std::vector<int> naturals(const int N)
{
  std::vector<int> vec(N);
  std::generate(vec.begin(), vec.end(), [&]() {
    static int i{ 1 };
    return i++;
  });
  return vec;
}

void Task5()
{
  auto nat{ naturals(5) };
  for (auto item : nat)
  {
    std::cout << item << std::endl;
  }
}

int main(int argc, char* argv[])
{
  // Task1
  // log(argv[1]);

  // Task2();
  // Task3();
  // Task4();
  // Task5();
}