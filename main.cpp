#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>

void Task1(const std::string& str)
{
  std::cout << str;
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
  return std::pair<const std::string&, const std::string&>{ name, lastName };
}

void Task3()
{
  auto test{ Credentials("Rishat", "Sabirov") };

  std::string name{ std::get<0>(test) };
  std::string lastName{ std::get<1>(test) };
}

constexpr int fact(int n)
{
  return n == 1 ? 1 : n * fact(n - 1);
}

void Task4()
{
  auto start_static{ std::chrono::high_resolution_clock::now() };

  auto result_static = fact(33);
  std::cout << result_static << std::endl;

  std::chrono::duration<double> time_static{ std::chrono::high_resolution_clock::now() - start_static };
  std::cout << "static factorial time: " << std::fixed << std::setprecision(6) << time_static.count() << std::endl;

  std::cout << "Enter a number for finding factorial" << std::endl;
  int n;
  std::cin >> n;

  auto start{ std::chrono::high_resolution_clock::now() };

  auto result = fact(n);
  std::cout << result << std::endl;

  std::chrono::duration<double> time{ std::chrono::high_resolution_clock::now() - start };
  std::cout << "runtime factorial time: " << std::fixed << std::setprecision(6) << time.count() << std::endl;
}

auto Naturals(int n)
{
  std::vector<int> vec(n);
  std::generate(vec.begin(), vec.end(), []() {
    static int i = 1;
    return i++;
  });
  return vec;
}
void Task5()
{
  std::cout << "Enter a number for create vector" << std::endl;
  int n;
  std::cin >> n;
  auto vect = Naturals(n);
  for (auto y : vect)
  {
    std::cout << y << std::endl;
  }
}

int main()
{
  Task1("Digital device");
  Task2();
  Task3();
  Task4();
  Task5();
}