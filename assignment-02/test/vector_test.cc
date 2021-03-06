
/* ------------------------------------------------------------------------ *
 *                       DO NOT MODIFIY THIS FILE                           *
 * -------------------------------------------------------------------------*/

#include "vector_test.h"

#include <solution/vector.h>
#include <gtest/gtest.h>

using cpppc::VectorElement;
using cpppc::VectorIterator;
using cpppc::Vector;

TEST_F(VectorTest, StandardConcept)
{
  LOG_MESSAGE("VectorTest.StandardConcept: vector__new");
  
  // Vector v1 {0};

  Vector * vec1 = new Vector(0);
  Vector * vec2 = new Vector(0);
  
  Vector v1 = *vec1;
  Vector v2 = *vec2;

  LOG_MESSAGE("VectorTest.StandardConcept: vector__equals");
  //ASSERT_EQ(true, v1.equals(v1, v2));
  //ASSERT_EQ(true, v1.equals(v1, v2));
  ASSERT_EQ(true, v1==v2);

  //VectorElement vel1
  //vel1.value = 12;
  VectorElement vel1 = VectorElement {12};

  VectorElement vel2 = VectorElement {34};
  v1.push_back(vel1);
  v1.push_back(vel2);

  //ASSERT_EQ(0, v1.equals(v1, v2));
  ASSERT_EQ(false, v1==v2);

  LOG_MESSAGE("VectorTest.StandardConcept: vector__assign");
  v2=v1;

  //ASSERT_EQ(1, v1.equals(v1, v2));
  ASSERT_EQ(1, v1==v2);
  ASSERT_EQ(true, v1==v2);

  LOG_MESSAGE("VectorTest.StandardConcept: vector__copy");
  //Vector v3 = Vector(v1);
  Vector * vec3 = new Vector(v1);
  Vector v3 = *vec3;

  //ASSERT_EQ(1, v1.equals(v1, v3));
  ASSERT_EQ(1, v1==v3);
  //ASSERT_EQ(0, v1==v3);

  
  delete vec1;
  delete vec2;
  delete vec3;

}


TEST_F(VectorTest, VectorConcept)
{
  LOG_MESSAGE("VectorTest.VectorConcept: vector__new");
  //C-Style: Vector * v = vector__new();
  //Vector * vec = new Vector();
  Vector v {};

  ASSERT_EQ(0,  v.size());
  ASSERT_EQ(1,  v.empty());

  LOG_MESSAGE("VectorTest.VectorConcept: vector__begin, vector__end");
  ASSERT_EQ(v.begin(), v.end());
  ASSERT_EQ(v.end(), v.begin() + v.size());

  LOG_MESSAGE("VectorTest.VectorConcept: vector__push_back(56)");
  VectorElement el1 = VectorElement {56};
  v.push_back(el1);
  LOG_MESSAGE("VectorTest.VectorConcept: vector__push_back(78)");
  VectorElement el2 = VectorElement {78};
  v.push_back(el2);
  LOG_MESSAGE("VectorTest.VectorConcept: vector__push_back(90)");
  VectorElement el3 = VectorElement {90};
  v.push_back(el3);

  ASSERT_EQ(v.end(), v.begin() + v.size());
  
  LOG_MESSAGE("VectorTest.VectorConcept: vector__at");
  ASSERT_EQ(3,  v.size());
  ASSERT_EQ(false,  v.empty());
  ASSERT_EQ(56, v[0].value);
  ASSERT_EQ(78, v[1].value);
  ASSERT_EQ(90, v[2].value);

  for (int i = 0; i < v.size(); i++) {
    LOG_MESSAGE("VectorTest.VectorConcept: v[%d] : %d",
                i, v[i].value);
  }
  

  LOG_MESSAGE("VectorTest.VectorConcept: vector__push_front(34)");
  VectorElement el4 = VectorElement {34};
  v.push_front(el4);
  LOG_MESSAGE("VectorTest.VectorConcept: vector__push_front(12)");
  VectorElement el5 = VectorElement {12};
  v.push_front(el5);

  for (int i = 0; i < v.size(); i++) {
    LOG_MESSAGE("VectorTest.VectorConcept: v[%d] : %d",
                i, v[i].value);
  }

  LOG_MESSAGE("VectorTest.VectorConcept: vector__at");
  ASSERT_EQ(5,  v.size());
  ASSERT_EQ(false,  v.empty());
  ASSERT_EQ(12, v[0].value);
  ASSERT_EQ(34, v[1].value);
  ASSERT_EQ(90, v[4].value);

  LOG_MESSAGE("VectorTest.VectorConcept: vector__copy");
  //Vector * veccopy = new Vector(v);
  //Vector vcopy = *veccopy;

  Vector vcopy {v};

  LOG_MESSAGE("VectorTest.VectorConcept: vector__begin, vector__end");
  VectorIterator viter = v.begin();
  VectorIterator vend  = v.end();

  for (; viter != vend; ++viter) {
    (*viter).value += 100;
  }

  LOG_MESSAGE("VectorTest.VectorConcept: vector__at");
  for (int i = 0; i < vcopy.size(); i++) {
    ASSERT_EQ(v[i].value, vcopy[i].value + 100);
  }

  LOG_MESSAGE("VectorTest.VectorConcept: vector__assign(v_empty)");
  //Vector * vec_empty = new Vector();
  Vector v_empty {}; 
  v=v_empty;

  ASSERT_EQ(1, v==v_empty);
  ASSERT_EQ(false, v.size());
  ASSERT_EQ(true, v.empty());
  
  //delete vec;
  //delete veccopy;
}

