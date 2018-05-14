
#include "measurements.h"

namespace cpppc {

  typedef Measurements<T> self_t; 
  

  double self_t::mean() const{
    return 2.0;
  }

  double self_t::variance() const{
    return 2.0;
  }

  double self_t::sigma() const{
    return 2.0;
  }

}