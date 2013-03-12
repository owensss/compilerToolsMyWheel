#ifndef TRANSFER_HPP
#define TRANSFER_HPP
#include "fa_defs.hpp"

namespace FA {

template <typename T>
class Transfer {
	public:
		void add(AlphabetPtr<T> alphabet, State* next);
		
};

}
#endif
