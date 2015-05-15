
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_GridBagConstraints__
#define __java_awt_GridBagConstraints__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class GridBagConstraints;
        class Insets;
    }
  }
}

class java::awt::GridBagConstraints : public ::java::lang::Object
{

public:
  virtual ::java::lang::Object * clone();
  GridBagConstraints();
  GridBagConstraints(jint, jint, jint, jint, jdouble, jdouble, jint, jint, ::java::awt::Insets *, jint, jint);
public: // actually package-private
  static const jlong serialVersionUID = -1000070633030801713LL;
public:
  static const jint NONE = 0;
  static const jint BOTH = 1;
  static const jint HORIZONTAL = 2;
  static const jint VERTICAL = 3;
  static const jint CENTER = 10;
  static const jint NORTH = 11;
  static const jint NORTHEAST = 12;
  static const jint EAST = 13;
  static const jint SOUTHEAST = 14;
  static const jint SOUTH = 15;
  static const jint SOUTHWEST = 16;
  static const jint WEST = 17;
  static const jint NORTHWEST = 18;
  static const jint RELATIVE = -1;
  static const jint REMAINDER = 0;
  static const jint PAGE_START = 19;
  static const jint PAGE_END = 20;
  static const jint LINE_START = 21;
  static const jint LINE_END = 22;
  static const jint FIRST_LINE_START = 23;
  static const jint FIRST_LINE_END = 24;
  static const jint LAST_LINE_START = 25;
  static const jint LAST_LINE_END = 26;
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) anchor;
  jint fill;
  jint gridheight;
  jint gridwidth;
  jint gridx;
  jint gridy;
  ::java::awt::Insets * insets;
  jint ipadx;
  jint ipady;
  jdouble weightx;
  jdouble weighty;
  static ::java::lang::Class class$;
};

#endif // __java_awt_GridBagConstraints__