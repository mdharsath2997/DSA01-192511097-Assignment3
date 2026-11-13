#include <iostream>
#include <stdexcept>
#include <string>
class Book{std::string title,author;int copies;static int valid(int n){if(n<0)throw std::invalid_argument("negative copies");return n;}
public: Book():Book("Untitled",0,"Unknown"){} explicit Book(const std::string&t):Book(t,1,"Unknown"){} Book(const std::string&t,int n):Book(t,n,"Unknown"){} Book(const std::string&t,int n,const std::string&a):title(t),author(a),copies(valid(n)){} void print()const{std::cout<<title<<" | "<<copies<<" | "<<author<<'\n';}};
struct Reorder{int second;int first;Reorder():first(10),second(first+1){}};
int main(){Book a,b("Donated"),c("Dune",4),d("Clean Code",3,"Martin");a.print();b.print();c.print();d.print();try{Book x("Bad",-1);}catch(const std::exception&e){std::cout<<"Rejected: "<<e.what()<<'\n';}Reorder r;std::cout<<r.second<<' '<<r.first<<'\n';}
