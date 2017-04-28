#ifndef Student2_h
#define Student2_h

#include <string>

class Student2 {
public:
  
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

  double getMedianGrade(std::vector<double>& homework) {
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    std::sort(homework.begin(), homework.end());
    vec_sz mid = size/2;
    
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];
    return median;
  }  

  double getFinalGrade(double midterm, double final, double median) {
    return ((0.2 * midterm) + (0.4 * final) + (0.4 * median));
  }

private:
  std::string name_;
  std::vector<double> homework_;
};

#endif



