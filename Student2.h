#ifndef Student2_h
#define Student2_h

#include <string>

class Student2 {
public:
  
  typedef std::vector<double>::size_type vec_sz;
  //Student2(const std::string name): name_(std::move(name)) {}
  //Student2(const char* name): name_(name) {}
  Student2(const std::string& name): name_(name) {}

  std::string getName() const {
    return name_;
  }
  
  void setGrades(std::vector<double>& homework) {
    homework_ = homework;
  }

  std::vector<double> getGrades() const {
    return homework_;  
  }

  double getMedianGrade(std::vector<double>& work) {
    vec_sz mid = sortAndDivideVector(work);
    return (work.size() % 2 == 0 ? (work[mid] + work[mid-1]) / 2 : work[mid]);
  } 

  vec_sz sortAndDivideVector(std::vector<double>& homework) {
    std::sort(homework.begin(), homework.end());
    return (vec_sz) (homework.size())/2;
  }  

  double getFinalGrade(double midterm, double final, double median) {
    return ((0.2 * midterm) + (0.4 * final) + (0.4 * median));
  }

private:
  std::string name_;
  std::vector<double> homework_;
};

#endif



