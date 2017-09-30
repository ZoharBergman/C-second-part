#include "Worker.h"
#include "Area.h"

long Worker::idCounter = 0;

Worker::Worker(const char *name, int salary, Area* area) : name(_strdup(name)), salary(salary), idNumber(Worker::idCounter++), area(nullptr)
{
	setArea(area);
}

void Worker::setArea(Area* newArea)
{
	// Checking that the areas are different
	if(area != newArea)
	{
		// Remove this worker from the old area
		if(area != nullptr)
		{
			if (typeid(*this) != typeid(AreaManager))
			{
				area->removeWorker(this);
			}
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
	if (&worker != nullptr)
	{
		os << typeid(worker).name()+6 << ": Name: " << worker.getName() << ", Id number: " << worker.getIdNumber() 
			<< ", Salary: " << worker.getSalary();
	}

	return os;
}