#include <chrono>
#include <iostream>
volatile long long sink=0;struct C{long long x;C&operator++(){++x;return *this;}C operator++(int){C old=*this;++x;return old;}};
template<bool P>long long run(){C c{0};for(int i=0;i<10000000;++i){if constexpr(P)c++;else ++c;}return c.x;}
int main(){auto a=std::chrono::steady_clock::now();sink=run<false>();auto b=std::chrono::steady_clock::now();sink=run<true>();auto c=std::chrono::steady_clock::now();std::cout<<"prefix_us="<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" postfix_us="<<std::chrono::duration_cast<std::chrono::microseconds>(c-b).count()<<" checksum="<<sink<<'\n';}
