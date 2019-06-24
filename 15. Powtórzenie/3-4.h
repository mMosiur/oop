#pragma once
#include <string>
#include <list>

class StringList {
	std::list<std::string> m_list;
	std::list<std::string>::iterator it;
public:
	StringList(std::list<std::string> list) : m_list(list) {
		it = m_list.begin();
	}
	void operator()(std::string s, bool mode) {
		if (mode) {
			m_list.push_back(s);
		}
		else {
			for (auto i = m_list.begin(); i != m_list.end(); ++i) {
				if (*i == s) {
					m_list.erase(i);
					break;
				}
			}
		}
	}
	void print() { for (auto i : m_list) std::cout << i << " "; std::cout << std::endl; }

	friend std::ostream& operator<<(std::ostream& a, StringList& b);
};

std::ostream& operator<<(std::ostream& out, StringList& list) {
	if (list.it == list.m_list.end()) {
		list.it = list.m_list.begin();
		throw std::out_of_range("List out of range");
	}
	out << *(list.it++);
	return out;
}