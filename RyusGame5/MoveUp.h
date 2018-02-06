#pragma once
#include "Action.h"

class ObjList;
class MoveUp : Action{
public:
	MoveUp();
	~MoveUp();
	bool IsDone() override;
	void Act() override;

protected:
	bool isDone;
	ObjList* pObjList;
};