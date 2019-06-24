#include <iostream>
#include <string>
#include "1-2.h"
#include "3-4.h"
#include "5.h"

int main() {
	/// 1
	std::cout << std::endl << "Zadanie 1" << std::endl;
	std::list<float> lista1 = { 3.14, 2.34, 1.11, 3.14 };
	auto mapa1 = count(lista1);
	for (auto i : mapa1) {
		std::cout << i.first << " - " << i.second << std::endl;
	}
	
	/// 2
	std::cout << std::endl << "Zadanie 2" << std::endl;
	std::list<std::string> lista2 = { "Ala ma", "kota", "oraz ma", "psa" };
	auto mapa2 = count(lista2);
	for (auto i : mapa2) {
		std::cout << i.first << " - " << i.second << std::endl;
	}

	/// 3
	std::cout << std::endl << "Zadanie 3" << std::endl;
	StringList s_list(lista2);
	s_list("przewodnika", true);
	s_list("kota", false);
	s_list("oraz ma", false);
	s_list("orangutana", false);
	s_list.print();

	/// 4
	std::cout << std::endl << "Zadanie 4" << std::endl;
	try {
		while(true) {
			std::cout << s_list << " ";
		}
	} catch (std::out_of_range e) {
		std::cout << std::endl;
	}

	std::cout << std::endl << "Zadanie 5" << std::endl;
	std::vector<int> vec = { 1, 111, 11, 12, 221, 222 };
	sortWithFunctor(vec.begin(), vec.end(), 1);
	for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;
	sortWithBind(vec.begin(), vec.end(), 2);
	for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;
	sortWithLambda(vec.begin(), vec.end(), 1);
	for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;
}