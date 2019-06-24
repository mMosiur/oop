#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

int countDigit(int value, int digit) {
	int result = 0;
	value = abs(value);
	while (value > 0) {
		if (value % 10 == digit) result++;
		value /= 10;
	}
	return result;
}

class comparator {
	int m_digit;
public:
	comparator(int digit) : m_digit(digit) {};
	bool operator()(const int& a, const int& b) {
		return countDigit(a, m_digit) < countDigit(b, m_digit);
	}
};

void sortWithFunctor(std::vector<int>::iterator begin, std::vector<int>::iterator end, int digit) {
	if (digit < 0 || digit > 9) throw digit;
	std::sort(begin, end, comparator(digit));
}

bool compareByDigit(int a, int b, int digit) {
	return countDigit(a, digit) < countDigit(b, digit);
}

void sortWithBind(std::vector<int>::iterator begin, std::vector<int>::iterator end, int digit) {
	if (digit < 0 || digit > 9) throw digit;
	std::function<bool(const int& a, const int& b)> compare = std::bind(compareByDigit, std::placeholders::_1, std::placeholders::_2, digit);
	std::sort(begin, end, compare);
}
void sortWithLambda(std::vector<int>::iterator begin, std::vector<int>::iterator end, int digit) {
	if (digit < 0 || digit > 9) throw digit;
	std::sort(begin, end, [&digit](const int& a, const int& b) {
		return countDigit(a, digit) < countDigit(b, digit);
		});
}