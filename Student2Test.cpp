// Student2TestTest.cpp
#include <gmock/gmock.h>
#include <vector>
#include <unordered_map>
#include "Student2.h"

using namespace::testing;

class Student2Test: public Test{
protected:
  static Student2* student2;

  static void SetUpTestCase(){
    student2 = new Student2("Gordon Zuehlke");
    std::vector<double> homework {77, 88, 55, 99, 56, 88, 75}; 
    student2->setGrades(homework);
  }

  static void TearDownTestCase(){
    delete student2;
    student2 = nullptr;
  }
};

Student2* Student2Test::student2 = nullptr;

TEST_F(Student2Test, ObjectIsNotNull  ){
  ASSERT_NE(student2, nullptr);
}

TEST_F(Student2Test, StudentHasCorrectName  ){
  ASSERT_EQ(student2->getName(), "Gordon Zuehlke");
}

TEST_F(Student2Test, StudentHasCorrectNumberOfGrades  ){
  std::vector<double> my_homework {77, 88, 55, 99, 56, 88, 75}; 
  ASSERT_EQ((student2->getGrades()).size(), my_homework.size());
}

TEST_F(Student2Test, StudentHasCorrectGrades  ){
  std::vector<double> my_homework {77, 88, 55, 99, 56, 88, 75};
  std::vector<double> homework = student2->getGrades();
  auto count_set = std::unordered_map<double, int>();
  for (unsigned int count = 0; count < my_homework.size(); ++count)
  {
    count_set[my_homework[count]]++;
    count_set[homework[count]]--;    
  }
  
  bool my_count = std::all_of(count_set.begin(),count_set.end(),
           [](const std::pair<double,int> p) { 
              return p.second == 0;
           }
  );
 
  ASSERT_TRUE(my_count);
}

TEST_F(Student2Test, StudentHasCorrectMedianGrade) {
  std::vector<double> x_homework {77, 88, 55, 99, 56, 88, 75}; 
  std::vector<double> y_homework {77, 88, 55, 99, 56, 88}; 
  ASSERT_EQ(student2->getMedianGrade(x_homework), 77 );
  ASSERT_EQ(student2->getMedianGrade(y_homework), 82.5 );
}

TEST_F(Student2Test, StudentHasCorrectFinalGrade) {
  EXPECT_NEAR(student2->getFinalGrade(80, 87, 82), 83.8, 2);
}



/*
TEST_F(Student2Test, ){
  ASSERT_TRUE();
}

TEST_F(Student2Test, ){
  ASSERT_THAT();
}

TEST_F(Student2Test, ){
  ASSERT_FALSE();
}
*/

























