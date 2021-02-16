#include <graphics.h>
#include <bits/stdc++.h>
#include <signal.h>

using namespace std;

void draw_line_dda(int x1, int y1, int x2, int y2)
{
    double dx = x2 - x1, dy = y2 - y1;
    double step;
    if (abs(dx) >= abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    double xin = dx / step, yin = dy / step;
    double x = x1, y = y1;
    putpixel(x, y, 4);
    for (int i = 0; i < step; i++)
    {
        x += xin;
        y += yin;
        putpixel(x, y, 4);
    }
}

void draw_line_bres(int x1, int y1, int x2, int y2,int t = 0)
{
    if(abs(y2-y1)>abs(x2-x1)){
        draw_line_bres(y1,x1,y2,x2,1);
        return;
    }
    if(x1>x2){
    	swap(x1,x2);
    	swap(y1,y2);
    }
    int inc = y1>y2?-1:1;
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new + inc==1?-(x2 - x1):(x2-x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        if(t) putpixel(y,x,4);
        else putpixel(x, y, 4);

        slope_error_new += m_new;       

        if (inc==1 && slope_error_new >= 0) 
        { 
            y+=inc; 
            slope_error_new  -= 2 * (x2 - x1); 
        }else if(inc==-1 && slope_error_new<=0){
            y+=inc;
            slope_error_new += 2*(x2-x1);
        }
        
    }
}

int main()
{
    cout << "Line Drawing Algorithms:" << endl;
    cout << "1. DDA Algorithm" << endl;
    cout << "2. Bresenham's Line Algorithm" << endl;
    cout << ">>";
    int x;
    cin >> x;
    if (x != 1 && x != 2)
    {
        cout << "Invalid Choice!" << endl;
        exit(0);
    }

    int gdriver = DETECT;
    int gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    setbkcolor(15);
    int maxx = getmaxx();
    int maxy = getmaxy();
    if (x == 1)
    {
        draw_line_dda(maxx, 0, 0, maxy);
        draw_line_dda(0, 0, maxx, maxy);
        draw_line_dda(0, 0, 100, maxy);
        draw_line_dda(200, maxy, 100, 0);
    }
    else
    {
        draw_line_bres(maxx, 0, 0, maxy);
        draw_line_bres(0, 0, maxx, maxy);
        draw_line_bres(0, 0, 100, maxy);
        draw_line_bres(200, maxy, 100, 0);
    }

    getch();
    closegraph();
}
