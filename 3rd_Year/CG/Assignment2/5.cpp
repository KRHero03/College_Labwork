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

    outtextxy(10,10,"Concentric Circles");
    outtextxy(10,30,"By Krunal Rank");
    outtextxy(10,50,"U18CO081");

    setcolor(0);
    for(int i = 200;i>=10;i-=10){
        setcolor(i/10%15);
        circle(maxx/2,maxy/2,i);
        floodfill(maxx/2,maxy/2,(i/10)%15);
    }
    
    
    getch();
    closegraph();
    return 0;
}