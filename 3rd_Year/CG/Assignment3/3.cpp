#include <graphics.h>
#include <bits/stdc++.h>
#include <signal.h>

using namespace std;

void draw_flag(int left, int top, int right, int bottom)
{
    assert(bottom > top);
    assert(right > left);
    int diffy = bottom - top;
    int del = diffy / 3;
    setcolor(12);
    bar(left, top, right, top + del);
    setcolor(15);
    bar(left, top + del, right, top + 2 * del);
    setcolor(2);
    bar(left, top + 2 * del, right, bottom);

    int ccx = (left + right) / 2, ccy = (top + bottom) / 2, rad = del / 2;
    setcolor(1);
    circle(ccx, ccy, rad);

    for (int i = 0; i < 180; i += 15)
    {
        double x1 = ccx + (double)rad * cos((double)i);
        double x2 = ccx - (double)rad * cos((double)i);
        double y1 = ccy + (double)rad * sin((double)i);
        double y2 = ccy - (double)rad * sin((double)i);
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    int x = 10, y = 480;
    initgraph(&gd, &gm, "");
    int gdriver = DETECT;
    int gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    int maxx = getmaxx();
    int maxy = getmaxy();

    int centerx = maxx / 2, centery = maxy / 2;
    cleardevice();
    int left = maxx / 2 - 200, right = maxx / 2 + 200, top = maxy / 2 - 150, bottom = maxy / 2 + 150;
    draw_flag(left, top, right, bottom);
    delay(20);

    getch();
    closegraph();
}