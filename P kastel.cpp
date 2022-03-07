#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void Bazi();
int random(int , int );

int main()
{
    int voroodi;
    srand(time(0));
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color 70");
    while(true)
    {
        cout << "Be bazi 'KASTEL' khosh amadid\n";
        SetConsoleTextAttribute(h, 0x72);
        cout << "Shoroe bazi '1'\n";
        SetConsoleTextAttribute(h, 0x74);
        cout << "Exit '0'\n";
        SetConsoleTextAttribute(h, 0x70);
        
        cin >> voroodi;
     
        switch (voroodi)
        {
        case 1:
            Bazi();
            break;
        case 0:
            return 0;
        }
    }
    
    return 0;
}

void Bazi()
{

}

int random(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}