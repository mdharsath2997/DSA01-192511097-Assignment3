#include <chrono>
#include <iostream>
volatile long long ps=0;volatile double ds=0;
int main(){constexpr int N=1000000;auto a=std::chrono::steady_clock::now();long long p=0;for(int i=0;i<N;++i)p+=75;auto b=std::chrono::steady_clock::now();double d=0;for(int i=0;i<N;++i)d+=0.75;auto c=std::chrono::steady_clock::now();ps=p;ds=d;std::cout<<"integer paise="<<ps<<" time_us="<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<'\n';std::cout.precision(17);std::cout<<"double="<<ds<<" time_us="<<std::chrono::duration_cast<std::chrono::microseconds>(c-b).count()<<'\n';}
