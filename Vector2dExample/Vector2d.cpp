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
	cout << "x:" << x << "	" << "y:" << y << endl;
}

double Vector2d::length() //�� ������� ������� ����� �������, ��������� - �����
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

double Vector2d::angle(Vector2d v1) //������� ������� ���� ����� ���������, ��������� - �����
{
	return this->scalarMult(v1) / (this->length()*v1.length());
}

Vector2d Vector2d::operator+(const Vector2d& vector) //���������� �������� ��������. ��� ��� ����, ����� ����� ���� ������ a+b, � �� a.sum(b)
{
	return Vector2d(x + vector.x, y + vector.y); //���������� ������, ������� �������� ������ 2 ��������. ���� ��� 2 ������� �� ����������
}

Vector2d Vector2d::operator-(const Vector2d& vector) //���������� ���������, �������� ��� ��������
{
	return Vector2d(x - vector.x, y - vector.y);
}

double Vector2d::operator*(const Vector2d& vector) //���������� �������� ���������
{
	return x * vector.x + y * vector.y; //� ������ ������ ��������� - �����, ��� ��� ������ ��� ������� ��������� ��������� 2 ��������
}

Vector2d Vector2d::operator*(const double number) //���������� �������� ���������
{
	return Vector2d(x * number, y * number); //��������� - ������, �.�. �������� ������ �� �����
}

Vector2d operator*(double number, Vector2d& vector) //���� �������� ��������� ������� �� �����, ����� 4*� � �*4 �������� ��������� (��� ����� �� �����)
{
	return vector * number; //��������� - ������
}

Vector2d& Vector2d::operator++() //���������� �������� ���������� ++a
{
	x++; //�������� � � �
	y++; //������������� �� 1
	return *this; //������, ��� �������� ������� ��� ��������, ���������
}

Vector2d Vector2d::operator++(int) //���������� �������� ���������� �++
{
	Vector2d temp(x, y);
	x++;
	y++;
	return temp; //�������� ������
}

Vector2d& Vector2d::operator--() //���������� �������� ���������� --a
{
	x--;
	y--;
	return *this; //�������� ������
}

Vector2d Vector2d::operator--(int) //���������� �������� ���������� a--
{
	Vector2d temp(x, y);
	x--;
	y--;
	return temp; //�������� ������
}

const Vector2d& Vector2d::operator+= (const Vector2d&vector) //���������� �������� ������������ ����� �������� (a+=b)
{
	x += vector.x;
	y += vector.y;
	return *this; //�������� ������
}

const Vector2d& Vector2d::operator-= (const Vector2d& vector) //���������� �������� ������������ ����� ��������� (a-=b)
{
	x -= vector.x;
	y -= vector.y;
	return *this; //�������� ������
}

const Vector2d& Vector2d::operator*= (double number) //���������� �������� ������������ ����� ���������, �������� ���� ��������� �� ����� (a*=4)
{
	x *= number;
	y *= number;
	return *this; //�������� ������
}

Vector2d::operator string() //���������� �������� ������ �������������� � string, ������������ ��� ������. ������ ������ ����� ��������: (string)(a + b)
{
	string s = "(" + to_string(x) + "; " + to_string(y) + ")";
	return s;
}

Vector2d::~Vector2d() //����������, ������������ ��� �������. ����� �� ��� �� ����� ����� ���������
{
}