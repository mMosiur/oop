#pragma once
#include <map>
#include <list>

template <class T>
std::map<T, int> count(std::list<T> objects) {
	std::map<T, int> mapa;
	for (auto i : objects) {
		auto result = mapa.emplace(i, 1);
		if (!result.second) result.first->second++;
	}
	return mapa;
}

#include <string>
#include <sstream>

template<>
std::map<std::string, int> count(std::list<std::string> objects) {
	std::map<std::string, int> mapa;
	for (auto i : objects) {
		std::stringstream ss(i);
		std::string temp;
		while (ss >> temp) {
			auto result = mapa.emplace(temp, 1);
			if (!result.second) result.first->second++;
		}
	}
	return mapa;
}