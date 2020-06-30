#ifndef Filterfalse
#define Filterfalse

#include <iostream>
#include <iterator>
#include <functional>
#include <vector>


namespace itertools{

template<typename F,typename T>
class filterfalse{

typedef typename T::value_type value_type;
F Fcontiner;
T& Tcontiner;

public:

 filterfalse(F f, T& container): Fcontiner(f), Tcontiner(container){}
 filterfalse(F f, T&& container): Fcontiner(f), Tcontiner(container){}

class iterator{

typename T::iterator iTstart;
typename T::iterator iTend;
F Fcontiner;

public:

iterator(const iterator& other) = default;

iterator(typename T::iterator s,typename T::iterator e,F fun): iTstart(s),iTend(e),Fcontiner(fun){
     while(iTstart!=iTend && !Fcontiner(*iTstart)){
           ++iTstart;
    }
}

iterator operator==(const iterator& other) const{
    return (iTstart==other.iTstart);
}
iterator operator!=(const iterator& other) const{
    return !(iTstart==other.iTstart);
}

iterator& operator=(const iterator& other){
     if(this != &other) {
        this->iTstart = other.iTstart;
        this->iTend = other.iTend;
        this->Fcontiner = other.Fcontiner;
            }
          return *this;
        }

auto operator*(){
    return *iTstart;
}

iterator& operator++(){

    while(iTstart!=iTend && !Fcontiner(*iTstart)){
           ++iTstart;
    }
    return *this;
}

 iterator operator ++(int){
         iterator tmp = *this;
            ++(*this);
            return tmp;
            }

};

iterator begin(){
    return iterator(Tcontiner.begin(),Tcontiner.end(),Fcontiner);
}
iterator end(){
     return iterator(Tcontiner.end(),Tcontiner.end(),Fcontiner);
}

};
 
}
#endif