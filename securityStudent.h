#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(
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

	~SecurityStudent();

// Degree getDegreeProgram() override;
	//using Student::Student;
//private:
	Degree degreeType = SECURITY;
};