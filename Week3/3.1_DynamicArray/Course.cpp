#include <iostream>
#include "Course.h"

Course::Course(const std::string& courseName, int capacity) {
	this->courseName = courseName;
	this->capacity = capacity;
	this->numberOfStudents = 0;
	this->students = new std::string[capacity];
}

Course::Course(const Course& course) {
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	this->numberOfStudents = course.numberOfStudents;
	this->students = new std::string[capacity];
	for (int i = 0; i < numberOfStudents; ++i) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {
	if (numberOfStudents == capacity) {
		resize();
	}
	students[numberOfStudents++] = name;
}

void Course::dropStudent(const std::string& name) {
	for (int i = 0; i < numberOfStudents; ++i) {
		if (students[i] == name) {
			for (int j = i; j < numberOfStudents - 1; ++j) {
				students[j] = students[j + 1];
			}
			--numberOfStudents;
			break;
		}
	}
}

void Course::clear() {
	numberOfStudents = 0;
}

std::string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

void Course::resize() {
	int newCapacity = capacity * 2;
	std::string* newStudents = new std::string[newCapacity];
	for (int i = 0; i < numberOfStudents; ++i) {
		newStudents[i] = students[i];
	}
	delete[] students;
	students = newStudents;
	capacity = newCapacity;
}
