
#include "vector.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

namespace cpppc {
  
  Vector::Vector(){
    _size = 0;
    _elements = nullptr;
  }


  Vector::Vector(size_t size) : _size(size)
  {
    if(size>0){
      _elements = new VectorElement[_size];
      for(size_t idx=0;idx<_size;idx++){
        _elements[idx]= VectorElement {0};  // TODO
      }
    }
  }

  Vector::~Vector(){
    if(_elements != nullptr){
      delete[] _elements;
    }
  }

  Vector::Vector(const Vector & vec)
  : _size(vec.size())
  {
    _elements = new VectorElement[_size];
    for(size_t idx = 0; idx<_size; idx++){
      //_elements[idx]=vec.elements()[idx]
      _elements[idx]=vec._elements[idx];
    }
  }

  Vector & Vector::operator=(const Vector & v_rhs){
    if(this != &v_rhs){
      _size = v_rhs.size();
      
      if (nullptr != _elements) {
        delete[] _elements;
      }
      if (_size > 0) {
        _elements = new VectorElement[_size];
        for (size_t idx = 0; idx < _size; idx++) {
          //_elements[idx] = v_rhs.elements()[idx];
          _elements[idx] = v_rhs._elements[idx];
        }
      }
    }
    return *this;
  }



  const VectorElement * Vector::begin() const{
    return _elements;
  }

  VectorElement * Vector::begin(){
    return _elements;
  }

  const VectorElement * Vector::end() const{
    // return begin()+_size;
    return _elements+_size;
  }

  
  VectorElement * Vector::end() {
    return begin()+_size;
  }
  

  bool Vector::equals(const Vector & v2) const
  {

    if(_size != v2.size()){
      return false;
    }
    for(size_t idx = 0; idx < _size; idx++){
      if(_elements[idx].value != v2._elements[idx].value){
        return false;
      }
    }
    return true;
  }



  bool Vector::empty() const{
    //return static_cast<int>(v.size())==0;
    return _size == 0;
  }
  
  bool Vector::operator==(const Vector & v2) const
  {
    if( _size != v2.size() ){
      return false;
    }
    for(size_t idx = 0; idx < _size; idx++){
      if( !(_elements[idx].value == v2._elements[idx].value) ){
        return false;
      }
    }
    return true;
  }

  /*
  std::ostream & Vector::operator<<(
    std::ostream & os,
    const cpppc::VectorElement & ele)
  {
    std::ostringstream ss;
    ss << "VectorElement { value(" << ele.value << ") }" << std::endl;
    
    return operator<<(os, ss.str());
  }

  std::ostream & Vector::operator<<(
    std::ostream & os,
    const cpppc::Vector & vec)
  {
  	std::ostringstream ss;
  	ss << "Vector { " << std::endl
  	   << "      size("       << vec.size()     << "),"  << std::endl
  	   << "      elements @	" << vec.elements() << " ("  << std::endl;
  	for(size_t idx = 0;idx<vec.size();idx++){
  	  ss << "        " << vec[idx];
  	  if(idx < vec.size()-1) {
  	  	ss << ",";
  	  }
  	  ss << std::endl;
  	}
  	ss << "   )";
  	return operator<<(os, ss.str());
  }
  */
  // vector.at()
  // const VectorElement & Vector::operator[](.) const { would prevent assign!
  VectorElement & Vector::operator[](int index) {
    return _elements[index];
  }

  const VectorElement & Vector::operator[](int index) const {
    return _elements[index];
  } 

  // void Vector::operator[](size_t index, VectorElement & ele) {
  //   _elements[index]=
  // }

  //const VectorElement & Vector::at(size_t index);

  void Vector::push_back(VectorElement ele){

    /*
    v->data = (int *)realloc(v->data, (v->size+1)*sizeof(int));
    v->data[v->size] = value;
    v->size=v->size+1;
    */

    //Vector * temp = new Vector{_size+1};
    //Vector

    _elements = (VectorElement *)realloc(_elements, (_size+1)*sizeof(VectorElement));
    _elements[_size]=ele; 
    //for(size_t idx = 0; idx<_size; idx++){
      //temp._elements[idx]=_elements[idx];
      //temp[idx]=_elements[idx];
    //}
    //temp[_size]=ele;
    
    //_old = _elements;
    //_elements = temp.elements();
    //free(_elements);
    _size += 1;
  }

  VectorElement Vector::pop_back(){
    VectorElement ret = _elements[_size-1];
    /*
      int ret = v->data[v->size-1];
      v->data = (int *)realloc(v->data, (v->size-1)*sizeof(int));
      v->size = v->size-1;
      return ret;
    */
    //Vector temp = Vector{_size-1};
    //for(size_t idx = 0; idx < _size-1; idx++){
    //  temp[idx]=_elements[idx];
    //}
    //this = temp; nouhh
    //~temp; nouh ! -> scope ?! temp should be deleted if out of scope
    
    _elements = (VectorElement *)realloc(_elements, (_size-1)*sizeof(VectorElement));
    _size = _size-1;
    

    //_elements = temp.elements();
    //_size = temp.size();
    return ret;
  }

  void Vector::push_front(VectorElement ele){
    
    /*
      v->data = (int *)realloc(v->data, (v->size+1)*sizeof(int));
  for(int idx=v->size;idx>0;idx--){
    v->data[idx] = v->data[idx-1];
  }
  v->data[0] = value;
  v->size = v->size+1;
    */
    // Vector * temp = new Vector{_size+1};
    //Vector temp = Vector{_size+1};
    _elements = (VectorElement *)realloc(_elements, (_size+1)*sizeof(VectorElement));
    for(size_t idx=_size; idx>0; idx--){
      _elements[idx] = _elements[idx-1];
    }
    _elements[0] = ele;
    _size = _size+1;
    //_elements = temp.elements();
    //_size = temp.size();
    // ~temp;
    //this = temp;
  }

  VectorElement Vector::pop_front(){
    /*
      int ret = v->data[0];
  for(int idx=1;idx<v->size-1;idx++){
    v->data[idx-1] = v->data[idx];
  }
  v->data = (int *)realloc(v->data, (v->size-1)*sizeof(int));
  v->size = v->size-1;
  return ret;
    */
    //Vector temp = Vector{_size-1};
    
    VectorElement ret = _elements[0];
    for(size_t idx=0; idx<_size; idx++){
      _elements[idx] = _elements[idx+1];
    }
    //VectorElement ret = _elements[0];
    //_elements = temp.elements();
    _elements = (VectorElement *)realloc(_elements, (_size-1)*sizeof(VectorElement));
    _size = _size-1;

    //_size = temp.size();
    
    return ret;
  }

  Vector * Vector::reverse(){
    Vector * temp = new Vector{_size};
    //Vector temp = Vector{_size};

    for(size_t idx = _size-1;idx>=0;idx--){
      temp->push_back(_elements[idx]);
    }
    return temp;
  }

}  // namespace cpppc