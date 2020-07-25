#ifndef Compress
#define Compress

#include <iostream>
#include <vector>

namespace itertools{

template<typename T2,typename B>
class compress{

 T2& Tcontiner;
 B& Bcontiner;
typedef typename T2::value_type value_type;

public:
compress(T2& tc,B& bc): Tcontiner(tc),Bcontiner(bc){}
compress(T2&& tc, B&& bc): Tcontiner(tc),Bcontiner(bc){}
compress(T2&& tc, B& bc): Tcontiner(tc),Bcontiner(bc){}
compress(T2& tc, B&& bc): Tcontiner(tc),Bcontiner(bc){}


class iterator{

friend class compress;

typename T2::iterator Sc;
typename T2::iterator Ec;
typename B::iterator Sb;
//typename B::iterator Eb;
//typename T2::value_type cur;

public:

explicit iterator(typename T2::iterator Cs,typename T2::iterator Ce,typename B::iterator Bs):Sc(Cs), Ec(Ce), Sb(Bs) {
     while (Sc != Ec && !(*Sb)){
        ++Sc;
        ++Sb;
   }
}
 iterator(const iterator& other) = default;

iterator& operator=(const iterator& o){
    if(this!=&o){
      this->Sc=o.Sc;
      this->Ec=o.Ec;
        this->Sb=o.Sb;
    }
    return *this;
};

iterator& operator++(){
do{
  ++Sc;
   ++Sb;
    } while (Sc != Ec && !(*Sb));
     return *this;
}

iterator operator++(int){
iterator temp=*this;
++(*this);
return temp;
}
bool operator==(const iterator& o) {
    return (Sc==o.Sc && Sb==o.Sb);
}
bool operator!=(const iterator& o) {
    return !(Sc==o.Sc && Sb==o.Sb);
}
value_type operator*(){
    return *Sc;
}


};

iterator begin(){
    return iterator(Tcontiner.begin(),Tcontiner.end(),Bcontiner.begin());
}
iterator end(){
    return iterator(Tcontiner.end(),Tcontiner.end(),Bcontiner.end());
}
};
}
#endif
