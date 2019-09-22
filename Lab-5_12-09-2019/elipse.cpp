// Author: Kartikei Mittal
// Mid Point elipse drawing algo
#include <bits/stdc++.h>
#include <graphics.h>

#define min std::min
#define max std::max
#define cin std::cin
#define cout std::cout
#define endl std::endl

int my_SIZE[] = {800,600};
int my_ORIGIN[] = {my_SIZE[0]/2, my_SIZE[1]/2};
void my_putpixel(int x, int y, int c)
{
    int x_ = x+my_ORIGIN[0], y_ = my_SIZE[1]-(y+my_ORIGIN[1]);
    if (
        x_ < 0  || y_ < 0  ||
        x_ > my_SIZE[0] || y_ > my_SIZE[1]
    )
        cout<<"Point: "<<x<<" "<<y<<" outside the screen.";
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
        for(int y = min(y1,y2); y != max(y1,y2); ++y)
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
    my_putpixel(x, y, BLUE);
    if(my_getpixel(x, y+1) == BLACK) // UP
        fill(x, y+1);
    if(my_getpixel(x, y-1) == BLACK) // DOWN
        fill(x, y-1);
    if(my_getpixel(x-1, y) == BLACK) // LEFT
        fill(x-1, y);
    if(my_getpixel(x+1, y) == BLACK) // RIGHT
        fill(x+1, y);
}

void draw_elipse(int h, int k, int a, int b)
{
    int a2 = a*a, b2 = b*b;
    float dx, dy, p1, p2, x, y; 
    x = 0;
    y = b; 
  
    // ---------------------------------------------- REGION 1 -----------------------------------
    p1 = b2 - (a2 * b) + (0.25 * a2); 
    dx = 2 * b2 * x; 
    dy = 2 * a2 * y; 
  
    while(dx < dy)  
    { 
        my_putpixel(x+h, y+k, WHITE);
        my_putpixel(x+h, -y+k, WHITE);
        my_putpixel(-x+h, y+k, WHITE);
        my_putpixel(-x+h, -y+k, WHITE); 
        ++x;
        dx += 2 * b2;
        if(p1 < 0) 
            p1 += dx + b2; 
        else 
        { 
            y--; 
            dy -= 2 * a2; 
            p1 += dx - dy + b2; 
        } 
    } 
  

    // ---------------------------------------------- REGION 2 -----------------------------------
    p2 = (b2 * (x+0.5) * (x+0.5)) +  (a2 * (y-1) * (y-1)) - a2 * b2; 

    while(y >= 0)
    {
        my_putpixel(x+h, y+k, WHITE);
        my_putpixel(x+h, -y+k, WHITE);
        my_putpixel(-x+h, y+k, WHITE);
        my_putpixel(-x+h, -y+k, WHITE);
        --y;
        dy -= 2 * a2;
        if(p2 > 0)
            p2 += a2 - dy;
        else 
        {
            x++; 
            dx += 2 * b2; 
            p2 += dx - dy + a2; 
        }
    }
}


int main()
{
    cout<<"Hello World! ";
    initwindow(my_SIZE[0], my_SIZE[1], "Graphics Window");
    draw_x_axis(); draw_y_axis();
    draw_elipse(150, 100, 100, 50);
    draw_elipse(150, 100, 110, 60);
    fill(100, 152);
    while(!kbhit())
        delay(100);
    return 0;
}