#include <iostream>
using namespace std;

class football_ground
{
private:
    double side_length;

public:
    football_ground(double length)
    {
        side_length = length;
    }
    football_ground()
    {
        side_length = 0;
    }

    double area()
    {
        return side_length * side_length;
    }
    double get_length()
    {
        return side_length;
    }
};
class cricket_ground : public football_ground
{
private:
    double width, length;

public:
    cricket_ground(double side_length) : football_ground(side_length)
    {
        width = get_length();
        length = get_length() * 2;
    }
    double area()
    {
        double A = (get_length() *2 * get_length());
        return A;
    }
};

class robot_playing_area : public football_ground

{
private:
    double radius;

public:
    robot_playing_area (double side_length) : football_ground(side_length)
    {
        radius = get_length();
    }

    double area()
    {

        double A=  (get_length() * get_length() * 3.142);
        return A;
    }
};
int main()
{
    football_ground fg(2) ;
    cricket_ground cg(2);
    robot_playing_area rg(2);



    cout<<"footbal ground area: "<< fg.area()<<endl;
    cout<<"cricket ground area: "<< cg.area()<<endl;
    cout<<"robot playing ground area: "<< rg.area()<<endl;

    return 0;
}