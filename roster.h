#pragma once
#include <string>
#include <array>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"

using namespace std;

class roster {
public:
	roster();
	
	void printAll();
	void add(string studentID, string emailAddress, string firstName, string lastName, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
	void remove(string studentID);
	void printByDegreeProgram(int Degree);
	void printNumDays(string);
	void printInvalidEmails();
	int addIndex = 0;
	Student* classRosterArray[5];
	virtual ~roster();
	
};

void main();
