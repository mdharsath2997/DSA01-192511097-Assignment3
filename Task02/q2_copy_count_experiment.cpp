#include <iostream>
#include <string>
class Record{int n;std::string* a;static int copies;public:Record(int x):n(x),a(new std::string[x]){}Record(const Record&o):n(o.n),a(new std::string[n]){for(int i=0;i<n;++i)a[i]=o.a[i];++copies;}~Record(){delete[]a;}void set(int i,std::string s){a[i]=s;}static int count(){return copies;}};int Record::copies=0;void byValue(Record x){}void byReference(const Record&x){}int main(){Record p(2);p.set(0,"A");Record q=p;byValue(p);byReference(p);std::cout<<"Copies="<<Record::count()<<'\n';}
