#include <graphics.h>
#include <bits/stdc++.h>
#include <signal.h>

using namespace std;

void draw_kite(int centerx, int centery)
{

    setcolor(2);
    line(centerx, centery + 100, centerx, centery - 100);
    line(centerx - 70, centery - 20, centerx + 70, centery - 20);
    line(centerx, centery + 100, centerx - 70, centery - 20);
    line(centerx, centery + 100, centerx + 70, centery - 20);
    line(centerx, centery - 100, centerx - 70, centery - 20);
    line(centerx, centery - 100, centerx + 70, centery - 20);
    line(centerx, centery + 100, centerx - 20, centery + 120);
    line(centerx - 20, centery + 120, centerx + 20, centery + 120);
    line(centerx, centery + 100, centerx + 20, centery + 120);
    floodfill(centerx + 50, centery - 21, 2);
    floodfill(centerx - 10, centery + 10, 2);
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
    while (true)
    {
        cleardevice();


        int dirx = rand() % 3;
        int diry = rand() % 3;
        dirx -= 1;
        diry -= 1;
        centerx += dirx;
        centery += diry;
        draw_kite(centerx, centery);
        delay(20);
    }

    getch();
    closegraph();
}