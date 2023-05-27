#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

double discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}


void solveWithDiscriminant(double a, double b, double c) {
    double d = discriminant(a, b, c);
    

    if (d >= 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Уравнение: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
        cout << "D = " << b << "^2 - 4 * " << a << " * " << c << endl;
        cout << "Уравнение имеет два корня:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else if (d == 0){
        double x = -b / (2 * a);
        cout << "Уравнение имеет один корень:" << endl;
        cout << "x = " << x << endl;
        } else
        {
            cout << "Уравнение не имеет рациональных корней" << endl;
        }
    
}

void solveWithVietasTheorem(double a, double b, double c) {
    double d = discriminant(a, b, c);
    if (d < 0) {
        cout << "Уравнение не имеет действительных корней." << endl;
    }
    double x1 = (-b + sqrt(d)) / (2 * a);  // Вычисление первого корня
    double x2 = (-b - sqrt(d)) / (2 * a);
    double sum = x1 + x2;  // Вычисление суммы корней
    double product = x1 * x2;  // Вычисление произведения корней
    cout << "Уравнение: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    cout << "x1 + x2 = " << sum << endl;
    cout << "x1 * x2 = " << product << endl;
    cout << "Уравнение имеет корни:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
}


int main(){
    double value = 0;
    double a, b, c;

    int choice;

   do
    {
        cout << "________________________________________________________" << endl;
        cout << "                         МЕНЮ" << endl;
        cout << "1. Типы квадратных уравнений" << endl;
        cout << "2. Решение квадратного уравнения с помощью Дискриминанта" << endl;
        cout << "3. Решение квадратного уравнения с помощью теоремы Виета" << endl;
        cout << "4. Выход" << endl;
        cout << "________________________________________________________" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
       
        switch (choice)
        {
            case 1:
                cout << "----------ТИПЫ КВАДРАТНЫХ УРАВНЕНИЙ------------" << endl;
                cout << "Квадратное уравнение - это алгебраическое уравнение второй степени, общий вид которого: ax^2 + bx + c = 0" << endl;
                cout << "Cуществует восемь типов квадратных уравнений:" << endl;
                cout << "1. 0 = 0" << endl;
                cout << "2. с = 0" << endl;
                cout << "3. ax^2 + bx + c = 0" << endl;
                cout << "4. ax^2 + bx = 0" << endl;
                cout << "5. ax^2 + c = 0" << endl;
                cout << "6. ax^2 = 0" << endl;
                cout << "7. bx + c = 0" << endl;
                cout << "8. 0 = 0" << endl;
                break;

            case 2:
                cout << "Введите коэффициенты квадратного уравнения" << endl;
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "c = ";
                cin >> c;
                while (!(cin >> value)){        //пока не будет введено нормальное число, выполняем цикл
                        cout << "Ошибка! Повторите ввод\n";          //сообщаем об ошибке ввода
                        cin.clear();                //сбрасываем коматозное состояние cin
                        fflush(stdin);
                        return 0;
                    }
                solveWithDiscriminant(a, b, c);
                break;

            case 3:
                cout << "Введите коэффициенты квадратного уравнения" << endl;
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "c = ";
                cin >> c;
                while (!(cin >> value)){        //пока не будет введено нормальное число, выполняем цикл
                        cout << "Ошибка! Повторите ввод\n";          //сообщаем об ошибке ввода
                        cin.clear();                //сбрасываем коматозное состояние cin
                        fflush(stdin);
                        return 0;
                    }
                solveWithVietasTheorem(a, b, c);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
                cout << "Выполните ввод повторно" << endl;
                exit(EXIT_FAILURE);        }
        
    }while (choice != 4);
    return 0;
}

