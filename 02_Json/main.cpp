#include "json.h"
#include <iostream>
#include <fstream>
#include "manipulator_json.h"


int main() {
	std::string jso = "struct.json";
	Manipulator obj(jso);
	obj.PrintJsonObj();
	std::cout<<obj.SearchElement("Object")<<std::endl;
	obj.AddElement("Issue",true);
	obj.PrintJsonObj();
	obj.DeleteElement("Trouble");
	obj.PrintJsonObj();
	std::cout << "Max element "<< obj.MaxElement() << std::endl;
	std::cout << "Min element "<<obj.MinElement() << std::endl;
	obj.WriteJsonToFile("object.json");
	return 0;
}