TEST_F(VectorTest, VectorFIFO)
{
  LOG_MESSAGE("VectorTest.VectorFIFO: Vector()");
  //Vector * v = vector__new();
  Vector v {};
  LOG_MESSAGE("VectorTest.VectorFIFO: Vector::push_front(...)");
  v.push_front(VectorElement {444});
  v.push_front(VectorElement {333});
  v.push_front(VectorElement {222});
  v.push_front(VectorElement {111});
  ASSERT_EQ(4,   v.size());

  LOG_MESSAGE("VectorTest.VectorFIFO: Vector::pop_back(...)");
  ASSERT_EQ(444, v.pop_back().value);
  ASSERT_EQ(333, v.pop_back().value);
  ASSERT_EQ(222, v.pop_back().value);
  ASSERT_EQ(111, v.pop_back().value);
  ASSERT_EQ(0,   v.size());

  LOG_MESSAGE("VectorTest.VectorFIFO: Vector::push_back(...)");
  v.push_back(VectorElement {111});
  v.push_back(VectorElement {222});
  v.push_back(VectorElement {333});
  v.push_back(VectorElement {444});
  ASSERT_EQ(4,   v.size());

  LOG_MESSAGE("VectorTest.VectorFIFO: Vector::pop_front(...)");
  ASSERT_EQ(111, v.pop_front().value);
  ASSERT_EQ(222, v.pop_front().value);
  ASSERT_EQ(333, v.pop_front().value);
  ASSERT_EQ(444, v.pop_front().value);
  ASSERT_EQ(0,   v.size());

  //LOG_MESSAGE("VectorTest.VectorFIFO: vector__delete");
  
  //vector__delete(v);
}

TEST_F(VectorTest, VectorLIFO)
{
  LOG_MESSAGE("VectorTest.VectorLIFO: Vector()");
  //Vector * v = vector__new();
  Vector v {};

  LOG_MESSAGE("VectorTest.VectorLIFO: Vector::push_front(...)");
  v.push_front(VectorElement {444});
  v.push_front(VectorElement {333});
  v.push_front(VectorElement {222});
  v.push_front(VectorElement {111});
  ASSERT_EQ(4,   v.size());

  LOG_MESSAGE("VectorTest.VectorLIFO: Vector::pop_front(...)");
  ASSERT_EQ(111, v.pop_front().value);
  ASSERT_EQ(222, v.pop_front().value);
  ASSERT_EQ(333, v.pop_front().value);
  ASSERT_EQ(444, v.pop_front().value);
  ASSERT_EQ(0,   v.size());

  LOG_MESSAGE("VectorTest.VectorLIFO: Vector::push_back(...)");
  v.push_back(VectorElement {111});
  v.push_back(VectorElement {222});
  v.push_back(VectorElement {333});
  v.push_back(VectorElement {444});
  ASSERT_EQ(4,   v.size());

  LOG_MESSAGE("VectorTest.VectorLIFO: Vector::pop_back(...)");
  ASSERT_EQ(444, v.pop_back().value);
  ASSERT_EQ(333, v.pop_back().value);
  ASSERT_EQ(222, v.pop_back().value);
  ASSERT_EQ(111, v.pop_back().value);
  ASSERT_EQ(0,   v.size());

  //LOG_MESSAGE("VectorTest.VectorLIFO: vector__delete");
  //vector__delete(v);
}


