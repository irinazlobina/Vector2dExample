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
	cout << "x:" << x << "	" << "y:" << y << endl;
}

double Vector2d::length() //по формуле считает длину вектора, результат - число
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

double Vector2d::angle(Vector2d v1) //находит косинус угла между векторами, результат - число
{
	return this->scalarMult(v1) / (this->length()*v1.length());
}

Vector2d Vector2d::operator+(const Vector2d& vector) //перегрузка операции сложения. это для того, чтобы можно было писать a+b, а не a.sum(b)
{
	return Vector2d(x + vector.x, y + vector.y); //возвращает вектор, который является суммой 2 векторов. сами эти 2 вектора не изменяются
}

Vector2d Vector2d::operator-(const Vector2d& vector) //перегрузка вычитания, работает как сложение
{
	return Vector2d(x - vector.x, y - vector.y);
}

double Vector2d::operator*(const Vector2d& vector) //перегрузка операции умножения
{
	return x * vector.x + y * vector.y; //в данном случае результат - число, так как именно эта функция описывает умножение 2 векторов
}

Vector2d Vector2d::operator*(const double number) //перегрузка операции умножения
{
	return Vector2d(x * number, y * number); //результат - вектор, т.к. умножаем вектор на число
}

Vector2d operator*(double number, Vector2d& vector) //тоже операция умножения вектора на число, чтобы 4*а и а*4 работали одинаково (без этого не будет)
{
	return vector * number; //результат - вектор
}

Vector2d& Vector2d::operator++() //перегрузка операции инкремента ++a
{
	x++; //значение х и у
	y++; //увеличивается на 1
	return *this; //вектор, для которого вызвали эту операцию, изменится
}

Vector2d Vector2d::operator++(int) //перегрузка операции инкремента а++
{
	Vector2d temp(x, y);
	x++;
	y++;
	return temp; //изменяет вектор
}

Vector2d& Vector2d::operator--() //перегрузка операции декремента --a
{
	x--;
	y--;
	return *this; //изменяет вектор
}

Vector2d Vector2d::operator--(int) //перегрузка операции декремента a--
{
	Vector2d temp(x, y);
	x--;
	y--;
	return temp; //изменяет вектор
}

const Vector2d& Vector2d::operator+= (const Vector2d&vector) //перегрузка операции присваивания после сложения (a+=b)
{
	x += vector.x;
	y += vector.y;
	return *this; //изменяет вектор
}

const Vector2d& Vector2d::operator-= (const Vector2d& vector) //перегрузка операции присваивания после вычитания (a-=b)
{
	x -= vector.x;
	y -= vector.y;
	return *this; //изменяет вектор
}

const Vector2d& Vector2d::operator*= (double number) //перегрузка операции присваивания после умножения, работает лишь умножение на число (a*=4)
{
	x *= number;
	y *= number;
	return *this; //изменяет вектор
}

Vector2d::operator string() //перегрузка операции явного преобразования в string, используется для вывода. пример вывода суммы векторов: (string)(a + b)
{
	string s = "(" + to_string(x) + "; " + to_string(y) + ")";
	return s;
}

Vector2d::~Vector2d() //деструктор, используется для очистки. вроде бы его не нужно никак описывать
{
}