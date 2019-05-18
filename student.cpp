#include "student.h"
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;


Student::Student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	daysInCourse = new int[daysInCourseArraySize];
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
}



/*Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeType)
{
	studentID = studentID;
	firstName = firstName;
	lastName = lastName;
	emailAddress = emailAddress;
	age = age;
	daysInCourse = new int[daysInCourseArraySize];
	for (int i = 0; i < 3; i++) daysInCourse[i] = daysInCourse[i];
}*/

//getters
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int  *Student::getDaysInCourse()
{
	return daysInCourse;
}

Degree Student::getDegreeType()
{
	return Degree();
}

//setters

void Student::setStudentID(string)
{
	studentID = studentID;
}

void Student::setFirstName(string)
{
	firstName = firstName;
}

void Student::setLastName(string)
{
	lastName = lastName;
}

void Student::setEmailAddress(string)
{
	emailAddress = emailAddress;
}

void Student::setAge(int)
{
	age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
	if (this->daysInCourse != nullptr) {
		delete[] this->daysInCourse;
		this->daysInCourse = nullptr;
	}
	this->daysInCourse = new int[daysInCourseArraySize];
	for (int i = 0; i < 3; i++)
		this->daysInCourse[i] = daysInCourse[i];
}

Student::~Student()
{
	if (daysInCourse != nullptr) {
		delete[] daysInCourse;
		daysInCourse = nullptr;
	}
}