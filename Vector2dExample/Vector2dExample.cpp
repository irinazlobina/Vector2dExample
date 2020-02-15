// Vector2dExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <clocale>
#include "Vector2d.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Vector2d Vector(3, 3, 7, 7);
	cout << "Первый вектор: ";
	Vector.print();

	cout << "Умножаем первый вектор на 2.5: ";
	Vector.mult(2.5);
	Vector.print();


	cout << "Второй вектор: ";
	Vector2d Vector2(0.5, 0.5);
	Vector2.print();

	cout << "Скалярное произведение векторов: " << Vector.scalarMult(Vector2) << endl;

	cout << "Создаем третий вектор, копируя первый: ";
	Vector2d Vector3(Vector);
	Vector3.print();

	cout << "Меняем координаты первого вектора: ";
	Vector.setx(5.5);
	Vector.sety(5.5);
	Vector.print();

	cout << "Вычитаем из первого вектора третий: ";
	Vector.sub(Vector3);
	cout << "x = " << Vector.getx() << "  " << "y = " << Vector.gety() << endl;
}
