template<std::size_t size>
ptd::bitset<size>::bitset(std::size_t storage) {	m_storage = storage;	}

template<std::size_t size>
bool ptd::bitset<size>::ison(int index) const {	return (1<<index) & m_storage; }

template<std::size_t size>
void ptd::bitset<size>::flip(int index) {	m_storage ^= (1<<index);	}

template<std::size_t size>
void ptd::bitset<size>::invert() {	m_storage = ~m_storage;	}

template<std::size_t size>
void ptd::bitset<size>::on(int index) {	m_storage |= (1<<index); }

template<std::size_t size>
void ptd::bitset<size>::off(int index){	m_storage &= ~(1<<index); }
