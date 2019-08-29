// Author: Kartikei Mittal
// Circle Drawing
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int my_SIZE[] = {800,600};
int my_ORIGIN[] = {my_SIZE[0]/2, my_SIZE[1]/2};

void my_putpixel(int x, int y, int c) {
    putpixel(x+my_ORIGIN[0], my_SIZE[1]-(y+my_ORIGIN[1]), c);
}
void draw_x_axis() {for(int i=-my_SIZE[0]; i<my_SIZE[0]; i+=4) my_putpixel(i, 0, RED);}
void draw_y_axis() {for(int i=-my_SIZE[1]; i<my_SIZE[1]; i+=4) my_putpixel(0, i, RED);}

void my_circle(int x_c, int y_c, int r)
{
    // int p = 1-r, x=r, y=0;
    // while(x>y)
    // {  
    //     y++; 
    //     if (p <= 0) 
    //         p += 2*y + 1; 
    //     else
    //     { 
    //         x--; 
    //         p += 2*(y-x) + 1; 
    //     } 
    //     if (x < y) 
    //         break; 
    //     my_putpixel(x  + x_c,  y + y_c, GREEN); 
    //     my_putpixel(-x + x_c,  y + y_c, WHITE); 
    //     my_putpixel(x  + x_c, -y + y_c, WHITE); 
    //     my_putpixel(-x + x_c, -y + y_c, WHITE); 
    //     if(x != y)
    //     { 
    //         my_putpixel( y + x_c,  x + y_c, GREEN); 
    //         my_putpixel(-y + x_c,  x + y_c, WHITE); 
    //         my_putpixel( y + x_c, -x + y_c, WHITE); 
    //         my_putpixel(-y + x_c, -x + y_c, WHITE); 
    //     }
    // }
    int p = 1-r;
    for(int x=0, y=r; x<=r;)
    {
        my_putpixel( x + x_c,  y + y_c, WHITE);
        my_putpixel(-x + x_c,  y + y_c, WHITE);
        my_putpixel( x + x_c, -y + y_c, WHITE);
        my_putpixel(-x + x_c, -y + y_c, WHITE);
        my_putpixel( y + x_c,  x + y_c, WHITE);
        my_putpixel(-y + x_c,  x + y_c, WHITE);
        my_putpixel( y + x_c, -x + y_c, WHITE);
        my_putpixel(-y + x_c, -x + y_c, WHITE);
        if(p<0)
            p += 2*++x + 1;
        else
            p += 2*(++x-(--y)) + 1;
    }
}

int main()
{
    cout<<"Hello World! ";
    initwindow(my_SIZE[0], my_SIZE[1], "Graphics Window");
    draw_x_axis(); draw_y_axis();
    my_circle(60, 80, 50);
    while(!kbhit())
        delay(100);
    return 0;
}