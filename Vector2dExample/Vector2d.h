#pragma once
#include <string>
#include <iostream>
#include <math.h>
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
	double angle(Vector2d); //угол между 2 векторами
	double length(); //длина вектора
	Vector2d operator+(const Vector2d& vector); //перегрузка операции сложения
	Vector2d operator-(const Vector2d& vector); //перегрузка операции вычитания
	double operator*(const Vector2d& vector);	//перегрузка операции умножения вектора на вектор (скалярное произведение)
	Vector2d operator*(const double number);    //перегрузка операции умножения вектора на число
	friend Vector2d operator*(double, Vector2d&);  //перегрузка операции умножения вектора на число
	Vector2d& operator++();	  //перегрузка операции инкремента				   
	Vector2d operator++(int); //перегрузка операции инкремента		   
	Vector2d& operator--();	  //перегрузка операции декремента				  
	Vector2d operator--(int); //перегрузка операции декремента					   
	const Vector2d& operator += (const Vector2d&); //перегрузка операции присвоения после сложения
	const Vector2d& operator -= (const Vector2d&); //перегрузка операции присвоения после вычитания
	const Vector2d& operator *= (const double);    //перегрузка операции присвоения после умножения
	operator string(); //перегрузка операции явного преобразования в string
};