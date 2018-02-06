#pragma once

#include <List>
#include "AbsObj.h"
class ObjList {
public:
	ObjList& Instance() {
		static ObjList instance;
		return instance;
	}
	void SetObject(AbsObj& obj) {
		pList->push_back(obj);
	}
	 std::list<AbsObj>& GetList() {
		 return *pList;
	}
private:
	ObjList();
	~ObjList();
	std::list<AbsObj>* pList;
};