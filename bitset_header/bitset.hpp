#ifndef BITSET_H
#define BITSET_H

#include <iostream>
#include <cstdint>
#include <cassert> //for assert()
#include "namespace.hpp"

template<std::size_t size>
class ptd::bitset
{
private:
	std::size_t m_bitlength{size};
	std::size_t m_storage{};
	
public:
	//constructor for the binary store
	bitset(std::size_t storage = 0x00000000);
	
	//prevent copy
//	bitset(bitset& ) = delete;
	
	//prevent assignment
//	bitset& operator=(bitset&) = delete;

public:
	
	friend std::ostream& operator<<(std::ostream& out, const bitset& b)
	{
		for(std::size_t x{b.m_bitlength-1};; --x)
		{
			out << (b.ison(x))?"1":"0";
			if(x==0)
				break;
		}
			
		return out;
	}
		
public:
	
	//checking if bit is on
	bool ison(int index) const;

	//flip a bit
	bitset& flip(int index);
	
	//invert all bits
	bitset& invert();
	
	//turn on a bit
	bitset& on(int index);
	
	//turn off a bit
	bitset& off(int index);
	
//	#include "bitset.inl"
};
//#include "bitset.inl"
template<std::size_t size>
ptd::bitset<size>::bitset(std::size_t storage) {	m_storage = storage;	}

template<std::size_t size>
bool ptd::bitset<size>::ison(int index) const {	return (1<<index) & m_storage; }

template<std::size_t size>
ptd::bitset<size>& ptd::bitset<size>::flip(int index) {	m_storage ^= (1<<index); return *this;	}

template<std::size_t size>
ptd::bitset<size>& ptd::bitset<size>::invert() {	m_storage = ~m_storage; return *this;	}

template<std::size_t size>
ptd::bitset<size>& ptd::bitset<size>::on(int index) {	m_storage |= (1<<index); return *this;	}

template<std::size_t size>
ptd::bitset<size>& ptd::bitset<size>::off(int index){	m_storage &= ~(1<<index); return *this;	}

#endif
