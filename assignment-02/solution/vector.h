
#include <cstdlib>

namespace cpppc {

  typedef struct {
  	int value;
  } VectorElement;

  typedef VectorElement * VectorIterator;

  class Vector {

  public:
    Vector();

  	Vector(size_t size);

  	~Vector();

  	Vector(const Vector & vec);
    
    Vector & operator=(const Vector & vec);
    
    VectorElement & operator[](int index);
    const VectorElement & operator[](int index) const;
    //const VectorElement & operator[](int index);

    //size_t size();
    //VectorElement * elements();
    //const VectorElement * elements();

    VectorElement * elements(){
      return _elements;
    }

    const VectorElement * elements() const {
      return _elements;
    }

    size_t size() const {
      return _size;
    }

    bool empty() const;

    bool equals(const Vector & v2) const; 

    bool operator==(const Vector & v2) const;
    
    const VectorElement * begin() const;
    VectorElement * begin();
    const VectorElement * end() const;
    VectorElement * end();

    void push_back(VectorElement ele);
    VectorElement pop_back();

    void push_front(VectorElement ele);
    VectorElement pop_front();

    //Vector reverse();
    Vector * reverse();

  private:
    size_t _size;
    VectorElement * _elements = nullptr;
  }; // Class Vector
}