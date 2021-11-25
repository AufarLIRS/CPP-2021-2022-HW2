#include<iostream>
#include<tuple>
#include<vector>
void log(const char* &str)
{
  for (int i = 0, i < str.length();i++)
  {
    std::cout << i;
  }
}

void swap(auto a, auto b)
{
  auto t = &a;
  &a = &b;
  &b = t;
}

constexpr fact(int n)
{
  if (n > 0)
    return n * fact(n - 1);
  return 1;
}
std::vector<int> naturals(int n)
{
  std::vector<int> vec;
  for (int i = 1; i <= n; i++)
  {
    vec.insert(n);
  }
  return vec;
}

std::tuple<char*, char*> returnFL() 
{ 
  std::tuple a = [ "—абиров", "–ишат" ];
  return a;
}

int main()
  {
  //fact(33) - выполн€етс€ во врем€ компил€ции;
  //int a; std::cin >> a; fact(a) - выполн€етс€ во врем€ рантайма;
}