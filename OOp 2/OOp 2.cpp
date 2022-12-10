// OOp 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
using namespace std;
class Bricks {
protected:
    int Size, Mass, Quanity;
public:
    Bricks() :Size(0), Mass(0), Quanity(0)
    {
        printf("Bricks()\n");

    }
    Bricks(int _Size, int _Mass, int _Quanity) :Size(_Size), Mass(_Mass), Quanity(_Quanity)
    {
        printf("Bricks(int _Size, int _Mass,int _Quanity)\n");

    }
    Bricks(const Bricks& p) :Size(p.Size), Mass(p.Mass), Quanity(p.Quanity) {
        printf("Bricks(const Bricks &p)\n");
        Quanity = p.Quanity;
        Size = p.Size;
        Mass = p.Mass;

    }
    ~Bricks() {
        printf("~Bricks()\n");
        printf("%d, %d %d\n", Size, Mass, Quanity);


    }
    void NewVal(int dM, int dS, int dQ) {
        Mass = dM;
        Size = dS;
        Quanity = dQ;
    }
    void MakeMoreQu(int dQ) {
        Quanity = Quanity + dQ;
    }
    void reset();

};
void Bricks::reset()
{
    Mass = 0;
    Size = 0;
    Quanity = 0;
}
class ColoredBricks :public Bricks {
private:
    string Color;
public:
    ColoredBricks() :Bricks()
    {
        printf("ColoredBricks()\n");
        Color = "White";
    }
    ColoredBricks(int _Size, int _Mass, int _Quanity, string colors) :Bricks(_Size, _Mass, _Quanity)
    {
        printf("ColoredBricks(int _Size,int _Mass, int Quanity,string colors)\n");
        this->Color = colors;
    }
    ColoredBricks(const ColoredBricks& p) {
        Color = p.Color;
        Size = p.Size;
        Mass = p.Mass;
        Quanity = p.Quanity;

        printf("ColoredBricks(const ColoredBricks &p)\n");
    }
    ~ColoredBricks() {
        printf("%d, %d, %d Color=%s\n", Mass, Size, Quanity, Color);
        printf("~ColoredBricks()\n");
    }
    void Change_Color(int new_Color) {
        Color = new_Color;
    }

};


class House {
private:
    Bricks Length;
    Bricks Width;
public:
    House()
    {

        printf("House()\n");

    }
    House(int _Size1, int _Mass1, int _Quanity1, int _Size2, int _Mass2, int _Quanity2) :Length(_Size1, _Mass1, _Quanity1), Width(_Size2, _Mass2, _Quanity2)
    {

        printf("House(int _Size1, int _Mass1,int _Quanity1,int _Size2,int _Mass2, int _Quanity2)\n");

    }
    House(const House& s) :Length(s.Length), Width(s.Width) {

        printf("House(const House &p)\n");

    }
    ~House() {

        printf("~House()\n");

    }

};




int main() {
    {
        setlocale(LC_ALL, "rus");
        cout << "Static" << endl;
        Bricks p;
        Bricks p1(5, 7, 9);
        Bricks p3(p1);
        cout << endl;

        


        House p4;
        cout << endl;
        House p5(1, 2, 3, 4, 5, 6);
        cout << endl;
        House p6(p5);




    }
}
