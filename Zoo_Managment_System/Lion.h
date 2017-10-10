//
//  Lion.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __LION_H
#define __LION_H

#include "Animal.h"

class Lion : public Animal
{
public:
	const static enum eManeColor { WHITE, BROWN, YELLOW, RED, ORANGE };
	const static char* eManeColorText[];

private:
	eManeColor maneColor;
	Lion(const Lion& lion);
	const Lion& operator=(const Lion& lion);

public:
	Lion(const char *name, float weight, int birthYear, eManeColor maneColor);        

	inline eManeColor getManeColor() const { return maneColor; }

	virtual void toOs(ostream& os) const;
};


#endif /* __LION_H */