#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, ""); // Used to fetch graphics driver and initialise the graph
    int maxx = getmaxx();
    int maxy = getmaxy();

    cleardevice(); // Clears screen

    setfontcolor(4);
    setbkcolor(15);

    outtextxy(10,10,"Smiley Face");
    outtextxy(10,30,"By Krunal Rank");
    outtextxy(10,50,"U18CO081");

    setcolor(14);
    circle(maxx/2,maxy/2,200);
    floodfill(maxx/2,maxy/2,14);

    setcolor(15);
    circle(maxx/2-75,maxy/2-75,30);
    circle(maxx/2+75,maxy/2-75,30);
    floodfill(maxx/2-75,maxy/2-75,15);
    floodfill(maxx/2+75,maxy/2-75,15);


    setcolor(0);
    circle(maxx/2-75,maxy/2-75,10);
    circle(maxx/2+75,maxy/2-75,10);
    floodfill(maxx/2-75,maxy/2-75,0);
    floodfill(maxx/2+75,maxy/2-75,0);


    setcolor(15);

    ellipse(maxx/2,maxy/2+80,0,180,100,40);
    line(maxx/2-100,maxy/2+80,maxx/2+100,maxy/2+80);
    floodfill(maxx/2,maxy/2+90,15);
    


    
    getch();
    closegraph();
    return 0;
}