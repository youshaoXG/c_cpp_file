#pragma once

/*
#ifndef _CIRCLR_H_
#define _CIRCLE_H
#endif
*/

//圆类
class Circle
{
public:
	void setR(double r);
	double getR();
	double getArea();//得到面积
	double getGirth();//得到周长
private:
	double m_r;//半径
};

