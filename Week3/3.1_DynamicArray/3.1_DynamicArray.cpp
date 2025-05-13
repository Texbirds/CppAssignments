#include <iostream>
#include "Course.h"

int main() {
	Course course("C++ Programming", 2);

	course.addStudent("Alice");
	course.addStudent("Bob");
	course.addStudent("Charlie"); 

	std::cout << "Students after adding:\n";
	std::string* students = course.getStudents();
	for (int i = 0; i < course.getNumberOfStudents(); ++i) {
		std::cout << "- " << students[i] << "\n";
	}

	course.dropStudent("Bob");

	std::cout << "\nStudents after dropping Bob:\n";
	for (int i = 0; i < course.getNumberOfStudents(); ++i) {
		std::cout << "- " << students[i] << "\n";
	}

	course.clear();
	std::cout << "\nAfter clearing, number of students: " << course.getNumberOfStudents() << std::endl;

	return 0;
}
