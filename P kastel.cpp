#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void Bazi();
int Random_Number(int , int );
string Random_Kart();
void Kart_new(int);
void Emtiaz();
void Namayeshgah_show(int);
void Daste_Kart_show(int);
struct New_Kart
{
    char zombie = '\0';
    int adad = 0;
};

New_Kart Daste_Kart[18];
New_Kart Namayeshgah[36];
int main()
{
    system("cls");
    int voroodi;
    srand(time(0));
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Be bazi 'KASTEL' khosh amadid\n";
        SetConsoleTextAttribute(h, 0x2);
        cout << "Shoroe bazi '1'\n";
        SetConsoleTextAttribute(h, 0x4);
        cout << "Exit '0'\n";
        SetConsoleTextAttribute(h, 0xF);
        
        cin >> voroodi;
     
        switch (voroodi)
        {
        case 1:
            Bazi();
            break;
        case 0:
            return 0;
        }
    Emtiaz();
    string again;
    cout << "\n\nDo you want to play again (yes|no) ? ";
    cin >> again;
    if (again == "yes")
        main();
    return 0;
}

void Bazi()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int t_Bazikonan;
    do
    {
        cout << "Tedad bazikonan ra vared namaeid(2-6) : ";
        cin >> t_Bazikonan;
    } while (t_Bazikonan > 6 || t_Bazikonan <= 1);
    for (int i = 1; i <= t_Bazikonan; i++)
        for (int j = 0; j < 3; j++)
           Kart_new((i-1)*3+j);
        
    int Nobat=1;
    do
    {
        
        cout << "Nobat Bazikon Shomare " << Nobat << " Ready ? (press any key)";
        getchar();
        getchar();
        Namayeshgah_show(t_Bazikonan);
        cout << "Daste kart : ";
        for (int i = 0; i < 3; i++)
        {
            Daste_Kart_show((Nobat - 1) * 3 + i);
        }
        cout << endl;
        int Kart_Bazikon , Kart_sotoon , Kart_Bazishode;
        do
        {
            cout << "Moghabele che kasi kart ra bazi mikonid (Bazikonan 1-"<<t_Bazikonan<<" ) ? ";
            cin >> Kart_Bazikon;
            cout << "Kodam sotoon (1-6) ? ";
            cin >> Kart_sotoon;
            cout << "kodam Kart (1-3)? ";
            cin >> Kart_Bazishode;
        } while (Kart_Bazikon > t_Bazikonan ||Kart_Bazikon < 1 || Kart_sotoon > 6 ||Kart_sotoon < 1 ||Kart_Bazishode > 3||Kart_Bazishode < 1 );
        Namayeshgah[((Kart_Bazikon - 1) * 6) + (Kart_sotoon - 1)] = Daste_Kart[((Nobat - 1) * 3) + (Kart_Bazishode - 1)];
        for (int i = 0; i < 6; i++)
        {
            int temp = 0;
            if (Namayeshgah[(Kart_Bazikon - 1) * 6 + i].adad == Namayeshgah[((Kart_Bazikon - 1) * 6) + (Kart_sotoon - 1)].adad && Namayeshgah[(Kart_Bazikon - 1) * 6 + i].zombie == Namayeshgah[((Kart_Bazikon - 1) * 6) + (Kart_sotoon - 1)].zombie)
                ++temp;

            if (temp >= 2)
            {
                Namayeshgah[((Kart_Bazikon - 1) * 6) + (Kart_sotoon - 1)].adad = 0;
                Namayeshgah[((Kart_Bazikon - 1) * 6) + (Kart_sotoon - 1)].zombie = '\0';
            }
        }
        Kart_new(((Nobat - 1) * 3) + (Kart_Bazishode - 1));
        if (Nobat == t_Bazikonan)
            Nobat = 0;
        ++Nobat;
        //shart payan dor
        int t_namayeshgah = 0;
        bool End = false;
        for (int i = 0; i < 6; i++)
        {
            t_namayeshgah = 0;
            for (int j = 0; j < 6; j++)
                if (Namayeshgah[(i) * 6 + j].adad != 0)
                    t_namayeshgah++;
            if (t_namayeshgah >= 6)
                End = true;
        }
        system("cls");
        if (Nobat + (3 * t_Bazikonan) > 90 || End == true)
            break;
    } while (true);
}

void Kart_new(int Kart_shomare)
{
    int Adad = Random_Number(1, 15);
    string Kart_esm = Random_Kart();
    if (Kart_esm == "Goorbe")
        Daste_Kart[Kart_shomare].zombie = 'G';
        
    else if (Kart_esm == "Kadoo")
        Daste_Kart[Kart_shomare].zombie = 'K';
       
    else if (Kart_esm == "Moomiaie")
        Daste_Kart[Kart_shomare].zombie = 'M';
        
    Daste_Kart[Kart_shomare].adad = Adad;
}

int Random_Number(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

string Random_Kart()
{
    int random_num = Random_Number(1, 3);
    switch (random_num)
    {
    case 1:
        return "Goorbe";
    case 2:
        return "Kadoo";
    case 3:
        return "Moomiaie";
    default:
        return Random_Kart();
    }
    return NULL;
}

void Namayeshgah_show(int t_Bazikonan)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Namayeshgah moghabel bazikonan (sotoon):\n";
    for (int i = 0; i < t_Bazikonan; i++)
    {
        cout << i + 1 << " : ";
        for (int j = 0; j < 6; j++)
        {
            if (Namayeshgah[i*6+j].adad != 0)
            {
                if (Namayeshgah[i*6+j].zombie == 'G')
                    SetConsoleTextAttribute(h, 0xB);

                else if (Namayeshgah[i*6+j].zombie == 'K')
                    SetConsoleTextAttribute(h, 0x6);

                else if (Namayeshgah[i*6+j].zombie == 'M')
                    SetConsoleTextAttribute(h, 0x7);
                cout << Namayeshgah[i*6+j].adad <<" ("<<j+1<<")"<< "   ";
            }
            SetConsoleTextAttribute(h, 0xF);
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 0x7);
}

void Daste_Kart_show(int Kart_shomare)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (Daste_Kart[Kart_shomare].zombie == 'G')
        SetConsoleTextAttribute(h, 0xB);

    else if (Daste_Kart[Kart_shomare].zombie == 'K')
        SetConsoleTextAttribute(h, 0x6);

    else if (Daste_Kart[Kart_shomare].zombie == 'M')
        SetConsoleTextAttribute(h, 0x7);

    cout << Daste_Kart[Kart_shomare].adad << "(" << (Kart_shomare%3) + 1 << ")" << "    ";
    SetConsoleTextAttribute(h, 0xF);
}

void Emtiaz()
{

}