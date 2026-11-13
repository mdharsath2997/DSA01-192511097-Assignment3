#include <chrono>
#include <iostream>
#include <string>
volatile std::size_t sink=0;
int main(){constexpr int N=100000;auto a=std::chrono::steady_clock::now();std::string s;for(int i=0;i<N;++i)s+='x';auto b=std::chrono::steady_clock::now();sink=s.size();std::cout<<"std::string length="<<sink<<" elapsed_us="<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<'\n';auto c=std::chrono::steady_clock::now();char*p=new char[N+1];for(int i=0;i<N;++i)p[i]='x';p[N]='\0';auto d=std::chrono::steady_clock::now();sink=N;delete[]p;std::cout<<"preallocated buffer length="<<sink<<" elapsed_us="<<std::chrono::duration_cast<std::chrono::microseconds>(d-c).count()<<'\n';}
