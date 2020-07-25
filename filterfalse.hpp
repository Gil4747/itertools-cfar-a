#ifndef Filterfalse
#define Filterfalse

#include <iostream>
//#include <iterator>
//#include <functional>
#include <vector>


namespace itertools{

template<typename F,typename T>
class filterfalse{

F Fcontiner;
T& Tcontiner;
typedef typename T::value_type value_type;

public:

 filterfalse(F f, T& container): Fcontiner(f), Tcontiner(container){}
 filterfalse(F f, T&& container): Fcontiner(f), Tcontiner(container){}

class iterator{

typename T::iterator iTstart;
typename T::iterator iTend;
F Fcontiner;

public:



explicit iterator(typename T::iterator s,typename T::iterator e,F fun): iTstart(s),iTend(e),Fcontiner(fun){
     while(iTstart!=iTend && Fcontiner(*iTstart)){
           ++iTstart;
    }
}
iterator(const iterator& other) = default;

iterator& operator=(const iterator& other){
     if(this != &other) {
        this->iTstart = other.iTstart;
        this->iTend = other.iTend;
        this->Fcontiner = other.Fcontiner;
            }
          return *this;
        };

 iterator& operator++(){
  do{
  ++iTstart;
  } while (iTstart != iTend && Fcontiner(*iTstart));
    return *this;
}    

iterator operator ++(int){
   iterator tmp = *this;
      ++(*this);
    return tmp;
    }

bool operator==(const iterator& other) {
    return (iTstart == other.iTstart);
}
bool operator!=(const iterator& other) {
    return (iTstart != other.iTstart);
}

 

value_type operator*(){
    return *iTstart;
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
