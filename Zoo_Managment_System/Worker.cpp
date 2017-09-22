#include "Worker.h"
#include "Area.h"

Worker::Worker(const char *name, int salary, Area* area) : name(_strdup(name)), salary(salary), idNumber(idCounter++)
{
	setArea(area);
}

void Worker::setArea(Area* newArea)
{
	// Checking that the areas are different
	if(area != newArea)
	{
		// Remove this worker from the old area
		if(newArea != nullptr)
		{
			area->removeWorker(this);
		}

		// Setting the area of this worker to the new area
		area = newArea;

		// In case the new area is not null, we should add to it this worker
		if (area != nullptr)
		{
			area->addWorker(this);
		}
	}
}

ostream& operator<<(ostream& os, const Worker& worker)
{
	os << "Name: " << worker.getName() << ", Id number: " << worker.getIdNumber() 
	   << ", Salary: " << worker.getSalary() << ", Area: " << worker.getArea();
	return os;
}