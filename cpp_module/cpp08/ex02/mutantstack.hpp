#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	MutantStack() { }
	MutantStack(const MutantStack& copy) { *this = copy; }
	MutantStack& operator=(const MutantStack& origin) { (void)origin; return *this; }
	~MutantStack() { }
};

#endif