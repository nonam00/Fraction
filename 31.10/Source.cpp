#include<iostream>
#include<Windows.h>

class Fraction
{

public:

	//  онструктор по умолчанию
	Fraction() : chisl{ 1 }, znam{ 1 } {}

	Fraction(int _chisl, int _znam) : chisl{ _chisl }, znam{ _znam } {}

	//  онструктор копировани€
	Fraction(const Fraction& obj) : chisl{ obj.chisl }, znam{ obj.znam } {}

	//  онструктор переноса
	Fraction(Fraction& obj) noexcept : chisl{ obj.chisl }, znam{ obj.znam } {}

	//деструктор
	~Fraction() { std::cout << " "; }

	// ќператор копировани€
	Fraction& operator=(Fraction& obj)
	{
		chisl = obj.chisl;
		znam = obj.znam;
		return *this;
	}

	friend Fraction operator+(const Fraction& obj1, const Fraction& obj2)
	{
		return Fraction(obj1.chisl * obj2.znam + obj2.chisl * obj1.znam, obj2.znam * obj1.znam);
	}

	friend Fraction operator-(const Fraction& obj1, const Fraction& obj2)
	{
		return Fraction(obj1.chisl * obj2.znam - obj2.chisl * obj1.znam, obj2.znam * obj1.znam);
	}

	friend Fraction operator*(const Fraction& obj1, const Fraction& obj2)
	{
		return Fraction(obj1.chisl * obj2.chisl, obj2.znam * obj1.znam);
	}

	friend Fraction operator/(const Fraction& obj1, const Fraction& obj2)
	{
		return Fraction(obj1.chisl * obj2.znam, obj1.znam * obj2.chisl);
	}

	Fraction& operator+=(const Fraction& obj2)
	{

		chisl = chisl * obj2.znam + obj2.chisl * znam;
		znam = obj2.znam * znam;
		return*this;
	}

	Fraction& operator-=(const Fraction& obj2)
	{
		chisl = chisl * obj2.znam - obj2.chisl * znam;
		znam = obj2.znam * znam;
		return*this;
	}

	Fraction& operator*=(const Fraction& obj2)
	{
		chisl *= obj2.chisl;
		znam *= obj2.znam;
		return*this;
	}

	Fraction& operator/=(const Fraction& obj2)
	{
		chisl *= obj2.znam;
		znam *= obj2.chisl;
		return*this;
	}

	void pruning() //упрощение дроби
	{
		int number = 1;
		for (int i = 1; i < znam; i++) 
			if (chisl % i == 0 && znam % i == 0)
				number = i;
		chisl /= number;
		znam /= number;
	}

	//вывод
	friend std::ostream& operator<<(std::ostream& out, const Fraction& obj)
	{
		if (obj.chisl % obj.znam == 0)
			out << (obj.chisl / obj.znam) << std::endl;
		else
			out << obj.chisl << "/" << obj.znam << std::endl;
		return out;
	}

protected:

	int chisl;		//числитель
	int znam;		//знаменатель

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction f1(6, 2);
	Fraction f2(3, 4);
	Fraction f3;
	f3+=f2;
	f3.pruning();
	std::cout << f1 << std::endl;

	return 0;
}