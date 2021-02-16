#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, ""); // Used to fetch graphics driver and initialise the graph
    int maxx = getmaxx();
    int maxy = getmaxy();


    int state = 0;
    setfontcolor(4);
    setbkcolor(15);
    outtextxy(10, 10, "Traffic Signal");
    outtextxy(10, 30, "By Krunal Rank");
    outtextxy(10, 50, "U18CO081");

    setcolor(0);
    rectangle(maxx / 2 - 40, maxy / 2 - 140, maxx / 2 + 40, maxy / 2 + 140);
    floodfill(maxx / 2, maxy / 2, 0);
    while (true)
    {

        if (state == 0)
        {

            setcolor(4);
            circle(maxx / 2, maxy / 2 - 70, 30);
            floodfill(maxx / 2, maxy / 2 - 70, 4);
        }
        else
        {
            setcolor(8);
            circle(maxx / 2, maxy / 2 - 70, 30);
            floodfill(maxx / 2, maxy / 2 - 70, 8);
        }

        if (state == 1)
        {

            setcolor(14);
            circle(maxx / 2, maxy / 2, 30);
            floodfill(maxx / 2, maxy / 2, 14);
        }
        else
        {

            setcolor(8);
            circle(maxx / 2, maxy / 2, 30);
            floodfill(maxx / 2, maxy / 2, 8);
        }

        if (state == 2)
        {

            setcolor(2);
            circle(maxx / 2, maxy / 2 + 70, 30);
            floodfill(maxx / 2, maxy / 2 + 70, 2);
        }
        else
        {

            setcolor(8);
            circle(maxx / 2, maxy / 2 + 70, 30);
            floodfill(maxx / 2, maxy / 2 + 70, 8);
        }

        sleep(1);
        state++;
        if (state == 3)
            state = 0;
    }

    getch();
    closegraph();
    return 0;
}