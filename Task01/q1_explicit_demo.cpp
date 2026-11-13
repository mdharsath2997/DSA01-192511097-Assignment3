#include <iostream>
#include <string>
struct ImplicitLabel{std::string s;ImplicitLabel(const std::string&x):s(x){}};
struct ExplicitLabel{std::string s;explicit ExplicitLabel(const std::string&x):s(x){}};
void show(ImplicitLabel x){std::cout<<x.s<<'\n';}
int main(){show("implicit conversion accepted");ExplicitLabel x("direct initialization accepted");std::cout<<x.s<<'\n';}
