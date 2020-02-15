#include "pch.h"
#include "Vector2d.h"

Vector2d::Vector2d(double x, double y) //инициализация вектора по данным координатам
{
	this->x = x; //присвоение данного значения экземпляру класса
	(*this).y = y; //пример возможной записи
}

Vector2d::Vector2d(double x1, double y1, double x2, double y2) //инициализация вектора по 2 точкам
{
	this->x = x2 - x1; //координаты х и у
	this->y = y2 - y1; //считаем по формуле
}

Vector2d::Vector2d(const Vector2d& Vector) //инициализируем вектор, копируя другой (Vector - уже существующий вектор, который мы копируем)
{
	this->x = Vector.x; //присваиваем значения координат
	this->y = Vector.y; //вектора, которым копируем
}

void Vector2d::sum(Vector2d vector) //сумма векторов, в результате первый вектор изменяется 
{
	x = x + vector.x; //к координатам вектора, от которого	мы вызвали этот метод
	y = y + vector.y; //прибавляем координаты вектора, который является параметром функции
}

void Vector2d::sub(Vector2d vector) //вычитание векторов, все тоже самое, что и в сумме
{
	x = x - vector.x;
	y = y - vector.y;
}

double Vector2d::scalarMult(Vector2d vector) //скалярное умножение, считаем по формуле
{
	return x * vector.x + y * vector.y;		 //результат - число, вектора не меняются
}

void Vector2d::mult(double a) //умножение вектора на число
{
	x = x * a; //просто умножаем координаты
	y = y * a; //на заданое число
}

void Vector2d::print() //выводим координаты вектора
{
	cout << "x = " << x << "  " << "y = " << y << endl;
}

Vector2d::~Vector2d() //деструктор, используется для очистки. вроде бы его не нужно никак описывать
{
}