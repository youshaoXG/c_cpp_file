#pragma once
#include "Point.h"

class Circle
{
public:
	void setXY(int x, int y);
	void setR(int r);

	//判断点十分在我的内部
	bool judgePoint(Point &p);
private:
	int m_x;
	int m_y;
	int m_r;
};

