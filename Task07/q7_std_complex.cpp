#include <complex>
#include <iostream>
int main(){using C=std::complex<double>;double w=2*3.141592653589793*50;C r(10,0),l(0,w*.01),c(0,-1/(w*.001));C s=r+l+c,p=r*l/(r+l);std::cout<<s<<" | "<<std::abs(s)<<'\n'<<p<<" | "<<std::abs(p)<<'\n';}