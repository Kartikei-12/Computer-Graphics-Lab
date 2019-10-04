// Author: Kartikei Mittal, Tokir Manva
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
   
    int p = 1-r;
    for(int x=0, y=r; x<=r;)
    {
        if(p<0)
            p += 2*++x + 1;
        else
            p += 2*(++x-(--y)) + 1;
        my_putpixel( x + x_c,  y + y_c, WHITE);
        my_putpixel(-x + x_c,  y + y_c, WHITE);
        my_putpixel( x + x_c, -y + y_c, WHITE);
        my_putpixel(-x + x_c, -y + y_c, WHITE);
        my_putpixel( y + x_c,  x + y_c, WHITE);
        my_putpixel(-y + x_c,  x + y_c, WHITE);
        my_putpixel( y + x_c, -x + y_c, WHITE);
        my_putpixel(-y + x_c, -x + y_c, WHITE);
    }
    // delay(50);
}
void flood(int x,int y)
{
	if(getpixel(x,y) == BLACK )
	{
		putpixel(x,y,YELLOW);
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y+1);
		flood(x,y-1);
	}
	delay(10);
}

int main()
{
	//w for width of circle and width is 10
	int w=10;
    cout<<"Hello World! ";
 //    cout<<"Enter Width of Circle\n";
	// scanf("%d",&w);
    initwindow(my_SIZE[0], my_SIZE[1], "Graphics Window");
    draw_x_axis(); draw_y_axis();
 //    int gd,gm; 
	// detectgraph(&gd,&gm);
	// initgraph(&gd,&gm,"c:\\tc\\bgi"); 
    my_circle(60, 80, 50);
    my_circle(60, 80, 50+w);
    flood(60+80+5,80);
    while(!kbhit())
        delay(100);
    return 0;
}