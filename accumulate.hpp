#include <iostream>
#include<stdio.h>
#include <iterator>
#include <functional>

namespace AccumulateContainer{

template<typename T>
class accumulate{

T container;

public:

accumulate(){}

accumulate(T cont):container(cont){}

accumulate(const accumulate& other){
    if(*this!=other){
  this->container(other->container);
    }
}

class Aiterator{
typename T::iterator start;
typename T::iterator end;
typename T::value_type cur;

public:

Aiterator(typename T::iterator x,typename T::iterator y){
    start=x;
    end=y;
    cur=*x;
    }

Aiterator(const Aiterator& other) : start(other.start),end(other.end),cur(*other.start) {}

Aiterator& operator++(){
    Aiterator temp(start);
    ++start;
    cur=std::accumulate(temp,start,cur);
    return *this;
}

Aiterator operator++(int)
{
Aiterator temp(start);
start++;
cur=std::accumulate(temp,start,cur);
return temp;
}

bool operator==(const Aiterator& other){
    return (*start==*other.start && *end==*other.end && cur==other.cur);
}

bool operator!=(const Aiterator& other){
    return !(*start==*other.start && *end==*other.end && cur==other.cur);
}
auto operator*(){
    return this->cur;
}
};
Aiterator begin(){
    return Aiterator(container.begin(),container.end());
}
Aiterator end(){
     return Aiterator(container.end(),container.end());
}

};

};
