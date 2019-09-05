#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void my_draw_line(int x1, int y1, int x2, int y2)
{ 
    double m = ((double)(y2-y1))/((double)(x2-x1));
    double incX = (m<1)? 1 : (1/m);
    double incY = (m<1)? m : 1;
    double x_curr=x1, y_curr=y1;
    while(floor(x_curr) != x2 && floor(y_curr) != y2)
    {
        putpixel(floor(x_curr), floor(y_curr), WHITE);
        x_curr += incX;
        y_curr += incY;
    }
}

int main()
{
    initwindow(400, 300, "First Sample");
    // line(2, 10, 8, 17);
    my_draw_line(2, 10, 40, 50);
    while (!kbhit())
        delay(200);   
    return 0;
}