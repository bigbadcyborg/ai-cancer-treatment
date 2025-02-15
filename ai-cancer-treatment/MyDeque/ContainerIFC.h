//
// Created by Russell Sullivan on 4/30/2019.
//
/*
Purpose of containerIFC in C++:
Abstraction:
	Defines a common API for different container types (e.g., vector, list, set, etc.).
	Hides implementation details from users.
Polymorphism:
	Allows different container implementations to be used interchangeably via a base class pointer.
	Useful when writing generic code that should work with multiple container types.
Encapsulation & Loose Coupling:
	Clients only interact with the containerIFC, not the actual container.
	Makes it easier to change the underlying container without affecting dependent code.
Extensibility:
	New container types can be introduced without modifying existing code.
	Encourages reusable code in large projects.
*/

#ifndef DEQUEUE_PROJ9_CONTAINERIFC_H
#define DEQUEUE_PROJ9_CONTAINERIFC_H

class BADINDEX {};

template <class T>
class ContainerIfc {
public:
    virtual ContainerIfc <T>& pushFront(T) =0;
    virtual ContainerIfc <T>& pushBack(T) =0;
    virtual ContainerIfc <T>& popFront(T&) =0; // throws BADINDEX
    virtual ContainerIfc <T>& popBack(T&) =0; // throws BADINDEX
    virtual int getSize() =0;
    virtual bool isEmpty() =0;
    virtual T front() =0; // throws BADINDEX
    virtual T back() =0; // throws BADINDEX
    virtual T& operator [](int) =0; // throws BADINDEX
    virtual void erase() =0;
};


#endif //DEQUEUE_PROJ9_CONTAINERIFC_H
