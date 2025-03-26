#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;
class Vector2D { // interface
    
public:
    static int ObjectNum, ObjectNum2;
    double x, y;
    Vector2D() : x(0.0), y(0.0) {
        //Конструктор за замовчуванням
        ObjectNum++;
        ObjectNum2++;
    }
    Vector2D(const Vector2D &other) : x(other.x), y(other.y) {
        ObjectNum++;
        ObjectNum2++;
        //Конструктор копіювання
    }
    Vector2D(double x, double y) {
        this->x = x;
        this->y = y;
        ObjectNum++;
        ObjectNum2++;
        //Конструктор миттєвої ініціалізації
    }
    ~Vector2D() {
        ObjectNum--;
    }
    //////////////////////////////////////////////////   Setters!
    void SetX(double x) {
        this->x = x;
    }
    void SetY(double y) {
        this->y = y;
    }

    string VectorInfo() {
        ostringstream ss; // Создание потока
        ss << "X= " << this->x << " Y= " << this->y;
        return ss.str(); // Вывод того что в потоке
    }

    void ScaleX(double val) {
        this->x = this->x * val;
        this->y = this->y * val;
    }
    void ReflectionVector() {
        this->x = this->x * -1;
        this->y = this->y * -1;
    }
    double LengthVector() { // Вывод модуля вектора
        return sqrt(pow(this->x, 2)+pow(this->y, 2));
    }
    static Vector2D FromString(const string& str) {
        istringstream ss(str);
        string label;
        double iX;
        double iY;

        ss >> label >> iX; 
        ss >> label >> iY;

        Vector2D Vec(iX, iY);
        return Vec;
    }
    Vector2D operator+(const Vector2D& other) { // Peregruzka +
        return Vector2D(this->x + other.x, this->y + other.y);
    }
    Vector2D operator-(const Vector2D& other) { // Peregruzka +
        return Vector2D(this->x - other.x, this->y - other.y);
    }
    double operator*(const Vector2D& other) { // Peregruzka +
        double res = (this->x * other.x) + (this->y * other.y);
        return res;
    }
    //interface
    static void VectorInterface() {
        Vector2D A, B;
        double a, b, c;
        char select[10];
        string boof, boof2;
        while (1) {
            cout << "\n\tHello! You are in the vector's menu. You can select what to do with your vectors\n\t";
            cout << "Here you can: Add, subtract, multiply on value your vector etc.There is commands: \n\t";
            cout << "Press: \"+\" to add; \n\t\"-\"to subtract;\n\t\"*\" to multiply on VALUE;\n\t\"length\" to get vector's length";
            cout << "\n\t\"-1\" to reflection vector;\n\t\"scalar\" to multiply vector on vector;\n\t";
            cout << "Also, you can enter \"exit\" to exit\n\t";
            cin >> select;
           
            if (strcmp(select, "+") == 0) {
                //PlusVector
                cout << "\n\tEnter vector settings on type: \"val1 val2\" for A vector: ";
                cin >> a >> b;
                Vector2D A(a, b);
                cout << "\n\tEnter vector settings on type: \"val1 val2\" for B vector: ";
                cin >> a >> b;
                Vector2D B(a, b);
                cout << "\n\t" << "You have A(" << A.VectorInfo() << ") B(" << B.VectorInfo() << ")\n\t";
                Vector2D S = A + B;
                cout << "Them sum is: A + B = C(" << S.VectorInfo() << ")\n\t";

            }
            else if (strcmp(select, "-") == 0) {
                //MinusVector
                cout << "\n\tEnter vector settings on type: \"val1 val2\" for A vector: ";
                cin >> a >> b;
                Vector2D A(a, b);
                cout << "\tEnter vector settings on type: \"val1 val2\" for B vector: ";
                cin >> a >> b;
                Vector2D B(a, b);
                cout << "\n\t" << "You have A(" << A.VectorInfo() << ") B(" << B.VectorInfo() << ")\n\t";
                Vector2D S = A - B;
                cout << "Them difference is: A - B = C(" << S.VectorInfo() << ")\n\t";
            }
            else if (strcmp(select, "*") == 0) {
                //multiply on Val
                cout << "\n\tEnter vector settings on type: \"val1 val2 ValForScaleThisVector\" for A vector: ";
                cin >> a >> b >> c;
                Vector2D A(a, b);
                cout << "\n\t" << "You have A(" << A.VectorInfo() << ")";
                A.ScaleX(c);
                cout << "\n\t" << "You have A(" << A.VectorInfo() << ") after scale\n";
            }
            else if (strcmp(select, "length") == 0) {
                //PlusVector
                cout << "\n\tEnter vector settings on type: \"val1 val2\" for A vector: ";
                cin >> a >> b;
                Vector2D A(a, b);
                cout << "\n\t" << "You have A(" << A.VectorInfo() << ")";
                cout << "\n\t" << "The vector length is: " << A.LengthVector();
            }
            else if (strcmp(select, "-1") == 0) {
                cout << "\n\tEnter vector settings on type: \"val1 val2\" for A vector: ";
                cin >> a >> b;
                Vector2D A(a, b);
                cout << "\n\t" << "You have A(" << A.VectorInfo() << ")";
                A.ReflectionVector();
                cout << "\n\t" << "The reflection is: " << A.VectorInfo() << "\n";
            }
            else if (strcmp(select, "scalar") == 0) {
                //PlusVector
                cout << "\n\tEnter vector settings on type: \"val1 val2\" for A vector: ";
                cin >> a >> b;
                Vector2D A(a, b);
                cout << "\tEnter vector settings on type: \"val1 val2\" for B vector: ";
                cin >> a >> b;
                Vector2D B(a, b);
                cout << "\n\t" << "You have A(" << A.VectorInfo() << ") B(" << B.VectorInfo() << ")\n\t";
                cout << "Them difference is: A * B = " << A * B << "\n\t";
            }
            else if (strcmp(select, "exit") == 0) {
                exit(0);
            }
            else { continue; }
        }
    }
};
class Time {
    int hours;
    int minutes;
    int seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {
        //Конструктор за замовчуванням
    }
    Time(const Time &other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds){
        //Конструктор копіювання
    }
    Time(int hour, int min, int sec) {
        hours = hour, minutes = min, seconds = sec;
        if (this->seconds >= 60) {
            while (!(this->seconds <= 59)) {
                this->seconds -= 60;
                this->minutes++;
            }
        }
        if (this->minutes >= 60) {
            while (!(this->minutes <= 59)) {
                this->minutes -= 60;
                this->hours++;
            }
        }
        if (this->hours == 12) {
            this->hours = 0;
        }
    }
    void SetSeconds(int sec) {
        this->seconds = this->seconds + sec;
        if (this->seconds >= 60) {
            while (!(this->seconds <= 59)) {
                this->seconds -= 60;
                this->minutes++;
            }
        }
        if (this->minutes >= 60) {
            while (!(this->minutes <= 59)) {
                this->minutes -= 60;
                this->hours++;
            }
        }
        if (this->hours == 12) {
            this->hours = 0;
        }
        return;
    }
    void SetMinutes(int min) {
        this->minutes = this->minutes + min;
        if (this->minutes >= 60) {
            while (!(this->minutes <= 59)) {
                this->minutes -= 60;
                this->hours++;
            }
        }
        if (this->hours == 12) {
            this->hours = 0;
        }
        return;
    }
    void SetHours(int hour) {
        this->hours = (this->hours + hour) % 12;
        return;
    }
    string CurrentTime() {
        ostringstream ss;
        ss << "Hours: " << this->hours << " Minutes: " << this->minutes << " Seconds: " << this->seconds;
        return ss.str();
    }
    void AddTime(Time clock) {
        //int s = this->seconds + clock.seconds;
        this->SetSeconds(clock.seconds);
        //int m = this->minutes + clock.minutes;
        this->SetMinutes(clock.minutes);
        int h = this->hours + clock.hours;
        this->SetHours(clock.hours);
        return;
    }
    void MinusTime(Time clock) {
        int s = -1 * clock.seconds;
        this->SetSeconds(s);
        int m = -1 * clock.minutes;
        this->SetMinutes(m);
        int h = -1 * clock.hours;
        this->SetHours(h);
        return;
    }
    void SetTime0() {
        this->hours = 0;
        this->seconds = 0;
        this->minutes = 0;
    }
    static void TimeInterface() {
        Time Cl1, Cl2;
        int a, b, c;
        char select[10];
        while (1) {
            cout << "\n\tHello! You are in the clock. You can select what to do with your time\n\t";
            cout << "Here you can enter the time and watch, how it will be on clock. Also you can enter 2 times and get sum\n\t";
            cout << "So, you can select: operations with 2 times(operations) or just see the current time on clock(current): \n\t";
            cin >> select;
            if (strcmp(select, "operations") == 0) {
                cout << "\n\tEnter the first time through space (hours minutes seconds): ";
                cin >> a >> b >> c;
                Cl1.SetHours(a);
                Cl1.SetMinutes(b);
                Cl1.SetSeconds(c);

                cout << "\tEnter the second time through space (hours minutes seconds): ";
                cin >> a >> b >> c;
                Cl2.SetHours(a);
                Cl2.SetMinutes(b);
                Cl2.SetSeconds(c);

                cout << "\n\tThe first clock is: " << Cl1.CurrentTime();
                cout << "\n\tThe second clock is: " << Cl2.CurrentTime();

                cout << "\n\tNow, enter the act: plus(+), or minus(-): ";
                cin >> select;
                if (strcmp(select, "+") == 0) {
                    Cl1.AddTime(Cl2);
                    cout << "\n\t" << Cl1.CurrentTime();
                    Cl1.SetTime0();
                    Cl2.SetTime0();
                    cout << "\n\tPress \"exit\" to close program. Else to continue: ";
                    cin >> select;
                    if (strcmp(select, "exit") == 0) {
                        exit(0);
                    }
                    else {
                        cout << endl;
                        continue;
                    }
                }
                else if (strcmp(select, "-") == 0) {
                    Cl1.MinusTime(Cl2);
                    cout << "\n\t" << Cl1.CurrentTime();
                    Cl1.SetTime0();
                    Cl2.SetTime0();
                    cout << "\n\tPress \"exit\" to close program. Else to continue: ";
                    cin >> select;
                    if (strcmp(select, "exit") == 0) {
                        exit(0);
                    }
                    else {
                        cout << endl;
                        continue;
                    }
                }
            }
            else if (strcmp(select, "current") == 0) {
                cout << "\tEnter the second time through space (hours minutes seconds): ";
                cin >> a >> b >> c;
                Cl2.SetHours(a);
                Cl2.SetMinutes(b);
                Cl2.SetSeconds(c);
                cout << "\n\t" << Cl2.CurrentTime();
                Cl2.SetTime0();
                cout << "\n\tPress \"exit\" to close program. Else to continue: ";
                cin >> select;
                if (strcmp(select, "exit") == 0) {
                    exit(0);
                }
                else {
                    cout << endl;
                    continue;
                }
            }
            else {
                Cl1.SetTime0();
                Cl2.SetTime0();
                cout << endl;
                continue;
            }

        }
    }
};

int Vector2D::ObjectNum = 0; // Инициализация переменной с выделением памяти для счетчика
int Vector2D::ObjectNum2 = 0;

int main()
{
   setlocale(LC_ALL, "Russian");
   Time::TimeInterface();
   //Vector2D::VectorInterface();
}













// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
