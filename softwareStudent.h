#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int* daysInCourse,
		int age,
		Degree degreeType
	);
	Degree getDegreeProgram();
	void setDegreeType(Degree);
	void print();

	
	// Degree getDegreeProgram() override;
	//using Student::Student;
//private:
	Degree degreeType = SECURITY;
~SoftwareStudent();
};