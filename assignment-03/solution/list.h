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

  template<typename ValueT, ValueT default_value> class list;
  // list<int32_t, -1>
  template <
    typename ValueT,
    ValueT   default_value = ValueT()>
  class list {
    typedef list<ValueT, default_value> self_t;
  public:
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
    public:
       iterator() = delete;

       iterator(const list_node_t & ln)
       : _list_node(ln)
       { }

       iterator & operator++() {
          _list_node = _list_node.next;
          return *this;
       }

       iterator operator=(const iterator & rhs){
         if(!(this == &rhs)){
          _list_node = rhs._list_node;
         }
         return *this;
       }

       iterator operator++(int) {
          iterator old = *this;
          _list_node = _list_node.next;
          return old;
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

    struct list_node {
       list_node * next;
       ValueT      value;
    };
    
  public:
    list()
    : _begin(iterator(*this))
    , _end(iterator(*this))
    { }

    // list<uint32_t>(list<int32_t>()) says 'nouh'
    list(const self_t & other)             = default;
    self_t & operator=(const self_t & rhs) = default;

    // list<int> l;
    // l_begin = l.begin();
    // ++l_begin;
    iterator begin()  { _begin; }
    // list<T> l;
    // *l.end();
    iterator end()    { _end; }

    void push_front(ValueT value)
    {
      list_node * ln = new list_node();
      ln->next = &_head;
      ln->value = value;
      _head = *ln;
    }

    ValueT pop_front(){
      list_node * update = _head.next;
      ValueT ret = _head.value;
      delete _head;
      _head = *update;
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
    }
    
    
  private:
    // same as = { }
    list_node _head        = { nullptr, default_value };
    static list_node _tail = { nullptr, default_value };

    // self_t * this

    iterator  _begin = *this;
    iterator  _end;
  };

}