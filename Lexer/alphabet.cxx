#include "../alphabet.hpp"
#include <algorithm> // std::swap

namespace FA {

template <typename T>
void LexAlphabet<T>::add(T down, T up) {
	if (down == up) {
		add(down);
		return; 
	} else if (down > up) {
		std::swap(down, up);
	}

	cont.push_back(std::make_pair<T, T>(down, up));
}

template <typename T>
bool LexAlphabet<T>::accept(T value) {
	auto dsize = dis.size();
	for (auto i = 0; i < dsize; ++i)
		if (dis[i] == value) return true;

	auto csize = cont.size();
	for (auto i = 0; i < csize; ++i) {
		const auto& p = csize[i];
		if ((p.first<value && p.second>value) || p.first==value || p.second==value)
			return true;
	}
	
	return false;
}

}
