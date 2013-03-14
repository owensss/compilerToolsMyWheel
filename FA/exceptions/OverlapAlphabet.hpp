#ifndef OVERLAPALPHABET_HPP
#define OVERLAPALPHABET_HPP
#include "..\fa_defs.hpp"
#include <utility>

namespace FA {

template <typename T>
class OverlapAlphabet {
	public:
		OverlapAlphabet(AlphabetPtr<T> first, AlphabetPtr<T> second)
			:conflict(first, second)
		{
		}
		const std::pair<AlphabetPtr<T>, AlphabetPtr<T>>& what(void) const {
			return conflict;
		}
	private:
		std::pair<AlphabetPtr<T>, AlphabetPtr<T>> conflict;
};

}
#endif
