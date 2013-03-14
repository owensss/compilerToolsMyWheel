#ifndef ALPHABETA_HPP
#define ALPHABETA_HPP
#include <vector>
#include <utility> // std::pair

namespace FA {

/*
 * @note: 我觉得, 对于所有的虚函数都放到 private, 用一个公有非虚函数包装的做法也是
 * 		  看场合的. 这里, Alphabet 类本就没有任何东西, 数据全都留给子类, 那也就没必要
 * 		  这样了吧 ._.
 */
template <typename Symbol>
class Word {
	public:
		// @params: the value input
		// @return: true if value is accepted 
		virtual bool accept(Symbol value) const = 0;
	public:
		Word(void) = default;
		~Word(void) = default;
		// @params: the value to be added
		virtual void add(Symbol value) = 0;
		// @return: true, if they have values in common, false otherwise
		// @why-this: it's important that the Alphabet are mutex with each other
		virtual bool mutex(const Word<Symbol>& rhs) const = 0;
	private:
};

}

#endif
