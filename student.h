#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
private: //data types
	     string studentID;
		 string firstName;
		 string lastName;
		 string emailAddress;
		 int age;
		 int* daysInCourse; //array size of 3
		 Degree degreeType; // degree types(networking, security, software)

public: 
	//constructors 
	const static int daysInCourseArraySize = 3;
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse[], Degree degreeType);

	
	//accessor/get methods
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	Degree getDegreeType();

	//virtual
	virtual Degree getDegreeProgram() = 0;
	

	//mutator/set methods
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmailAddress(string);
	void setAge(int);
	void setDaysInCourse(int[]);
	virtual void setDegreeType(Degree) = 0;
    virtual void print() = 0;

	//destructor
	~Student();

};

#endif //STUDENT_H

