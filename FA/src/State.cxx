#include "../State.hpp"

namespace FA {

template <typename T> 
std::set<StatePtr<T>> State<T>::next(T value) {
	std::set<StatePtr<T>> result;
	auto end = Snext.end();
	
	for (auto i = Snext.begin(); i != end; ++i) {
		auto nextState = (*i)->transfer(value);
		if (nextState != nullptr) 
			result.insert(nextState);
	}

	return result;
}

template <typename T>
void State<T>::add(TransferPtr<T> nextState) {
	auto end = Snext.end();
	for (auto i = Snext.begin(); i != end; ++i)
		if ( (*i)->alphabet()->mutex( *(nextState->alphabet())) )
			throw OverlapAlphabet<T>((*i)->alphabet(), nextState->alphabet());

	Snext.insert(nextState);
}

} // namespace FA

