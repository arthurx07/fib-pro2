#include <iostream>

template <typename T> void change_var(T& a, T& b)
{
  T t = a;
  a = b;
  b = t;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cout << "Error: parameters a b were expected but not found" << std::endl;
    exit(1);
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  // char a = *argv[1];
  // char b = *argv[2];
  
  std::cout << "a is: " << a << " and b is: " << b << std::endl;
  change_var(a, b);
  std::cout << "a is: " << a << " and b is: " << b << std::endl;
}

