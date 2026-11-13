#include <iostream>
int main(){for(auto d:{std::pair<int,int>{10,20},{100,200},{1000,2000}}){long long bytes=1LL*d.first*d.second*sizeof(char)+1LL*d.first*sizeof(char*);std::cout<<d.first<<"x"<<d.second<<": "<<bytes<<" bytes including row pointers\n";}}
