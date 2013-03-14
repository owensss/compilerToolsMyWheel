#include "../nfa.hpp"
#include "../Transition.hpp"
#include "../Word.hpp"

namespace FA {

template <typename T>
NFA<T>& NFA<T>::insert(StatePtr<T> state) {
	states.push_back(state);
	return *this;
}

template <typename T>
std::set<StatePtr<T>> NFA<T>::next(T value) const {
	if (current == nullptr) return *this;
	decltype(__current) s;

	auto end = __current.end();
	for (auto i = __current.begin(); i != end; ++i) {
		auto next = (*i)->next(value);
		s.insert(std::begin(next), std::end(next));
	}

	current = s;
	return s;
}

}
