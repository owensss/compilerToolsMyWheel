#include <memory>
namespace FA {

template <typename T> class Word;
template <typename T>
	using WordPtr = std::shared_ptr<Word<T>> ;

template <typename T> class State;
template <typename T>
	using StatePtr = std::shared_ptr<State<T>>;

template <typename T> class Transition;
template <typename T>
	using TransitionPtr = std::shared_ptr<Transition<T>>;

}
