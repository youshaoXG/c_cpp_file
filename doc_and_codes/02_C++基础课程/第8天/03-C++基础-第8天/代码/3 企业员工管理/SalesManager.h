#pragma once
#include "Manager.h"
#include "SaleMan.h"

class SalesManager : public Manager, public SaleMan
{
public:
	SalesManager();
	~SalesManager();

	//�õ�Ա����нˮ�ķ���
	virtual void getPay();

	//Ա������������
	virtual void uplevel(int addLevel);

	virtual void init();

};

