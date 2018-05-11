#ifndef CPPPC__A03__MEASUREMENTS_H__INCLUDED
#define CPPPC__A03__MEASUREMENTS_H__INCLUDED

#include <vector>
#include <cmath>

namespace cpppc {

template <typename T>
class Measurements
{

  typedef Measurements<T>                                   self_t;
  typedef T                                                value_t;

  typedef       T &                                      reference;
  typedef const T &                                const_reference;
  typedef typename std::vector<T>::iterator               iterator;
  typedef typename std::vector<T>::const_iterator   const_iterator;

public:
  Measurements(){

  }

  Measurements(const self_t & rhs){

  }

  ~Measurements() = default;

private:

  std::vector<T> _values;

};

} // namespace cpppc

#endif // CPPPC__A03__MEASUREMENTS_H__INCLUDED