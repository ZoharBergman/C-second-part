#include "Worker.h"
#include "Area.h"

Worker::Worker(const char *name, int salary, const Area* area) : name(_strdup(name)), salary(salary), area(area), idNumber(idCounter++){};

ostream& operator<<(ostream& os, const Worker& worker)
{
	os << "Name: " << worker.getName() << ", Id number: " << worker.getIdNumber() 
	   << ", Salary: " << worker.getSalary() << ", Area: " << worker.getArea();
	return os;
}