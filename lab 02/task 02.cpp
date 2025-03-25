#include<iostream>
using namespace std;

class employee {
public:
	virtual void calculatesalary() = 0;
};

class fullTimeEmp :public employee {
	double fixsalary;
public:
	fullTimeEmp(double salary) {
		fixsalary = salary;
	}

	void calculatesalary() {
		cout << "Salary of full time employee: " << fixsalary << '\n';
	}
};

class partTimeEmp :public employee {
	int hours;
	double hourlysalary;
public:
	partTimeEmp(int hour, double salary) {
		hours = hour;
		hourlysalary = salary;
	}
	void calculatesalary() {
		cout << "Salary of part time employe: " << hours * hourlysalary << '\n';
	}
};

int main() {
	fullTimeEmp fte(50000);
	partTimeEmp pte(20, 1500);

	fte.calculatesalary();
	pte.calculatesalary();
	return 0;
}