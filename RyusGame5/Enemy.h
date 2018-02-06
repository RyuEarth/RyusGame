#pragma once
#include "AbsObj.h"
class Enemy : AbsObj{
public:
	bool IsDone() override;
	void Act() override;
};