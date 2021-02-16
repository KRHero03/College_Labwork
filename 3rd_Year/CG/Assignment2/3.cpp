#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, ""); // Used to fetch graphics driver and initialise the graph

    cleardevice(); // Clears screen
    
    int maxx = getmaxx();
    int maxy = getmaxy();

    setbkcolor(15);
    setfontcolor(4);
    setcolor(1);
    outtextxy(10,10,"Car Design");
    outtextxy(10,30,"By Krunal Rank");
    outtextxy(10,50,"U18CO081");

    line(10,250,10,350);
    line(10,250,120,250);
    arc(120,350,180,0,30);

    line(10,350,90,350);
    line(120,250,170,200);
    line(170,200,370,200);    
    line(370,200,420,250);
    

    arc(420,350,180,0,30);
    
    line(150,350,390,350);
    line(420,250,570,250);
    line(450,350,570,350);
    line(570,250,570,350);


    line(130,250,170,210);
    line(170,210,260,210);
    line(260,210,260,250);
    line(130,250,260,250);

    line(280,210,370,210);
    line(370,210,410,250);
    line(280,210,280,250);
    line(280,250,410,250);
    floodfill(300,300,1);

    setcolor(0);
    circle(120,352,27);
    circle(420,352,27);
    floodfill(120,352,0);
    floodfill(420,352,0);



    getch();
    closegraph(); // Closes graph and disconnects graphics driver.
    return 0;
}