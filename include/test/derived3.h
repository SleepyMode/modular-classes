
#pragma once

#include "wrapper/base.h"

class Derived3 : public ActiveBase
{
public:
	virtual void Test()
	{
		__super::Test();
		std::printf("Derived3::Test\n");
	}
};

#undef ActiveBase
#define ActiveBase Derived3

