#ifndef _STATE_HPP
#define _STATE_HPP
#include <set>
#include "fa_defs.hpp"
#include "exceptions/OverlapAlphabet.hpp"

namespace FA {

template <typename T>
class State {
	public:
		State(bool _accept = false) :__accept(_accept) {}
		~State() = default;
		void add(TransferPtr<T> nextstate) ;
	private:
		// @return: next state list corresponding to current value
		std::set<StatePtr<T>> next(T value);
		// @return: true if this state is accepted
		bool accept(void) const {return __accept;}
	private:
		bool __accept; // accept state
		std::set<TransferPtr<T>> Snext;
};

} // namespace FA

#include "src\State.cxx" // template implement

#endif
