#include<iostream>
#include<vector>
using namespace std;
class subject {
public:
 string subjectname;
 int credit;
    float gradepoint;
    // constructorr̥ṅ
subject(string name, int cr, float gp) {
subjectname = name;
          credit = cr;
        gradepoint = gp;
    }
};
class student {
public:
 string name;
    vector<subject> subjects;
    // constructor
    student(string studentname) {
  name = studentname;
    }
    void addsubject(string subjectname, int credit, float gradepoint) {
        subject newsubject(subjectname, credit, gradepoint);
        subjects.push_back(newsubject);
    }
    float calculatecgpa() {
     int totalcredit = 0;
        float weightedgradepoint = 0;
        for (const subject& sub : subjects) {
     totalcredit += sub.credit;
            weightedgradepoint += sub.credit * sub.gradepoint;
        }
    return (totalcredit > 0) ? (weightedgradepoint / totalcredit) : 0;
  }
    void displaycgpa() {
  cout << "Student name: " << name << endl;
      float cgpa = calculatecgpa();
 cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    string studentname;
    int numsub;
    cout << "Enter student name: ";
    getline(cin, studentname);
    cout << "Enter the number of subjects: ";
    cin >> numsub;

    student s(studentname);
    cin.ignore(); // To clear the newline character from the buffer

    for (int i = 0; i < numsub; i++) {
        string subjectname;
        int credit;
        float gradepoint;
        cout << "Enter the subject name: ";
        getline(cin, subjectname);
        cout << "Enter the credit: ";
        cin >> credit;

        cout << "Enter the gradepoint: ";
        cin >> gradepoint;
        cin.ignore(); // To clear the newline character for the next getline
        s.addsubject(subjectname, credit, gradepoint);
    }
    s.displaycgpa();
    return 0;
}
