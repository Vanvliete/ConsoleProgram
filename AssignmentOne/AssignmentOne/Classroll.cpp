#include "Classroll.h"

//Implementation file for class Classroll
//Author: Erik Van Vliet

ClassRoll::ClassRoll(string passedFile, string passedCourseName, int passedMaxStudents)
{
	int index = 0;

	if (passedMaxStudents > SIZE || passedMaxStudents <= 0)
	{
		cout << "Error. invalid maximum students entered. Default set." << endl;
		maxStudents = SIZE;
	}
	else
	{
		maxStudents = passedMaxStudents;
	}

	ifstream fin(passedFile);

	if (!fin.is_open())
	{
		cout << "Error, file did not open properly.";
		system("pause");
		exit(-1);
	}

	for (index = 0; index < maxStudents; index++)
	{

		getline(fin, students[index].studentName);
		if (fin.eof())
			break;

		fin >> students[index].assignmentTotal;
		fin >> students[index].testTotal;
		fin >> students[index].letterGrade;
		fin.ignore(80, '\n');
	}
	courseName = passedCourseName;
	noStudents = index;
}

void ClassRoll::writeStudents(ostream& output) const
{
	int length;
	output << left << setw(20) << "Student Name"
		<< right << setw(15) << "Assign Total"
		<< setw(15) << "Test Total"
		<< setw(5) << "Grade"
		<< endl;

	for (length = 0; length < noStudents; length++)
	{
		output << left << setw(20) << students[length].studentName
			<< right << setw(15) << students[length].assignmentTotal
			<< setw(15) << students[length].testTotal
			<< setw(5) << students[length].letterGrade
			<< endl;
	}

	output << "Number of students: " << noStudents << endl;
}

int ClassRoll::searchStudent(string passedStudentName) const
{
	int index = 0;
	
	for (index = 0; index < noStudents; index++)
	{
		if (passedStudentName == students[index].studentName)
		
			return index;
		
	}

	return (index+1);
}

void ClassRoll::showGrade(string passedStudentName) const
{
	
	if (searchStudent(passedStudentName) > noStudents)
	
		cout << passedStudentName << " was not found, please check the name and try again." << endl;
	
	else
		
		cout << passedStudentName << " 's letter grade is: " << students[searchStudent(passedStudentName)].letterGrade << endl;
}

void ClassRoll::changeGrade(string passedStudentName, char newGrade)
{
	int studentIndex = searchStudent(passedStudentName);
	newGrade = toupper(newGrade);
	switch (newGrade)
	{
		case 'A':
		{
			students[studentIndex].letterGrade = newGrade;
			break;
		}
		case 'B':
		{
			students[studentIndex].letterGrade = newGrade;
			break;
		}
		case 'C':
		{
			students[studentIndex].letterGrade = newGrade;
			break;
		}
		case 'D':
		{
			students[studentIndex].letterGrade = newGrade;
			break;
		}
		case 'F':
		{
			students[studentIndex].letterGrade = newGrade;
			break;
		}
		default:
			cout << "Incorrect grade entered. Please enter grade from A-F only." << endl;
	}

}

