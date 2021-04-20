/*
 * 作者：解琛；
 * 时间：2021 年 4 月 19 日；
 * 功能：队列；
 */

#include "list.h"

template <typename T> class Queue: public List<T> {
public:
    void enqueue(T const& e) { insertAsLast(e); }
    T dequeue() { return remove(first()); }
    T& front { return first()->data; }
};
