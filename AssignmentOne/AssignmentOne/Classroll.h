#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Specification file for class Classroll
//Assignment 1 - Program designed for a professor to maintain records of enrolled students
//Author: Erik Van Vliet

const int SIZE = 25;

struct StudentRec
{
	string studentName;
	int assignmentTotal, testTotal;
	char letterGrade;

};

class ClassRoll
{
public:
	
	void showGrade(string /*studentName*/) const;
	int getNoStudents() const { return noStudents; }
	string getCourseName() const { return courseName; }
	void changeGrade(string /*studentName*/, char /*studentGrade*/);
	void writeStudents(ostream& /*output*/) const;
	
	ClassRoll(string /*fileName*/, string /*courseName*/, int = 10 /*maxStudents*/);

private:

	string courseName;
	int maxStudents, noStudents;
	StudentRec students[SIZE];
	int searchStudent(string)const;
	
};
