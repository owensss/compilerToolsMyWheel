#ifndef ALPHABETA_HPP
#define ALPHABETA_HPP
#include <vector>
#include <utility> // std::pair

namespace FA {

/*
 * @note: �Ҿ���, �������е��麯�����ŵ� private, ��һ�����з��麯����װ������Ҳ��
 * 		  �����ϵ�. ����, Alphabet �౾��û���κζ���, ����ȫ����������, ��Ҳ��û��Ҫ
 * 		  �����˰� ._.
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
