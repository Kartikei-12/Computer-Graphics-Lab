// Author: Kartikei Mittal
// Hyperbola
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
void draw_x_axis() {for(int i=-my_ORIGIN[0]; i<my_ORIGIN[0]; ++i) my_putpixel(i, 0, RED);}
void draw_y_axis() {for(int i=-my_ORIGIN[1]; i<my_ORIGIN[1]; ++i) my_putpixel(0, i, RED);}

void draw_hyperbola(int xc, int yc, int a, int b)
{
    int p, a2 = a*a, b2 = b*b, count = 200;
    int x = a, y = 0;

    for(int i=-my_ORIGIN[0]; i<my_ORIGIN[0]; i += 4)
        my_putpixel(i, yc, GREEN);

    p = b2*a + b2/4 - a2;
    while( x*b2 > y*a2 )
    {
        my_putpixel(xc + x, yc + y, WHITE);
        my_putpixel(xc + x, yc - y, WHITE);
        my_putpixel(xc - x, yc + y, WHITE);
        my_putpixel(xc - x, yc - y, WHITE);
        ++y;
        if(p < 0)
        {
            ++x;
            p += -a2*(1 + 2*(y+1)) + 2*b2*(x + 1);
        }
        else
            p += -a2*(1 + 2*(y+1));
    }

    p = b2*(x+0.5)*(x+0.5) - a2*(y+1)*(y+1) - a2*b2;
    while(count--)
    {
        my_putpixel(xc + x, yc + y, WHITE);
        my_putpixel(xc + x, yc - y, WHITE);
        my_putpixel(xc - x, yc + y, WHITE);
        my_putpixel(xc - x, yc - y, WHITE);
        ++x;
        if(p >= 0)
        {
            ++y;
            p += b2*(2*x + 3) - 2*a2*(y+1);
        }
        else
            p += b2*(2*x + 3);
    }
}

int main() try
{
    initwindow(my_SIZE[0], my_SIZE[1], "Graphics Window");
    draw_x_axis(); draw_y_axis();
    
    draw_hyperbola(0, 10, 100, 50);

    while(!kbhit())
        delay(100);
    return 0;
}
catch(string &e) { cerr<<"Error: "<<e<<endl; }
catch(exception &e) { cerr<<e.what()<<endl; }
catch(...) { cerr<<"\nSomething Wrong\n"<<endl; }
