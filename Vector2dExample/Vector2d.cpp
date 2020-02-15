#include "pch.h"
#include "Vector2d.h"

Vector2d::Vector2d(double x, double y) //������������� ������� �� ������ �����������
{
	this->x = x; //���������� ������� �������� ���������� ������
	(*this).y = y; //������ ��������� ������
}

Vector2d::Vector2d(double x1, double y1, double x2, double y2) //������������� ������� �� 2 ������
{
	this->x = x2 - x1; //���������� � � �
	this->y = y2 - y1; //������� �� �������
}

Vector2d::Vector2d(const Vector2d& Vector) //�������������� ������, ������� ������ (Vector - ��� ������������ ������, ������� �� ��������)
{
	this->x = Vector.x; //����������� �������� ���������
	this->y = Vector.y; //�������, ������� ��������
}

void Vector2d::sum(Vector2d vector) //����� ��������, � ���������� ������ ������ ���������� 
{
	x = x + vector.x; //� ����������� �������, �� ��������	�� ������� ���� �����
	y = y + vector.y; //���������� ���������� �������, ������� �������� ���������� �������
}

void Vector2d::sub(Vector2d vector) //��������� ��������, ��� ���� �����, ��� � � �����
{
	x = x - vector.x;
	y = y - vector.y;
}

double Vector2d::scalarMult(Vector2d vector) //��������� ���������, ������� �� �������
{
	return x * vector.x + y * vector.y;		 //��������� - �����, ������� �� ��������
}

void Vector2d::mult(double a) //��������� ������� �� �����
{
	x = x * a; //������ �������� ����������
	y = y * a; //�� ������� �����
}

void Vector2d::print() //������� ���������� �������
{
	cout << "x = " << x << "  " << "y = " << y << endl;
}

Vector2d::~Vector2d() //����������, ������������ ��� �������. ����� �� ��� �� ����� ����� ���������
{
}