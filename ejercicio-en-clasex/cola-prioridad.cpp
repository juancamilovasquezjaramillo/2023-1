#include "cola.h"

Cola::Cola(){
}

Elemento Cola::front(){
  //Elemento ans = vec[0]; 
  Elemento ans = vec[vec.size() - 1];
   return ans;
}

void Cola::enqueue(Elemento e){
  //vec.push_back(e);
  vec.insert(vec.begin(), e);
}

void Cola::deque(){
  //vec.erase(vec.begin());
  vec.pop_back();
}

bool Cola::vaciaCola(){
  bool ans;
  if(vec.empty())
     ans = true;
  else
     ans = false;
  return ans;
}