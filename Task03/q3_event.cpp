#include <iostream>
#include <string>
#include <stdexcept>
class Event{std::string name;int rows,cols;char**seat;public:Event(std::string n,int r,int c):name(n),rows(r),cols(c),seat(nullptr){if(r<0||c<0)throw std::invalid_argument("dimensions");if(r&&c){seat=new char*[r];int i=0;try{for(;i<r;++i)seat[i]=new char[c]{};}catch(...){while(i)delete[]seat[--i];delete[]seat;throw;}}std::cout<<"Construct "<<name<<'\n';}bool book(int r,int c){if(r<0||r>=rows||c<0||c>=cols||seat[r][c]=='X')return false;seat[r][c]='X';return true;}~Event(){int n=0;for(int i=0;i<rows;++i)for(int j=0;j<cols;++j)n+=seat[i][j]=='X';std::cout<<"Summary "<<name<<": "<<n<<'\n';if(seat){for(int i=0;i<rows;++i)delete[]seat[i];delete[]seat;}std::cout<<"Destroy "<<name<<'\n';}};
int main(){{Event a("Stack",2,3);a.book(0,0);}{Event* p=new Event("Heap",3,2);p->book(2,1);delete p;}Event z("ZeroRows",0,5);std::cout<<"End main\n";}
