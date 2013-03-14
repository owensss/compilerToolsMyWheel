#include "../Transition.hpp"

namespace FA {

template <typename T> 
Transition<T>::Transition(StatePtr<T> next)
	:Tnext(nullptr, next) 
{
}

template <typename T>
Transition<T>::Transition(WordPtr<T> alphabet, StatePtr<T> next) 
	:Tnext(alphabet, next)
{
}

template <typename T> 
StatePtr<T> Transition<T>::transfer(T value) {
	if (Tnext.first->accept(value)) return Tnext.second;
	
	return nullptr;
}
}
