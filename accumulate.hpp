#ifndef Accumulate
#define Accumulate

#include <iterator>
#include "range.hpp"

namespace itertools{

      typedef struct {
        template<typename T>
        T operator()(T a, T b) const {
            return a+b;
        }
    } Fun;

template<typename T,typename F=Fun>
class accumulate{

typedef typename T::value_type value_type;
T continer;
F function;


public:

explicit accumulate(T cont,F func=Fun()):continer(cont),function(func){}

accumulate(const accumulate& other){
    if(*this!=other){
  this->continer(other->continer);
    }
}

class iterator{

friend class accumulate;

private:

typename T::iterator start;
typename T::iterator end;
typename T::value_type cur;
F func;

public:
iterator(const iterator& other){cur=other.cur;}
    

iterator& operator=(const iterator& o){
    if(this!=&o){
        start=o.start;
        end=o.end;
        cur=o.cur;
    }
    return *this;
}


iterator(typename T::iterator x,typename T::iterator y){
    start=x;
    end=y;
    cur=*x;
    }

iterator& operator++(){
    iterator temp(start);
    if(start!=end){
    ++start;
    }
    cur=func(cur,*start);
    return *this;
}

iterator operator++(int){
iterator temp(start,end);
if(start!=end){
start++;
cur=func(cur,*start);
}
return temp;
}

bool operator==(const iterator& other){
    return (*start==*other.start && *end==*other.end && cur==other.cur);
}

bool operator!=(const iterator& other){
    return !(*start==*other.start && *end==*other.end && cur==other.cur);
}
auto operator*(){
    return this->cur;
}

};

iterator begin(){
    return iterator(continer.begin(),continer.end());
}
iterator end(){
     return iterator(continer.end(),continer.end());
}

};

};

#endif