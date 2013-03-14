#ifndef TRANSFER_HPP
#define TRANSFER_HPP
#include "fa_defs.hpp"
#include <utility> // std::pair
#include <vector>

namespace FA {

/* note: a transfer with alphabet = nullptr will generate a ep-transfer */
template <typename T>
class Transition {
	public:
		// ep-transfer constructor
		inline Transition(StatePtr<T> next);
		inline Transition(WordPtr<T> alphabet, StatePtr<T> next);
		WordPtr<T> alphabet(void) const {return Tnext.first;}
		StatePtr<T> state(void) const {return Tnext.second;}
		/*
		 * @return: if value is accepted, return next State. else return nullptr
		 */
		inline StatePtr<T> transfer(T value);
	private:
		Transition() = delete;
		std::pair<WordPtr<T>, StatePtr<T>> Tnext;
};

} // namespace FA

#include "src/Transition.cxx"

#endif
