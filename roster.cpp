#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include "roster.h"


using namespace std;

void main() {
	cout << "Scripting and Programming Applications C867" << endl;
	cout << "C++" << endl;
	cout << "000839618" << endl;
	cout << "Cory Deuschle" << endl;

	roster classRoster;

	Degree studentDegree;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Cory,Deuschle,cdeusch@wgu.edu],26,25,35,44,SOFTWARE"
	};

	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string holder[9];
	
		if (holder[8] == "SECURITY") {
			studentDegree = Degree::SECURITY;
		}
		if (holder[8] == "NETWORKING") {
			studentDegree = Degree::NETWORKING;
		}
		if (holder[8] == "SOFTWARE") {
			studentDegree = Degree::SOFTWARE;

		}
		classRoster.add(holder[0], holder[1], holder[2], holder[3], stoi(holder[4]), stoi(holder[5]), stoi(holder[6]), stoi(holder[7]), studentDegree);
	}
	classRoster.printAll();
	cout << "\n";
	classRoster.printInvalidEmails();
	cout << "\n";
	for (int i = 0; i < 5; i++) {
		classRoster.printNumDays(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << "\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n";
	classRoster.remove("A3");
	cout << "such a student with this ID was not found." << endl;
	classRoster.remove("A3");
	cout << "such a student with this ID was not found." << endl;
	return ;

}

roster::roster() { addIndex = -1; }
void roster::add(string studentID, string emailAddress, string firstName, string lastName, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType)
{
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	if (degreeType == Degree::NETWORKING) {
		classRosterArray[addIndex++] = new (NetworkStudent); (studentID, emailAddress, firstName, lastName, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
	}
	if (degreeType == Degree::SOFTWARE) {
		classRosterArray[addIndex++] = new (SoftwareStudent); (studentID, emailAddress, firstName, lastName, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
	}
	if (degreeType == Degree::SECURITY) {
		classRosterArray[addIndex++] = new (SecurityStudent); (studentID, emailAddress, firstName, lastName, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
	}
}

void roster::printAll() {
	for (int i = 0; i < 5; i++) {
		classRosterArray[i]->print();
	}
}

void roster::printNumDays(string studentID) {
	for (int i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).getStudentID() == studentID) {
			int avg = 0;
			avg = ((*classRosterArray[i]).getDaysInCourse()[0] + (*classRosterArray[i]).getDaysInCourse()[1] + (*classRosterArray[i]).getDaysInCourse()[2]) / 3;
			cout << "Average days took to student with ID: " << studentID << " to finish all three courses" << avg << endl;
		}
	}
}

void roster::printByDegreeProgram(int Degree) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == Degree) {
			classRosterArray[i]->print();
		}
	}
}

void roster::printInvalidEmails() {
	cout << "The following are invalid student emails: " << endl;
	for (int i = 0; i < 5; i++) {
		bool foundCharSymbol = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string studentEmail = "";
		studentEmail = (*classRosterArray[i]).getEmailAddress();
		for (char& a : studentEmail) {
			if (a == '@') {
				foundCharSymbol = true;
			}
			if (a == '.') {
				foundCharPeriod = true;
			}
			if (a == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharSymbol == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << (*classRosterArray[i]).getEmailAddress() << endl;
		}

	}
}

void roster::remove(string studentID) {
	bool removeStudent = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			removeStudent = true;
			break;
		}
	}
	if (removeStudent == false) {
		cout << "such a student with this" << studentID << " was not found." << endl;
	}
}
roster::~roster() {}
