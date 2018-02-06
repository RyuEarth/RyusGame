#pragma once

class Action {
public:
	virtual bool IsDone() = 0;
	virtual void Act() = 0;
protected:
	bool isDone;
	ObjList* pObjList;
};