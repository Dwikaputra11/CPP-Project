#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
char s []="unknown";
char f0 []="apple";
char f1 []="orange";
char f2 []="pear";
char c0 []="red";
char c1 []="green";
char c2 []="orange";

template <>
struct Traits<Fruit>
{
    public:
    static char* name(int a)
    {
        if(a>=3 || a<0)
            return s;
        else if (a==0)
            return f0;
        else if (a==1)
            return f1;
        else
            return f2;            
    }
};

template <>
struct Traits<Color>
{
    public:
    static char* name(int a)
    {
        if(a>=3 || a<0)
            return s;
        else if (a==0)
            return c0;
        else if (a==1)
            return c1;
        else
            return c2;  
    }
};//hackerrank.com/contests/code-cpp-4/challenges/cpp-class-template-specialization

int main() {
  
  int n,c,f;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> c >> f;
    cout << Traits<Color>::name(c) << " ";
    cout << Traits<Fruit>::name(f) << "\n";
  }



  return 0;
}