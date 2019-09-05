// Author: Kartikei Mittal
// Flood fill
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int my_SIZE[] = {800,600};
int my_ORIGIN[] = {my_SIZE[0]/4, my_SIZE[1]/4};
void my_putpixel(int x, int y, int c) {
    putpixel(x+my_ORIGIN[0], my_SIZE[1]-(y+my_ORIGIN[1]), c);
}
int my_getpixel(int x, int y) {
    return getpixel(x+my_ORIGIN[0], my_SIZE[1]-(y+my_ORIGIN[1]));
}
void draw_x_axis() {for(int i=-my_SIZE[0]; i<my_SIZE[0]; i+=4) my_putpixel(i, 0, RED);}
void draw_y_axis() {for(int i=-my_SIZE[1]; i<my_SIZE[1]; i+=4) my_putpixel(0, i, RED);}

void my_draw_line(int x1, int y1, int x2, int y2, int color)
{
    if(x1 == x2)
    {
        for(int y=min(y1,y2); y!=max(y1,y2); ++y)
            my_putpixel(x1, y, WHITE);
        return ;    
    }
    int sign = (x1>x2)? -1 : 1;
    int dx = x2-x1, dy = y2-y1;
    int pK = 2*(dy-dx);
    for(int x=x1, y=y1; x < x2; x += sign)
    {
        my_putpixel(x, y, color);
        if(pK < 0)
            pK += 2*dy;
        else
        {
            ++y;
            pK += 2*(dy-dx);
        }
    }
}


void fill(int x, int y)
{
    delay(1);
    my_putpixel(x, y, RED);
    if(my_getpixel(x, y+1) == BLACK) // UP
        fill(x, y+1);
    if(my_getpixel(x, y-1) == BLACK) // DOWN
        fill(x, y-1);
    if(my_getpixel(x-1, y) == BLACK) // LEFT
        fill(x-1, y);
    if(my_getpixel(x+1, y) == BLACK) // RIGHT
        fill(x+1, y);
}

void draw_H()
{
    my_draw_line(10, 0, 10, 100, WHITE);
    my_draw_line(40, 0, 40, 40, WHITE);
    my_draw_line(10, 0, 40, 0, WHITE);
    my_draw_line(40, 40, 80, 40, WHITE);
    my_draw_line(80, 0, 80, 40, WHITE);
    my_draw_line(80, 0, 110, 0, WHITE);
    my_draw_line(110, 0, 110, 100, WHITE);
    my_draw_line(80, 100, 110, 100, WHITE);
    my_draw_line(80, 60, 80, 100, WHITE);
    my_draw_line(40, 60, 80, 60, WHITE);
    my_draw_line(40, 60, 40, 100, WHITE);
    my_draw_line(10, 100, 40, 100, WHITE);
    fill(20, 5);
}

void draw_T()
{
    my_draw_line(150, 100, 250, 100, WHITE);
    my_draw_line(250, 80, 250, 100, WHITE);
    my_draw_line(210, 80, 250, 80, WHITE);
    my_draw_line(210, 0, 210, 80, WHITE);
    my_draw_line(190, 0, 210, 0, WHITE);
    my_draw_line(190, 0, 190, 80, WHITE);
    my_draw_line(150, 80, 190, 80, WHITE);
    my_draw_line(150, 80, 150, 100, WHITE);
    fill(195, 5);
}

void draw_semi_circle(int x_c, int y_c, int r)
{
    int p = 1-r;
    for(int x=0, y=r; x<=(r/sqrt(2)); p += (p<0)? (2*++x + 1) : (2*(++x-(--y)) + 1))
    {
        my_putpixel( x + x_c,  y + y_c, WHITE); // 0 Oct
        // my_putpixel(-x + x_c,  y + y_c, WHITE); // 7 Oct
        my_putpixel( x + x_c, -y + y_c, WHITE); // 3 Oct
        // my_putpixel(-x + x_c, -y + y_c, WHITE); // 4 Oct
        my_putpixel( y + x_c,  x + y_c, WHITE); // 1 Oct
        // my_putpixel(-y + x_c,  x + y_c, WHITE); // 6 Oct
        my_putpixel( y + x_c, -x + y_c, WHITE); // 2 Oct
        // my_putpixel(-y + x_c, -x + y_c, WHITE); // 5 Oct
    }
}

void draw_D()
{
    draw_semi_circle(300, 50, 50);
    draw_semi_circle(300, 50, 30);
    my_draw_line(300, 80, 300, 20, WHITE);
    my_draw_line(280, 0, 280, 100, WHITE);
    my_draw_line(280, 100, 300, 100, WHITE);
    my_draw_line(280, 0, 300, 0, WHITE);
    fill(299, 50);
}


int main()
{
    cout<<"Hello World! ";
    initwindow(my_SIZE[0], my_SIZE[1], "Graphics Window");
    draw_x_axis(); draw_y_axis();
    draw_H();
    draw_T();
    draw_D();
    while(!kbhit())
        delay(100);
    return 0;
}