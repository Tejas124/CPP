#include<iostream>
using namespace std;

class distance2;
class distance1
{
    private:
    int meter;
    public:
    distance1()
    {
        meter=0;
    }
    distance1(int m)
    {
        meter=m;
    }
    void display();
    friend distance1 add(distance1,distance2);
    friend distance2 add(distance2,distance1);
};

class distance2{
    private:
    int centimeter;
    public:
    distance2()
    {
        centimeter=0;
    }
    distance2(int c)
    {
        centimeter=c;
    }
    void display();
    friend distance1 add(distance1,distance2);
    friend distance2 add(distance2,distance1);
};

distance1 add(distance1 a,distance2 b)
{
    distance1 temp;
    temp.meter=a.meter+b.centimeter/100;
    return temp;
}

void distance1::display()
{
    cout<<"\nAddition in meter is: "<<meter<<" m";
}

distance2 add(distance2 a,distance1 b)
{
    distance2 temp;
    temp.centimeter=a.centimeter+b.meter*100;
    return temp;
}

void distance2::display()
{
    cout<<"\nAddition in centimeter is: "<<centimeter<<" cm";
}

int main()
{
    int mt;
    int ct;
    cout<<"\nEnter the meter value: ";
    cin>>mt;
    cout<<"\nEnter the centimeter value: ";
    cin>>ct;

    distance1 m1(mt),m2;
    distance2 c1(ct),c2;
    

    int ch;
    
    
    do{
        cout<<"\n1.Addition in meter\n2.Addition in centimeter\n3.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                m2=add(m1,c1);
                m2.display();
                break;
            case 2:
                c2=add(c1,m1);
                c2.display();
                break;
            case 3:
                exit(0);
        }
    }while(ch!=3);

    return 0;
}