#ifndef CPPPC__S03__SPARSE_ARRAY_H__INCLUDED
#define CPPPC__S03__SPARSE_ARRAY_H__INCLUDED

// Might come in handy:
#include <unordered_map>


namespace cpppc {

  namespace detail {

    template <class SparseArrayT>
    class sparse_array_iterator
    {
      // Just a suggestion
    };

    template <class SparseArrayT>
    class sparse_array_proxy_ref
    {
      // Just a suggestion
    };

  } // namespace detail


  template <class T, std::size_t N>
  class sparse_array
  {
    // Just a suggestion:
    using value_type = T;

    typedef sparse_array<T, N>                      self_t;
    typedef detail::sparse_array_proxy_ref<self_t>  proxy_reference;
    typedef int                                     index_t;

  public:

    typedef detail::sparse_array_iterator<self_t>   iterator;
    typedef index_t                                 difference_type;
    
    //value_type  T
    using size_type                 = std::size_t
    using difference_type           = std::ptrdiff_t
    
    using reference                 = sparse_array_proxy_ref<self_t>;
    using const_reference           = sparse_array_proxy_ref<const self_t>;
    
    using pointer                   = value_type*;
    using const_pointer             = const value_type*;
    
    using iterator                  = detail::sparse_array_iterator<self_t>;
    using const_iterator            = detail::sparse_array_iterator<const self_t>;
    using reverse_iterator          = std::reverse_iterator<iterator>
    using const_reverse_iterator    = std::reverse_iterator<const_iterator>


  public:
    class proxy_reference {
      using sparse_array_t = sparse_array<T,N>;
      using self_t         = proxy_reference;

    public:
      proxy_reference() = delete;
      proxy_reference(sparse_array_t & sa, index_t offset)
      : _sa(sa), _index(offset)
      { }

      proxy_reference & operator=(const & T value) {

        return *this;
      }
    private:
      //sparse_array_t * _sa;
      sparse_array_t & _sa;
      index_t          _index;
    };

    class iterator {
    public:
      iterator() = default;
      iterator(sparse_array_t & sa, index_t offset)
      : _sa(&sa), _index(offset)
      {

      }

      proxy_reference operator*(){
        return (*_sa)[_index];
      }

    private:
      sparse_array_t * _sa;
      index_t          _index;
    };


  public:
    friend iterator;

  public:
    sparse_array() = default;
    ~sparse_array() = default;
    sparse_array(const self_t & other) = default;
    sparse_array(self_t && other) = default;
    
    self_t & operator=(const self_t & other) = default;

    self_t & operator=(self_t && other)= default;

    bool operator==(const self_t & rhs) const {
      return (this == &rhs) // identity
            || (_default == rhs._default
              && true // TODO
              );
    }

    bool operator!=(const self_t & rhs) const {
      return not (*this == rhs);
    }

    reference operator[](in index) {
      return reference(*this, index);
    }

    const_reference operator[](in index) const {
      return reference(*this, index);
    }

    const value_type operator[](int index) const{
 
    }

    value_type & operator[](int index){
      if(_map[index] == default_value){
        _map[index];
      }
    }

    T operator[](int offset) const{
      auto it_match = _map.find(offset);
      if(it_match == _map.end()){
        return _default;
      }
      return *it_match;
    }

    iterator begin(){
      return iterator(*this, 0);
    }

    iterator end(){
      return iterator(*this, N);
    }

    std::size_t size() const noexcept {
      return N;
    }

  private:
    T                                   _default_value;
    std::size_t                         N;
    std::unordered_map<int, value_type> _map;

  };

} // namespace cpppc

#endif // CPPPC__S03__SPARSE_ARRAY_H__INCLUDED