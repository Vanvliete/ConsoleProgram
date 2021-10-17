#include "Classroll.h"

//Client code for Assignment One
//Author: Erik Van Vliet

using namespace std;

void showCourse(ClassRoll&);



int main()
{
	cout << "ClassRoll object examples for student.data file:" << endl << endl;
	ClassRoll comp333("student.data", "OOP C++", 3);
	cout << "Number of students in COMP 333 = " << comp333.getNoStudents() << endl;
	cout << "printing all students in student.data to the screenscreen:\n\n";
	comp333.writeStudents(cout);
	cout << "\nLooking up student T. Jones:\n";
	comp333.showGrade("T. Jones"); //should be in student.data, if not add it
	cout << "\nChange grade for T. Jones to a B\n\n";
	comp333.changeGrade("T. Jones", 'B');
	cout << "show T. Jones grade changed \n";
	comp333.showGrade("T. Jones");
	cout << "\nChange grade for T. Jones to a M\n\n";
	comp333.changeGrade("T. Jones", 'M');
	cout << "show non existant student\n";
	comp333.showGrade("Colin");
	cout << "printing all students in student.data again\n\n";
	comp333.writeStudents(cout);
	cout << "\n\ncalling your show course function:";
	//add the code to call your showCourse() function here for student.data
	showCourse(comp333);
	cout << "\n\n\nEmpty object examples from default.data file" << endl << endl;
	ClassRoll noclass("default.data", "No Class"); //empty file
	cout << "Number of students = " << noclass.getNoStudents() << endl << endl;
	cout << "\n\nbestClass object examples" << endl << endl;
	ClassRoll bestClass("fullclass.data", "poker");
	bestClass.writeStudents(cout);
	cout << "Number of students in " << bestClass.getCourseName()
		<< ": " << bestClass.getNoStudents() << endl << endl;
	bestClass.writeStudents(cout);
	bestClass.showGrade("Superman");
	cout << "write to a file \n";
	ofstream fout("sample.dat");
	if (!fout.is_open())
		
	{
		cout << "error opening saple.dat file " << endl;
		system("pause");
		exit(1);
	}
	bestClass.writeStudents(fout);
	cout << "\n\ncalling your show course function:";
	cout << "\n\ncalling your show course function:";
	//add the code to call your showCourse() function for bestclass

	showCourse(bestClass);

	system("type sample.dat");
	system("pause");


}

void showCourse(ClassRoll& classRollObject)
{
	cout << "Course name: " << classRollObject.getCourseName() << endl;
	cout << "Number of students: " << classRollObject.getNoStudents() << endl;
}

/*
ClassRoll object examples for student.data file:

Number of students in COMP 333 = 3
printing all students in student.data to the screenscreen:

Student Name           Assign Total     Test TotalGrade
Erik                            100            100    A
Kelli                            96             98    A
T. Jones                         88             83    A
Number of students: 3

Looking up student T. Jones:
T. Jones 's letter grade is: A

Change grade for T. Jones to a B

show T. Jones grade changed
T. Jones 's letter grade is: B

Change grade for T. Jones to a M

Incorrect grade entered. Please enter grade from A-F only.
show non existant student
Colin was not found, please check the name and try again.
printing all students in student.data again

Student Name           Assign Total     Test TotalGrade
Erik                            100            100    A
Kelli                            96             98    A
T. Jones                         88             83    B
Number of students: 3


calling your show course function:Course name: OOP C++
Number of students: 3



Empty object examples from default.data file

Number of students = 0



bestClass object examples

Student Name           Assign Total     Test TotalGrade
T. Jones                        100            100    A
B. Smith                         98             99    A
C. Ball                          83             82    B
K. Troyer                        76             74    C
T. Troyer                        50             51    D
K. VanVliet                      95             96    A
J. Doe                           35             32    F
F. Castle                        90             91    A
G. Donovan                       77             76    C
Z. Amand                         66             65    D
Number of students: 10
Number of students in poker: 10

Student Name           Assign Total     Test TotalGrade
T. Jones                        100            100    A
B. Smith                         98             99    A
C. Ball                          83             82    B
K. Troyer                        76             74    C
T. Troyer                        50             51    D
K. VanVliet                      95             96    A
J. Doe                           35             32    F
F. Castle                        90             91    A
G. Donovan                       77             76    C
Z. Amand                         66             65    D
Number of students: 10
Superman was not found, please check the name and try again.
write to a file


calling your show course function:

calling your show course function:Course name: poker
Number of students: 10
Student Name           Assign Total     Test TotalGrade
T. Jones                        100            100    A
B. Smith                         98             99    A
C. Ball                          83             82    B
K. Troyer                        76             74    C
T. Troyer                        50             51    D
K. VanVliet                      95             96    A
J. Doe                           35             32    F
F. Castle                        90             91    A
G. Donovan                       77             76    C
Z. Amand                         66             65    D
Number of students: 10
Press any key to continue . . .
*/