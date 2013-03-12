#include <memory>
namespace FA {

class Alphabet;
template <typename T>
	using AlphabetPtr = std::shared_ptr<Alphabet<T>> ;
class State;
class Transfer;

}
