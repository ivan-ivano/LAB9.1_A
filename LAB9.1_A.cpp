#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

enum Spec { Comp_Nauk, Inf, Mat_Econ, Fiz_Inf, Trud_Navch };
string specStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
    string prizv;
    int kyrs;
    Spec spec;
    int fiz;
    int mat;
    int inf;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int PercentWithoutThrees(Student* p, const int N);
void PrintPrizv(Student* p, const int N);

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);

    cout << "Відсоток студентів, які вчаться без трійок: " << fixed << setprecision(2) << PercentWithoutThrees(p, N) << "%" << endl;
    cout << endl;
    PrintPrizv(p, N);


    return 0;
}


void Create(Student* p, const int N)
{
    int spec;
    string prizvList[] = {
        "Панчишин", "Сидоренко", "Коваленко", "Мельник", "Мороз", "Григоренко", "Ковальчук", "Павленко",
        "Бойко", "Лисенко", "Шевченко", "Бондаренко", "Ткаченко", "Кузьменко", "Козак", "Кучер", "Василенко", "Остапенко",
        "Попов", "Литвин", "Гончаренко", "Панченко", "Єфіменко", "Кравченко", "Захарченко", "Онопрієнко", "Савченко"
    };
    for (int i = 0; i < N; i++)
    {
        p[i].prizv = prizvList[rand() % 10];
        p[i].kyrs = rand() % 4 + 1;
        p[i].spec = static_cast<Spec>(rand() % 5);
        p[i].fiz = rand() % 5 + 1;
        p[i].mat = rand() % 5 + 1;
        p[i].inf = rand() % 5 + 1;
    }
}


void Print(Student* p, const int N)
{
    cout << "=================================================================================================" << endl;
    cout << "|  № | Прізвище       | Курс | Спеціальність                 | Фізика | Математика | Інформатика |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(15) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].kyrs << " "
            << "| " << setw(30) << left << specStr[p[i].spec]
            << "| " << setw(6) << setprecision(2) << fixed << right << p[i].fiz
            << " | " << setw(10) << setprecision(2) << fixed << right << p[i].mat
            << " | " << setw(11) << setprecision(2) << fixed << right << p[i].inf << " |"
            << endl;
    }
    cout << "=================================================================================================" << endl;
    cout << endl;
}

int PercentWithoutThrees(Student* p, const int N)
{
    int Count = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].fiz > 3 && p[i].mat > 3 && p[i].inf > 3)
        {
            Count++;
        }
    }

    return (Count * 100) / N;
}

void PrintPrizv(Student* p, const int N)
{
    cout << "Прізвища студентів, які отримали з фізики оцінки '4' або '5':" << endl;
    for (int i = 0; i < N; i++)
    {
        if (p[i].fiz >= 4)
        {
            cout << p[i].prizv << endl;
        }
    }
    cout << endl;
}