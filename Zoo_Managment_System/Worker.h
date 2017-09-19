//
//  Worker.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __WORKER_H
#define __WORKER_H

#include <iostream>

using namespace std;

class Area;

class Worker
{
private:
	static long idCounter;   
    char *name;
    long idNumber;
    int salary;
	const Area* area;
    Worker(const Worker& worker);
    const Worker& operator=(const Worker& worker);

public:
    
	Worker(const char *name, int salary, const Area* area = NULL);
	~Worker(){ delete []name; }        
    
	inline const char* getName() const { return name; }
    
	inline long getIdNumber() const { return idNumber; }
    
	inline int getSalary() const { return salary; }
	void setSalary(int salary) { this->salary = salary; }
    
	inline const Area& getArea() const { return *area; }
	void setArea(const Area& area){ this->area = &area; }
    
    friend ostream& operator<<(ostream& os, const Worker& worker);
    
};
long Worker::idCounter = 0;
#endif /* __WORKER_H */