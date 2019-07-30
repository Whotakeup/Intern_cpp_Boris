
#include "manipulator_json.h"
#include "gtest/gtest.h"
#include <string>
#include <fstream>

class ManipulatorTest:public::testing::Test {

	public:
	Manipulator *obj;
	ManipulatorTest(){ 
		obj = new Manipulator("struct.json"); 
	}

};

TEST_F(ManipulatorTest, TestInit){

	ASSERT_FALSE(obj->getJSONobj().is_null());

}
TEST_F(ManipulatorTest, TestSearchElement) {

	ASSERT_TRUE(obj->SearchElement("username") == "Alex");

}
TEST_F(ManipulatorTest, TestAddElement) {

	obj->AddElement("Follow", 4);
	ASSERT_TRUE(obj->SearchElement("Follow")==4);

}
TEST_F(ManipulatorTest, TestDeleteElement) {

	obj->DeleteElement("Follow");
	ASSERT_TRUE(obj->SearchElement("Follow") == NULL);

}

TEST_F(ManipulatorTest, TestGetMax) {

	ASSERT_TRUE(obj->MaxElement() == "Alex");

}
TEST_F(ManipulatorTest, TestGetMin) {

	ASSERT_EQ(23,obj->MinElement());

}
TEST_F(ManipulatorTest, WriteToFile) {

	obj->WriteJsonToFile("object.json");
	std::fstream out("object.json");
	std::string actual;
	out >> actual;
	ASSERT_FALSE(actual.empty());
	out.close();
}
int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}