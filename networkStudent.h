#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student 
{
public: 
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();
// Degree getDegreeProgram() override;
	//using Student::Student;
//private:
	Degree degreeType = NETWORKING;


};