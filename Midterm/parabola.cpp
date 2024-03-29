// Author: Kartikei Mittal
// Parabola
#include <bits/stdc++.h>
#include <graphics.h>

#define cin std::cin
#define cout std::cout
#define cerr std::cerr
#define endl std::endl
#define string std::string
#define exception std::exception

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
    putpixel(x_, y_, c);
}
int my_getpixel(int x, int y) {
    return getpixel(x+my_ORIGIN[0], my_SIZE[1]-(y+my_ORIGIN[1]));
}
void draw_x_axis() {for(int i=-my_ORIGIN[0]; i<my_ORIGIN[0]; i+=4) my_putpixel(i, 0, RED);}
void draw_y_axis() {for(int i=-my_ORIGIN[1]; i<my_ORIGIN[1]; i+=4) my_putpixel(0, i, RED);}

void draw_parabola(int xc, int yc, int a)
{
    int p, aa = 2*a, count = 600;
    int x = 0, y = 0;

    p = 1 - aa;
    while( aa > y )
    {
        my_putpixel(x + xc, yc - y, WHITE);
        my_putpixel(x + xc, y++ + yc, WHITE);
        if(p >= 0)
        {
            ++x;
            p += 2*y - 2*aa + 3;
        }
        else
            p += 2*y + 3;
    }

    p = (y+0.5)*(y+0.5) - 2*aa*(x+1);
    while(count--)
    {
        my_putpixel(x + xc, yc - y, WHITE);
        my_putpixel(x++ + xc, yc + y, WHITE);
        if(p < 0)
        {
            ++y;
            p += 2*(y+1) - 2*aa;
        }
        else
            p += -2*aa;
    }
    
}

int main() try
{
    initwindow(my_SIZE[0], my_SIZE[1], "Graphics Window");
    draw_x_axis(); draw_y_axis();
    
    draw_parabola(-300, 100, 10);

    while(!kbhit())
        delay(100);
    return 0;
}
catch(string &e) { cerr<<"Error: "<<e<<endl; }
catch(exception &e) { cerr<<e.what()<<endl; }
catch(...) { cerr<<"\nSomething Wrong\n"<<endl; }
