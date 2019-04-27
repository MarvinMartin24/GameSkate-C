// BGIFirstTest.c : Example graphic application


#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void Circle(int y) {
	setfillstyle(SOLID_FILL, LIGHTRED);
	circle(310, 60 + y, 10);
	floodfill(311, 61+y, WHITE);
}

void obstacle1(int x) {
	setfillstyle(SOLID_FILL, 15);
	rectangle(-400 + x, 150, 0 + x, 160);
	floodfill(-399 + x, 151, WHITE);
}

void obstacle2(int x) {
	setfillstyle(SOLID_FILL, 15);
	rectangle(637 + x, 200, 1037 + x, 210);
	floodfill(638 + x, 201, WHITE);
}

void obstacle3(int x) {
	setfillstyle(SOLID_FILL, 15);
	rectangle(-500 + x, 250, -100 + x, 260);
	floodfill(-499 + x, 251, WHITE);
}

void obstacle4(int x) {
	setfillstyle(SOLID_FILL, 15);
	rectangle(800 + x, 300, 1200 + x, 310);
	floodfill(801+x, 301, WHITE);
}

void FinishArea() {
	setfillstyle(SOLID_FILL, YELLOW);
	rectangle(0, 400, 637, 430);
	floodfill(1, 401, WHITE);

	setcolor(BLACK);
	settextstyle(BOLD_FONT, HORIZ_DIR, 20);
	outtextxy(200, 401, "NEXT LEVEL");
	setcolor(WHITE);
}

main()
{

	// Set the graphic 
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	

	int x1 = 0, x2 = 0, x3 =0, x4 = 0;
	int y = 0;
	int N = 0;
	int counter = 0;
	int H = 0;
	int v = 0;
	int ctr = 1;

	// Restart Loop
	while (H == 0)
	{
		clearviewport();
		setcolor(RED);
		settextstyle(BOLD_FONT, HORIZ_DIR, 50);
		outtextxy(100, 100, "HANNAH'S GAME");
		setcolor(WHITE);
		settextstyle(BOLD_FONT, HORIZ_DIR, 20);
		outtextxy(130, 300, "Press any Key to start");
		
		// Wait for the user to press any key
		_getch();
		

		// Restart from 0 the game 
		x1 = 0;
		x2 = 0;
		x3 = 0;
		x4 = 0;
		y = 0;
		N = 0;
		counter = 0;
		v = 0;
		ctr = 1;


		//Motion Loop
		while (N == 0) {

			// Make clear Motion
			setactivepage(counter % 2);

			// Set Finish Line
			FinishArea();							// Set Yellow restart Line

			// Go Down
			if (_kbhit())							// Wait for the user to hit a key
			{
				if  (_getch() == KEY_DOWN)			// Wait for the user to hit a key Down
					{y += 10+v;}					// Increase the y depending of the level (link with v) to make the circle going down
			}

			//Print the red circle
			Circle(y);


			// Set obstacle speed and loops
			
					//Motion Obstacle 1
			x1 += 10 + v;								// Initial Speed 10
			if (x1 >= 1100) { x1 = 0; }					// Obstacle 1 Loop

					//Motion Obstacle 1
			x2 += 12 + v;								// Initial Speed 12
			if (x2 >= 1100) { x2 = 0; }					// Obstacle 2 Loop

					//Motion Obstacle 1
			x3 += 14 + v;								// Initial Speed 14
			if (x3 >= 1200) { x3 = 0; }					// Obstacle 3 Loop

					//Motion Obstacle 1
			x4 += 20 + v;								// Initial Speed 20
			if (x4 >= 1200) { x4 = 0; }					// Obstacle 4 Loop
			
			// Print Obstacles
			obstacle1(x1);
			obstacle2(-x2);
			obstacle3(x3);
			obstacle4(-x4);

			// Impact
			if (((300+v <= x1) && (x1 <= 710+v)) && ((80 < y) && (y < 110))) { N = 1; }				// Impact Obstacle 1
			if (((315 + v <= x2) && (x2 <= 720 + v)) && ((130 < y) && (y < 160))) { N = 1; }		// Impact Obstacle 2
			if (((380 + v <= x3) && (x3 <= 800 + v)) && ((180 < y) && (y < 210))) { N = 1; }		// Impact Obstacle 3
			if (((460 + v <= x4) && (x4 <= 880 + v)) && ((230 < y) && (y < 260))) { N = 1; }		// Impact Obstacle 4



			// Replace Circle & Increase Speed Afer Yellow line
			if (y > 330) { y = 0; v += 2; ctr++; }													// Circle Loop, Update speed and Level


			//printf("x+v=%d+%d  y=%d\n",x1,v, y);
			
			// Make clear Motion
			setvisualpage(counter % 2);
			counter++;

			delay(40);																				// Time between each motion loop
			clearviewport();																		// Delete Previous Motions

		}

	// Print The level after losing
	printf("You was level: %d\n", ctr);	

	//GAME OVER
	setcolor(RED);
	settextstyle(BOLD_FONT, HORIZ_DIR, 70);
	outtextxy(100, 100, "GAME OVER");
	setcolor(WHITE);
	settextstyle(BOLD_FONT, HORIZ_DIR, 30);
	outtextxy(50, 300, " Press'A' to play Again");
	
	// Restart or Stop 
	if (_getch() == 'a') { H = 0; }			// 'a' --> Restart 
	else { H = 1; }							// else Stop
	}

	closegraph();							// End
}


