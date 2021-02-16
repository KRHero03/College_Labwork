#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, ""); // Used to fetch graphics driver and initialise the graph

    cleardevice(); // Clears screen
    outtext("Hello! This is a message"); // Used to write Text (text)
    cleardevice(); // Clears screen
    for(int i = 0;i<10;i++){
        setfontcolor(i); // Sets font color 
        /* 
        0-Black 1-Blue 2-Green 3-Cyan 4-Red 
        5-Pink 6-Brown 7-White 8-Gray 9-Purple
        10-Light Cyan 11-Light Cyan 12-Light Red
        13-Light Pink 14-Yellow 15-White
        */
    outtextxy(0,(i)*50,"Hello! This is another message"); // Used to write Text at places (x,y,text)
    }
    
    //pause(); // Pauses Rendering graphics


    getch();
    closegraph(); // Closes graph and disconnects graphics driver.
    return 0;
}