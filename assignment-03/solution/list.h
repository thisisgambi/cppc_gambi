#include <cstdlib>
//#include <iterator>

/*
// it++; -> old position
iterator operator++(int) {
  iterator old = *this;
  --_pos;
  return old;
}

// ++it; -> new position
iterator & operator++() {
  _pos = 0;
  return *this;
}

*/


namespace cpppc {

 // template<typename ValueT, ValueT default_value> class list;
  // list<int32_t, -1>
  template <
    typename ValueT,
    ValueT   default_value = ValueT()>
  class list {
    typedef list<ValueT, default_value> self_t;
  public:
    
    struct list_node {
       list_node * next;
       ValueT      value;
    };

    // list<T>::iterator
    class iterator {
       typedef typename
         //list<ValueT, default_value>
         list::self_t
         list_t;
       typedef typename
         list_t::list_node
         list_node_t;
       typedef typename
         list_t::iterator
         self_t;
       typedef int 
         difference_type;
       typedef 
         ValueT 
         value_type;
       typedef 
         ValueT *
         pointer;
       typedef 
         ValueT &
         reference;
       typedef typename
         std::forward_iterator_tag
         iterator_category;
 
    public:
       iterator() = delete;
/*
       iterator(const list_node_t & ln)
       //: _list_node(ln)
       { 
         _list_node = new list_node();
         _list_node->next = ln.next;
         _list_node->value = ln.value;
       }
*/
       iterator(list_node_t * ln)
       //: _list_node(ln)
       {
        _list_node = ln;
       }

       iterator & operator++() {
          _list_node = _list_node.next;
          return *this;
       }

       iterator operator++(int) {
          iterator old = *this;
          _list_node = _list_node->next;
          return old;
       }

       iterator operator=(const iterator & rhs){
         if(!(this == &rhs)){
          _list_node = rhs._list_node;
         }
         return *this;
       }
    

       // int * ptr;
       //
       // ptr[3]     = 4;
       // *(ptr + 3) = 4;
       //
       // auto it = list.begin();
       // *it = 3;
       //
       // list<X> l;
       // auto it  =  l.begin();
       // auto val = *it;
       const ValueT & operator*() const {
         return _list_node->value;
       }

       ValueT & operator*() {
         return _list_node->value;
       }

       bool operator==(const self_t & rhs) {
         return  (this == &rhs || // identity
                   // ?? *_list_node == rhs._list_node ??
                   ( _list_node == rhs._list_node &&
                     _list_node->value == rhs._list_node->value));
       }

    private:
      //list_node_t * _head_node;
       list_node_t * _list_node;
    };

    
    
  public:
    list()
    : _begin( _head )
    , _end( _head )
    { }

    // list<uint32_t>(list<int32_t>()) says 'nouh'
    list(const self_t & other)             = default;


    ~list(){
      while(!(_head == nullptr )){
        pop_front();
      }
      //clear()
      delete _head;
    }
    
    self_t & operator=(const self_t & rhs){  // = default ?
      if(_size!=0){
        std::cout << "operator= - size > 0";
        while(_head->next != nullptr){
          list_node * temp = _head->next;
          delete _head;
          _head = temp;
          delete temp;
          
          // why not use pop_front()?
          //pop_front();
        }
      }
      _head        = rhs._head;
      _head->value = *(rhs.begin());
      _head->next  = rhs._head->next;
      _size = rhs.size();
      return *this;
    }


    bool operator==(const self_t & other){
      if(!(this == &other)){ 

        if(!(size() == other.size())){
          return false;
        }
        if(_size == 0){
         return true;
        } 
        iterator pos1 = begin();
        iterator pos2 = other.begin();
        while(!(pos1 == end() )
          //&& !(pos2 == end() ))
          ){
          if(!(pos1 == pos2)){ 
            return false;
          }
          pos1++;
          pos2++;
        }
      }
      // are both iterators at the end ?
      //if(  pos1 == end() 
      //  && pos2 == end())
      //{

        return true;
      //}
      //return false;
    }

    // list<int> l;
    // l_begin = l.begin();
    // ++l_begin;
    iterator begin()  { return _begin; }
    iterator begin() const {return _begin;}
    // list<T> l;
    // *l.end();
    iterator end()    const { return iterator(nullptr); }


    void push_front(ValueT value)
    {
      list_node * ln = new list_node();
      ln->next = _head;
      ln->value = value;
      _head = ln;
      _size++;
    }

    ValueT pop_front(){
      list_node * update = _head->next;
      ValueT ret = _head->value;
      delete _head;
      _head = update;
      _size--;
      return ret;
    }
    
    void insert(iterator & pos, ValueT value)
    {
      list_node * ln = new list_node();
      // only if pos is end of list:
      //    ln->next = nullptr;
      ln->next = pos._list_node->next;
      ln->value = value;
      pos._list_node.next = ln;
      _size++;
    }
    
    size_t size() const {
      return _size;
    }
    
  private:
    // same as = { }
    list_node * _head = new list_node{ nullptr, default_value };
    //static constexpr list_node _tail = { nullptr, default_value };

    // to maintain O(1) for size
    // otherwise we to navigate trough all nodes
    size_t _size = 0;

    // self_t * this
    // iterator  _begin = *this;
    iterator  _begin = iterator{_head};
    iterator  _end;
  };

}