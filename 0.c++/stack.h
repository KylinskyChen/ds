/*
 * 作者：解琛；
 * 时间：2021 年 4 月 19 日；
 * 功能：Stack；
 */

#include "vector.h"

template <typename T> class Stack: public Vector<T> {
public:
    void push(T const& e) { insert(size(), e); }
    T pop() { return remove(size() - 1); }
    T& top() { return (*this)[size() - 1]; }
};
