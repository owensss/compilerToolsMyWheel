#ifndef ALPHABETA_HPP
#define ALPHABETA_HPP
#include <vector>
#include <utility> // std::pair

/*
 * requirement for T:
 * <, == >
 */
/*
 * we did not effort to optimize the storage. even duplicates are not considered at all!
 */
template <typename T>
class LexAlphabet {
	public:
		// @params: the value input
		// @return: true if value is accepted 
		bool accept(T value);
	public:
		Alphabet(void) {}
		~Alphabet(void) {}
		// @params: the value to be added
		void add(T value) {dis.push_back(value);}
		// @params: the value to be added
		void add(T down, T up);
		void clear() { dis.clear(); cont.clear(); }
	private:
		std::vector<T> dis; // distributed values
		std::vector<std::pair<T, T>> cont; // continuoues values
};

#include "src\LexAlphabet.cxx" // impl functions

#endif
