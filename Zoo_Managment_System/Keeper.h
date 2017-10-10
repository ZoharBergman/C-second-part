//
//  Keeper.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __KEEPER_H
#define __KEEPER_H

#include "Worker.h"

class Keeper : public Worker
{
public:
	static const enum eAnimal {LION, PENGUIN, ELEPHANT, GIRAFFE, ZEBRA, HORSE, ZEBROID};
	static const char* eAnimalsNames[];
private:
	eAnimal specialty;
	Keeper(const Keeper& keeper);
	const Keeper& operator=(const Keeper& keeper);

public:
	Keeper(const char *name, int salary, eAnimal specialty, Area* area = nullptr);	

	inline eAnimal getSpecialty() const { return specialty; }
	
	virtual void toOs(ostream& os) const;
};


#endif /* __KEEPER_H */