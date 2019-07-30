#pragma once
#include "json.h"
#include <fstream>
using json = nlohmann::json;
class Manipulator {
private:
	json j;
	std::fstream i;
	
public:
	Manipulator(const std::string&);
	void WriteJsonToFile(const std::string&);
	~Manipulator();
	void PrintJsonObj();
	json SearchElement(const std::string&);
	void DeleteElement(const std::string &);
	template<typename T>
	void AddElement(const std::string& t1, T&& t2) {
		j.emplace(t1, t2);
	};
	json getJSONobj();
	json MaxElement();
	json MinElement();
};