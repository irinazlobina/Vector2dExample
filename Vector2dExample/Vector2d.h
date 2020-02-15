#pragma once
#include <iostream>
using namespace std;
class Vector2d
{
private:
	double x, y; //координаты вектора
public:
	Vector2d() { x = 0; y = 0; } //создает нулевой вектор
	Vector2d(double, double); //создание вектора по координатам
	Vector2d(double, double, double, double); //создание вектора по 2 точкам
	Vector2d(const Vector2d&); //копирование существующего вектора
	~Vector2d(); //деструктор

	void setx(double value) { x = value; } //задание координаты х
	double getx() { return x; }			   //получение значения х
	void sety(double value) { y = value; } //задание координаты у
	double gety() { return y; }			   //получение значения у
	void sum(Vector2d); //сложение векторов
	void sub(Vector2d); //вычитание векторов
	void mult(double); //умножение вектора на число
	double scalarMult(Vector2d); //скалярное умножение векторов
	void print(void); //вывод координат вектора

};
