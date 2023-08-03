#include<iostream>

/*
Перегрузка унарных операторов
Задание
В  классе дробь реализовать перегрузку следующих унарных
оераторов:
инкримент "++"
декримент "--"
унарный минус "-"
унарный плюс "+"
Обратить внимание на конструкторы класса и те которые представляются нужными отметить
как explicit. выбор пояснить комментарием
Добавить в класс методы: - получения целой части от дроби - получения дробной части от
дроби - сокращение дроби(уменьшение знаменателя до возможного минимума) - получение
обратной дроби
*/

// GPT так решил
/*
Вот пример реализации класса "Дробь" с перегрузкой указанных унарных операторов и дополнительными методами:

```cpp
#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    explicit Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    // Унарный оператор инкремента (префиксный)
    Fraction operator++ () {
        numerator += denominator;
        return *this;
    }

    // Унарный оператор декремента (префиксный)
    Fraction operator-- () {
        numerator -= denominator;
        return *this;
    }

    // Унарный оператор минус
    Fraction operator- () {
        return Fraction(-numerator, denominator);
    }

    // Унарный оператор плюс
    Fraction operator+ () {
        return *this;
    }

    // Метод для получения целой части дроби
    int getWholePart() {
        return numerator / denominator;
    }

    // Метод для получения дробной части дроби (в виде новой дроби)
    Fraction getFractionPart() {
        int wholePart = getWholePart();
        int newNumerator = numerator - wholePart * denominator;
        return Fraction(newNumerator, denominator);
    }

    // Метод для сокращения дроби
    void reduce() {
        int div = gcd(numerator, denominator);
        numerator /= div;
        denominator /= div;
    }

    // Метод для получения обратной дроби
    Fraction getReciprocal() {
        return Fraction(denominator, numerator);
    }

    // Вспомогательная функция для нахождения НОД двух чисел
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    // Дружественная функция перегрузки оператора вывода
    friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
};

std::ostream& operator<< (std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}

int main() {
    Fraction f1(5, 3);
    std::cout << "f1: " << f1 << std::endl;

    Fraction f2 = ++f1;
    std::cout << "f1 after ++: " << f1 << std::endl;
    std::cout << "f2: " << f2 << std::endl;

    Fraction f3 = --f2;
    std::cout << "f2 after --: " << f2 << std::endl;
    std::cout << "f3: " << f3 << std::endl;

    Fraction f4 = -f3;
    std::cout << "f3 after unary minus: " << f3 << std::endl;
    std::cout << "f4: " << f4 << std::endl;

    Fraction f5 = +f4;
    std::cout << "f4 after unary plus: " << f4 << std::endl;
    std::cout << "f5: " << f5 << std::endl;

    std::cout << "Whole part of f5: " << f5.getWholePart() << std::endl;

    Fraction f6 = f5.getFractionPart();
    std::cout << "Fraction part of f5: " << f6 << std::endl;

    f6.reduce();
    std::cout << "f6 after reduction: " << f6 << std::endl;

    Fraction f7 = f6.getReciprocal();
    std::cout << "Reciprocal of f6: " << f7 << std::endl;

    return 0;
}
```

В выводе программы видно, как работают перегруженные унарные операторы,
методы получения целой и дробной части дроби,
сокращения дроби и получения обратной дроби.

*/

class Fraction
{
private:
    int _number1{ 0 }; // Делимое
    int _number2{ 1 }; //Делитель

    // Вспомогательная функция для нахождения НОД двух чисел    
    int  gcd(int a, int b)
    {
        a = abs(a), b = abs(b);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

public:
    explicit Fraction(int num1, int num2) :_number1{ num1 }, _number2{ num2 } { }

    void Show()
    {
        std::cout << "Numerator: " << _number1 << std::endl;
        std::cout << "Denominator: " << _number2 << std::endl;
    }

    // Унарный оператор инкремента (префиксный)
    Fraction& operator++ ()
    {
        //_number1 += _number2;
        _number1++;
        _number2++;
        return *this;
    }
    // Унарный оператор декремента (префиксный)
    Fraction& operator--()
    {
        //_number1 -= _number2;
        _number1--;
        _number2--;
        return *this;
    }
    // Унарный минус
    Fraction& operator -() 
    {
        _number1 * -1;
        return*this;
    }
    
    // Пишем одно значение с отризвтельным знаком(-) 
    //иначе будет +
    // 
    // Унарный плюс

    Fraction& operator+() { return *this; }

    // Метод для получения целой части дроби
    int wholeFractionPart() { return _number1 / _number2; }// Использование типа int не выводит дробную часть
    //т.к это целочисленный тип данных

    // Метод для получения дробной части дроби (в виде новой дроби)
    Fraction fractionalPartFrection()
    {
        int wholePart = wholeFractionPart();
        int newNamber = _number1 - wholePart * _number2;
        return Fraction(newNamber, _number2);
    }

    // Сокращение дробной части
    void sokrdrob()
    {
        int x = gcd(_number1, _number2);
        _number1 /= x;
        _number2 /= x;
    }
};

int main()
{
	setlocale(LC_ALL, "Rus");
    Fraction fraction(10, 20);
    std::cout << "Префиксный инкремент : " << std::endl;
    ++fraction;
    fraction.Show();
    std::cout << std::endl << std::endl;

    std::cout << "Префиксный декремент : " << std::endl;
    --fraction;
    fraction.Show();
    std::cout << std::endl << std::endl;

    std::cout << "Унарный (-) : " << std::endl;
    fraction.operator-();
    fraction.Show();
    std::cout << std::endl << std::endl;

    std::cout << "Унарный (+) : " << std::endl;
    fraction.operator+();
    fraction.Show();
    std::cout << std::endl << std::endl;

    std::cout << "Метод для получения целой части дроби : " << std::endl;
    std::cout << "Целая часть дроби: " << fraction.wholeFractionPart() << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Метод для получения дробной части дроби (в виде новой дроби) : " << std::endl;
    fraction.fractionalPartFrection().Show();
    std::cout << std::endl << std::endl;

    std::cout << "Сокращение дробной части : " << std::endl;
    fraction.sokrdrob();
    fraction.Show();
    std::cout << std::endl << std::endl;

	return 0;
}