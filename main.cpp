#include<string>
#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>

void Task1(const std::string& str)
{
   std::cout<<str<<std::endl;
}

void swap(auto& x1, auto& x2)
{
   auto x=x1;
   x1=x2;
   x2=x;
}

void Task2()
{
  int a = 5;
  int b = 6;
  swap(a, b);  

  std::string s1("W");
  std::string s2("B");
  swap(s1, s2);
}

void Task4(int n)
{
auto start=std::chrono::high_resolution_clock::now();
int x=1;
for(auto i{1}; i <= n; i++) 
{
	x = x * i;
}
std::chrono::duration<double> diff= std::chrono::high_resolution_clock::now() -start;
std::cout<< x <<std::endl;
std::cout<< diff.count() <<std::endl;
}

constexpr int Task4Const(int n)
{
int x=1;
for(auto i=1; i <= n; i++) 
{
	x = x * i;
}
return x;
}

void Task5(int n)
{
std::vector<int> vector(n);
auto func = [&]()
    {
        static int i{0};
        i++;
        return i;
    };

    std::generate(vector.begin(), vector.end(),func);
    for (auto i = 0; i < vector.size(); i++)
    {
        std::cout<<vector[i]<<" ";
    }    
}

int main()
{
int n=10;
const std::string str="слово";

Task1(str);

Task2();

auto start=std::chrono::high_resolution_clock::now();
int y=Task4Const(n);
std::chrono::duration<double> diff= std::chrono::high_resolution_clock::now() -start;
std::cout<<y<<std::endl;
std::cout<< diff.count() <<std::endl;

Task4(n);

Task5(n);
}