#ifndef NFA_HPP
#define NFA_HPP
#include "fa_defs.hpp"
#include <vector>
#include <set>

namespace FA {

/* T is: the alphabet element of the State machine */
/* I forbid sigma transition */
/* no symbol definition */
/* note: the Transition includes:
 * 		1, the Word from the symbols.
 * 		2, the dest-State
 * 		it do not contains the src-State
 */
template <typename T>
class NFA {
	public:
		inline NFA<T>& insert(StatePtr<T> state);
		// @desc: set current state
		inline NFA<T>& setCurrent(StatePtr<T> state) {__current.clear(); __current.push_back(state);}
		// @desc: set start state
		inline NFA<T>& setStart(StatePtr<T> state) {__start = state; return *this;}
		// @return: the next State. nullptr if goes into a wrong state
		inline std::set<StatePtr<T>> next(T value) const;
		// @return: true if current state is accepted
		std::set<StatePtr<T>> isAccept(void) const;
		StatePtr<T> start(void) const {return __start;}
		std::set<StatePtr<T>> current(void) const {return __current;}
		void rerun(void) {__current.insert(start);}
	private:
		std::vector<StatePtr<T>> states;
		// current states
		std::set<StatePtr<T>> __current;
		StatePtr<T> __start;
};

} // namespace FA

#include "src/nfa.cxx"

#endif
