#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Log(const string& str)
{
  std::cout << str << std::endl;
}

void Swap(auto& x1, auto& x2)
{
  auto temp = x1;
  x1 = x2;
  x2 = temp;
}

auto Task_3(string surname, string name)
{
  return std::pair<std::string, std::string>{ surname, name };
}

int Find_fact(int x)
{
  if (x <= 1)
  {
    return x;
  }
  return x * (Find_fact(x - 1));
}

auto Naturals(int n)
{
  vector<int> out_vec(n);
  for (int i = 0; i < n; i++)
  {
    out_vec[i] = i + 1;
  }
  return out_vec;
}

int main()
{
  string str("Text");
  Log(str);

  int a{ 5 };
  int b{ 6 };
  Swap(a, b);
  std::cout << a << b << std::endl;
  std::string s1("W");
  std::string s2("B");
  Swap(s1, s2);
  std::cout << s1 << s2 << std::endl;

  auto [x1, x2] = Task_3("Lisenko", "Aleksey");
  std::cout << x1 << " " << x2 << std::endl;

  std::cout << Find_fact(5) << std::endl;
  int num;
  std::cout << "Введите число для нахождения фокториала: " << std::endl;
  std::cin >> num;
  std::cout << Find_fact(num) << std::endl;

  auto vect = Naturals(5);
  for (auto y : vect)
  {
    std::cout << y << std::endl;
  }
}
