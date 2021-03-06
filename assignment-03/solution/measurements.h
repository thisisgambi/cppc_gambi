#ifndef CPPPC__A03__MEASUREMENTS_H__INCLUDED
#define CPPPC__A03__MEASUREMENTS_H__INCLUDED

#include <vector>
#include <cmath>
#include <numeric>
#include <cstdlib>

namespace cpppc {

template <typename T>
class Measurements
{

  typedef Measurements<T>                                   self_t;
  typedef T                                                value_t;
  typedef size_t                                         size_type;

  typedef       T &                                      reference;
  typedef const T &                                const_reference;
  typedef typename std::vector<T>::iterator               iterator;
  typedef typename std::vector<T>::const_iterator   const_iterator;

public:
  Measurements(){
    std::vector<T> _values {};
    //std::vector<T> * v = new std::vector<T>();
    //_values = *v;
  }

  Measurements(const self_t & rhs){
    _values = rhs._values;
  }

  ~Measurements() = default;

  iterator begin(){
    return _values.begin();
  }

  iterator end(){
    return _values.end();
  }

  template <class IterT>
  void insert(IterT range_start, IterT range_end){
    _values.insert(_values.end(), range_start, range_end);
  }

  void insert(const value_t & val){
    _values.push_back(val);
  }

  size_t size(){
    return _values.size();
  }

  value_t median() const{
    //ret = std::static_cast<self_t>(_values.size()/2);
    //sort in ascending order:
    std::vector<value_t> _values_tmp {_values};

    _values_tmp.sort(_values_tmp.begin(), _values_tmp.end());
    //_values_tmp.sort()
    /*const size_type & div = static_cast<size_type>(2);
    size_type mod = modulus(_values.size(), div);

    size_type mid = _values.size()/2;
    
    iterator it = _values.begin();
    // if size() even: 
    value_t ret = static_cast<value_t>(0);
    if(mod == 0){ // size() even
      // direct it to middle
      for(int idx=1; idx<mid;idx++){
        it++;
      }
      value_t val1 = *it;
      it++;
      value_t val2 = *it;
      ret = static_cast<value_t>((val1+val2)/2);
    } else { //size() odd
      for(int idx=1; idx<mid;idx++){
        it++;
      }
      ret = *it; 
    }*/

    return _values_tmp.at(_values_tmp.size());
  }

  double mean() const{
    T sum = std::accumulate(
        _values.begin()
      , _values.end()
      , 0);
    return sum/_values.size();
  }

  double variance() const{
    double mn = mean();
    auto sum = 0;
    for(int idx=0;idx<_values.size();idx++)
    {
      sum += (_values.at(idx)-mn)^2;
    }
    return sum/_values.size();
  }

  double sigma() const{
    return std::sqrt(variance());
  }

private:

  std::vector<T> _values;

};

} // namespace cpppc

#endif // CPPPC__A03__MEASUREMENTS_H__INCLUDED