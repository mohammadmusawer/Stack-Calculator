#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
	// Constructor 
	Node(T v, Node<T> *p) : val(v), next(p) {}

	// Accessor for data 
	T getVal() { return val;  }

	// Accessor for next pointer
	Node<T> *getNext() { return next; }
private:
	T val;			// Actual data stored in node
	Node<T> *next;			// Pointer to next node
};

#endif // NODE_H
