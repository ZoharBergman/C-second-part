//
//  Area_Manager.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __AREA_MANAGER_H
#define __AREA_MANAGER_H

#include "Worker.h"

class AreaManager : public Worker
{
private:
	AreaManager(const AreaManager& areaManager);
    const AreaManager& operator=(const AreaManager& areaManager);

public:

	AreaManager(const char *name, int salary, const Area* area = NULL);            
};


#endif /* __AREA_MANAGER_H */
