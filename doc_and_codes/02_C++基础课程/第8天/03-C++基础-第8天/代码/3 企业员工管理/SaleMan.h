#pragma once
#include "Employee.h"

class SaleMan : virtual public Employee
{
public:
	SaleMan();
	~SaleMan();


	//�õ�Ա����нˮ�ķ���
	virtual void getPay() ;

	//Ա������������
	virtual void uplevel(int addLevel) ;

	virtual void init();

protected:
	//���µ������ܶ�
	int saleAmount;
	//��ɱ���
	double salePersent;
};

