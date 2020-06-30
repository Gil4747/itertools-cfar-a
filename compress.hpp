#ifndef Compress
#define Compress

#include <iterator>
#include <vector>

namespace itertools{

template<typename T,typename B>
class compress{

 T Tcontiner;
 B& Bcontiner;

compress(T tc,B bc): Tcontiner(tc),Bcontiner(bc){}

class iterator{

friend class compress;

typename T::iterator Sc;
typename T::iterator Ec;
typename B::iterator Sb;
typename B::iterator Eb;
typename T::value_type cur;

public:

explicit iterator(typename T::iterator Cs,typename T::iterator Ce,typename B::iterator Bs,typename B::iterator Be){
    Sc=Cs;
    Ec=Ce;
    Sb=Bs;
    Eb=Be;
}

iterator& operator=(const iterator& o){
    if(this!=&o){
        Sc=o.Sc;
        Sb=o.Sb;
        Ec=o.Ec;
        Eb=o.Eb;
    }
    return *this;
}

bool operator==(const iterator& o){
    return (Sc==o.Sc && Ec==o.Ec && Sb==o.Sb && Eb==o.Eb);
}
bool operator!=(const iterator& o){
    return !(Sc==o.Sc && Ec==o.Ec && Sb==o.Sb && Eb==o.Eb);
}
auto operator*(){
    return cur;
}
iterator& operator++(){
typename B::iterator temp2=Sb;
typename T::iterator temp=Sc;
while(*temp2!=true && Sc!=Ec && Sb!=Eb){
temp2=Sb;
temp=Sc;
if(Sc!=Ec)
    ++Sc;
if(Sb!=Eb)
    ++Sb;
}
if(*temp2==true)
   cur=*temp;
return *this;
}

iterator operator++(int){
iterator temp=*this;
++(*this);
return temp;
}

};

iterator& begin(){
    return iterator(Tcontiner.begin(),Tcontiner.end(),Bcontiner.begin(),Bcontiner.end());
}
iterator& end(){
    return iterator(Tcontiner.end(),Tcontiner.end(),Bcontiner.end(),Bcontiner.end());
}
};
}
#endif