#include <iostream>
#include "manipulator_json.h"
#include<fstream>
Manipulator::Manipulator(const std::string &path){
		i.open(path);
	
	if (!i.is_open()) {
		std::cout << "File cannot be opened!" << std::endl;
	}
	else {
		i >> j;
	}
	i.close();
}
Manipulator::~Manipulator() {
	j.clear();
}
void Manipulator::PrintJsonObj() { std::cout << j<<std::endl; }

nlohmann::json Manipulator::SearchElement(const std::string& str) {
		if (j.count(str) == 0) {
			std::cout << "Element doesn't exist" << std::endl;
			return NULL;
		}
		return j[str];
}

void Manipulator::DeleteElement(const std::string& str) {
	if (j.count(str) == 0) {
		std::cout << "Element doesn't exist"<<std::endl;
		return;
	}
	j.erase(str);
}
json Manipulator::getJSONobj()
{
	return j;
}
json Manipulator::MaxElement() {
	json max = j.begin().value();
	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		if (it.value() > max) {
			max = it.value();
		}
	}
	return max;
}
json Manipulator::MinElement() {
	json min = j.begin().value();
	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		if (it.value() < min) {
			min = it.value();
		}
	}
	return min;
}

void Manipulator::WriteJsonToFile(const std::string& path) {
	i.open(path);
	if (!i.is_open()) {
		std::cout << "File cannot be opened!" << std::endl;
	}
	else {
		i << j;
	}
	i.close();
}
