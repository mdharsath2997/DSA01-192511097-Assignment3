#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
class Time{int s;public:explicit Time(int x=0):s(x){}Time&operator++(){++s;return *this;}Time operator++(int){Time old=*this;++s;return old;}bool operator==(const Time&x)const{return s==x.s;}bool operator<(const Time&x)const{return s<x.s;}void print()const{std::cout<<s/3600<<':'<<(s/60)%60<<':'<<s%60;}};
class Playlist{std::vector<std::string>v;public:Playlist(std::initializer_list<std::string>x):v(x){}std::string&operator[](int i){if(i<0||i>=int(v.size()))throw std::out_of_range("playlist index");return v[i];}const std::string&operator[](int i)const{if(i<0||i>=int(v.size()))throw std::out_of_range("playlist index");return v[i];}int size()const{return v.size();}};
int main(){Time t(3599),a=t++,b=++t;std::cout<<"a=";a.print();std::cout<<" b=";b.print();std::cout<<" t=";t.print();std::cout<<'\n';Playlist p{"Intro","Theme","End"};std::cout<<p[1]<<'\n';try{std::cout<<p[-1];}catch(const std::exception&e){std::cout<<e.what()<<'\n';}try{std::cout<<p[p.size()];}catch(const std::exception&e){std::cout<<e.what()<<'\n';}}
