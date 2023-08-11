#include <graphics.h>
#include <iostream>
using namespace std;

void drawHouse();
void drawEmoji ();
void drawBangladeshFlag();
void drawRainDrops();

int main(){
    int choice;bool running = true;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (running){
        cout << "Choose an option from the list below:\n";
        cout << "1. House\n";
        cout << "2. Emoji \n";
        cout << "3. National Flag of Bangladesh\n";
        cout << "4. Rain\n";
        cout << "5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice){
        case 1:
            initwindow(800,600,"House");
            drawHouse();
            break;
        case 2:
            initwindow(800,600,"Emoji");
            drawEmoji();
            break;

        case 3:
            initwindow(800,600,"Flag");
            drawBangladeshFlag();
            break;
        case 4:
            initwindow(800,600,"Rain Drops");
            for (int i = 0; i < 500; i++){
                drawRainDrops();
                delay(50);
                cleardevice();
            }
            break;
        default:
            running = false;
            break;
        }
    }
    closegraph();
    return 0;
}

void drawHouse(){
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(WHITE);
    rectangle(150, 200, 450, 400);
    floodfill(300, 250, WHITE);

    setfillstyle(SOLID_FILL, DARKGRAY);
    setcolor(WHITE);
    line(150, 200, 300, 100);
    line(300, 100, 450, 200);
    line(150, 200, 450, 200);
    floodfill(300, 150, WHITE);

    setfillstyle(SOLID_FILL, BROWN);
    setcolor(WHITE);
    rectangle(200, 300, 300, 400);
    floodfill(250, 350, WHITE);

    setfillstyle(HATCH_FILL, LIGHTBLUE);
    setcolor(WHITE);
    rectangle(350, 250, 450, 325);
    floodfill(375, 275, WHITE);
}


void drawEmoji(){
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int faceRadius = 100;
    setcolor(WHITE);
    circle(centerX, centerY, faceRadius);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(centerX,centerY,WHITE);

    int eyeRadius = 20;
    setcolor(BLACK);
    circle(centerX - 40, centerY - 30, eyeRadius);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(centerX-40,centerY-30,BLACK);
    circle(centerX + 40, centerY - 30, eyeRadius);
    floodfill(centerX+40,centerY-30,BLACK);

    int noseLength = 20;
    line(centerX, centerY - 10, centerX - noseLength, centerY + 10);
    line(centerX - noseLength, centerY + 10, centerX + noseLength, centerY + 10);
    line(centerX + noseLength, centerY + 10, centerX, centerY - 10);

    ellipse(centerX, centerY + 40, 0, 180, 40, 20);
}

void drawBangladeshFlag(){
    int flagWidth = 300;
    int flagHeight = 200;
    int stickWidth = 10;
    int stickHeight = 300;
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int circleRadius = flagWidth / 10;

    setfillstyle(SOLID_FILL, COLOR(0, 102, 71));

    int leftX = centerX - flagWidth / 2;
    int rightX = centerX + flagWidth / 2;
    int topY = centerY - flagHeight / 2;
    int bottomY = centerY + flagHeight / 2;

    bar(leftX, topY, rightX, bottomY);

    setcolor(WHITE);
    rectangle(leftX - stickWidth, topY, leftX, topY + stickHeight);
    floodfill(leftX - 5, topY + stickHeight / 2, WHITE);

    int circleCenterX = leftX + static_cast<int>(flagWidth * 0.48);
    int circleCenterY = centerY;

    setfillstyle(SOLID_FILL, RED);
    fillellipse(circleCenterX, circleCenterY, circleRadius, circleRadius);

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(centerX - 120, centerY + flagHeight / 2 + 30, "National Flag of Bangladesh");
}


void drawRainDrops()
{
    for (int j = 0; j < 100; j++){
        setcolor(WHITE);
        outtextxy(rand() % 800, rand() % 600, "|");

    }
}

