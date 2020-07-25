
#ifndef Accumulate
#define Accumulate
using namespace std;
#include <iostream>
//#include <iterator>
//#include "range.hpp"

namespace itertools{

      typedef struct {
        template<typename K>
        K operator()(K a, K b) const {
            return a+b;
        }
    } Fun;

template<typename T,typename F=Fun>
class accumulate{
typedef typename T::value_type value_type;
T& continer;
F function;

public:

explicit accumulate(T& continer, F func = Fun()) : continer(continer), function(func){}

explicit accumulate(T&& continer, F func = Fun()) : continer(continer), function(func){}

class iterator{

private:

typename T::iterator start;
typename T::iterator end;
typename T::value_type cur;
F func;

public:

iterator(typename T::iterator start,typename T::iterator end,F func):start(start), end(end), func(func){
    if(start!=end)
    cur=*start;
    
}

iterator(const iterator& other){this=other;}

const iterator& operator=(const iterator& o){
    if(this!=&o){
        this->start=o.start;
       this->end=o.end;
        this->cur=o.cur;
        this->func=o.func;
    }
    return *this;
}

iterator& operator++(){
     ++start;
    if(start!=end){
    cur=func(cur,*start);
    }
    return *this;
}

iterator operator++(int){
iterator temp=*this;
++(*this);
return temp;
}

bool operator==(const iterator& other){
    return (start==other.start);
}

bool operator!=(const iterator& other){
    return !(start==other.start);
}
auto operator*(){
    return this->cur;
}

};

iterator begin(){
    return iterator(continer.begin(),continer.end(),function);
}
iterator end(){
     return iterator(continer.end(),continer.end(),function);
}

};

}

#endif
