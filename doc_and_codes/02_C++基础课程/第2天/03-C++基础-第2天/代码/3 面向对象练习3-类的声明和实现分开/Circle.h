#pragma once
#include "Point.h"

class Circle
{
public:
	void setXY(int x, int y);
	void setR(int r);

	//�жϵ�ʮ�����ҵ��ڲ�
	bool judgePoint(Point &p);
private:
	int m_x;
	int m_y;
	int m_r;
};

