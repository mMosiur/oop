#pragma once
#include <map>
#include <list>

template <class T>
std::map<T, int> count(std::list<T> objects) {
	std::map<T, int> mapa;
	for (auto i : objects) {
		auto result = mapa.emplace(i, 1);
		if (result.second) continue;
		result.first->second++;
	}
	return mapa;
}