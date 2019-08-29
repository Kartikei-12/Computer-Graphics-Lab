#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void my_draw_line(int x1, int y1, int x2, int y2)
{
    int sign = (x1>x2)? -1 : 1;
    int dx = x2-x1, dy = y2-y1;
    int pK = 2*(dy-dx);
    for(int x=x1, y=y1; x < x2; x += sign)
    {
        putpixel(x, y, WHITE);
        if(pK < 0)
            pK += 2*dy;
        else
        {
            ++y;
            pK += 2*(dy-dx);
        }
    }
}

int main()
{
    int x1,x2,y1,y2;
    cout<<"Enter points: ";
    cin>>x1>>y1>>x2>>y2;
    initwindow(400, 300, "Graphics Window");
    my_draw_line(x1, y1, x2, y2);
    while(!kbhit())
        delay(100);
    return 0;
}