// BGIFirstTest.c : GAME OF SKATE BY MARVIN MARTIN


//--------------------------------LIBRARY----------------------------------//

#include <graphics.h>
#include <dos.h>
#include <conio.h> 
#include <stdio.h>

//------------------------------DECLARATION--------------------------------//

int ChooseMode();
void DaySky();
void NightSky();
void EvilMode();
void Floor();
void Cloud(int, int);
void Moon(int, int);
void Bird(float, float, int);
void skater(float, float, int);
void Cap(float, float, int);
void obstacle_1(float, float);
void obstacle_2(float, float);
void obstacle_3(float, float);
int random(int);
int Score(float);
int DayNight(float);


//---------------------------------MAIN-----------------------------------//

main() {
	// Initialize the window
	int drive = DETECT, mode, MODE = 1;
	initgraph(&drive, &mode, "C:\\TC\\BGI");
	

	// Intialize Variable
	int v = 0, N = 0, M = 1, counter = 0, i = 0, r=0, ctr=0, q=1;
	float x = 0.0, y = 0.0, var=0.0, b = 0.0, d = 0.0, k = 0.0, m=0.0, n=0.0;
	char c[2];
	double speed = 0.0;
	const Vo = 9.5;


	// Loop to restart the Game
	while (M == 1)																					// While the User want to Play
	{

		// Login Title

		clearviewport();
		settextstyle(BOLD_FONT, HORIZ_DIR, 70);
		outtextxy(10, 100, "GAME OF SKATE");
		settextstyle(BOLD_FONT, HORIZ_DIR, 30);
		outtextxy(140, 250, "A=Realistic Mode");
		outtextxy(140, 300, "B=Dream Mode");

		// (Re)initialize Variable
		N = 0, var = 0, x = 0.0, y = 0.0, b = 0.0, d = 0.0, ctr = 0, q = 1, m=0.0, n=0.0;
		

		// (Re)set Up the Game
		printf("\n\n<-----GAME OF SKATE----->\n\n");
		printf("---> Press A for the Realistic Mode \n---> Press B for the Dream Mode \n");
		
		MODE = ChooseMode();
		printf("\n\nYou took Mode = ");
		if (MODE == 1) { printf("A\n"); }
		else { printf("B\n"); }
		

		printf("\n\n--->Press any key to start\n--->Press Up to Jump\n");
		_getch();

		// Motion Loop
		while (N != 1)																				// While No IMPACT
		{
			// Set the Decor
			setactivepage(counter % 2);

				// Bird Motion			
			b += 5.0;																				// Make the Bird Moving
			if (b >= 700) { b = 0; d = 0; }															// The Comeback
			if (counter % 2 == 0) { d += 4.25; }													// Wings Down
			else if (counter % 3 == 1) { d -= 12.5; }												// Wings Up
				
				// Cloud Motion
			v += 3;																					// Make the Cloud Moving
			if (v >= 600) { v = 0; }																// The Comeback

				// Moon Motion
			k += 0.7;																				// Make the Cloud Moving
			if (k >= 600) { k = 0; }																// The Comeback


				// Day or Night
			if (DayNight((var + Vo))==1)															// Day
			{
				DaySky();
				Floor();
				Bird(b, d,BLACK);
				Cloud(-v, 0);
			}
			else if (DayNight((var + Vo))==2)														// Night
			{
				NightSky();
				Floor();
				Bird(b, d, WHITE);
				Moon(-k, 0);
				
			}
			else 
			{																					// Evil Mode
				EvilMode();
				Floor();
				Bird(b, d, BLACK);
				Cloud(-v, 0);
				Moon(-k, 0);
			}



			// If user press Key Up 
			if (y == 0) { i = 0; }																	// Limit Jumps
			if (_kbhit())
			{
				if (_getch() == KEY_UP)
				{
					if (i < MODE)																	// Give number of Jump
					{
						speed = 30.0;																// Heighness of Jump
						i++;
					}
				}
			}

			// JUMP
			speed -= 2.25;
			y -= speed;																				// Make the Skater Jump & Fall
			if (y >= 0) { y = 0.0; speed = 0.0; }		

			// Cap motion

			if (((50 <= b) && (b <= 85)) && ((-130 <= y) && (y <= -100))) {q++;}					// If Touch the Bird it keeps or gives it 
			if (q % 2 == 0) 
			{	m = b - 77; n = -128; 
				settextstyle(BOLD_FONT, HORIZ_DIR, 8);
				outtextxy(0+b, 70, "Get it Back !");
			}
			else { m = 0.0; n = y; }																// Cap stay on the skater


			// Select Skater & Cap for the Environment
			if (DayNight((var + Vo)) == 1) { skater(0, y, BLACK); Cap(m, n, BLACK);}
			else if (DayNight((var + Vo)) == 2) { skater(0, y, WHITE);  Cap(m, n, WHITE);}
			else { skater(0, y, BLACK);  Cap(m, n, BLACK);}
			


			// Obstacle Motion
			x += (var + Vo);																		// Make the Obstacles Moving
			if (x >= 620 + 20 * var) { x = 0.0; r = random(3); ctr++; }								// Make them comeback Randomly and count them
			

			// Random Obstacle
			switch (r)
			{
			case 0: {
				obstacle_1(-x, 0);
				if (((479 <= x) && (x <= 565)) && ((-95 <= y) && (y <= 0))) { N = 1; }; }break;		//Impact 1 for osbstacle 1
			case 1: {
				obstacle_2(-x, 0); 
				if (((460 <= x) && (x <= 620)) && ((-80<= y) && (y <= 0))) { N = 1; }; }break;		//Impact 2 for osbstacle 2
			case 2: {
				obstacle_3(-x, 0); 
				if (((425 <= x) && (x <= 638)) && ((-180 <= y) && (y <= -20))) { N = 1; }; }break;	// Impact 3 for osbstacle 3
			}

			// Print the Score
			
			c[0] = Score((var + Vo));
			c[1] = '\0';
			setcolor(WHITE);
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 100);
			outtextxy(500, 100, c);																	// Print level bwtn 1-9
		
			
			
			// Incrementing
			var += 0.012;
			setvisualpage(counter % 2);
			counter++;
			

			// Set the speed of Loops
			// Clear the view
			delay(40);
			clearviewport();

		}

		// GAME OVER
		settextstyle(BOLD_FONT, HORIZ_DIR, 70);
		outtextxy(100, 100, "GAME OVER");
		settextstyle(BOLD_FONT, HORIZ_DIR, 30);
		outtextxy(200, 200, "LEVEL:");
		settextstyle(BOLD_FONT, HORIZ_DIR, 30);
		outtextxy(360, 200, c);
		settextstyle(BOLD_FONT, HORIZ_DIR, 25);
		outtextxy(120, 400, "Press ENTER to Play");

		// Info of the Game
		printf("\n\n You avoid %d Obstacles \n", ctr);
		
		// Restart & Stop Choice
		printf("\n\n--->Press ENTER to PLAY again or ANY other to STOP \n\n");
	
		if (_getch()==KEY_ENTER) {M = 1;}
		else M = 0; 
	}
	closegraph();																					// End of the Game
}

//------------------------------DEFINITION--------------------------------//

int ChooseMode() {
	switch (_getch())
	{
	case 'a': {return 1; }break;
	case 'b': { return 2; }break;
	default:
		printf("\n\nIt was not A or B, So we gived you mode A\n");
		return 1;
	}
}

void DaySky() {
	setfillstyle(XHATCH_FILL, CYAN);
	rectangle(0, 0, 637, 362);
	floodfill(1, 1, WHITE);
}

void NightSky() {
	setfillstyle(XHATCH_FILL, BLACK);
	rectangle(0, 0, 637, 362);
	floodfill(1, 1, WHITE);
}

void EvilMode() {
	setfillstyle(XHATCH_FILL, LIGHTRED);
	rectangle(0, 0, 637, 362);
	floodfill(1, 1, WHITE);
}

void Floor() {
	setfillstyle(XHATCH_FILL, DARKGRAY);
	rectangle(0, 370, 637, 500);
	floodfill(1, 371, WHITE);

}

void Cloud(int x, int y) {

	setfillstyle(XHATCH_FILL, WHITE);
	ellipse(617 + x, 50 + y, 0, 360, 50, 18);
	floodfill(618 + x, 51 + y, WHITE);

	setfillstyle(XHATCH_FILL, WHITE);
	ellipse(579 + x, 30 + y, 0, 360, 50, 12);
	floodfill(580 + x, 31 + y, WHITE);

	setfillstyle(XHATCH_FILL, WHITE);
	ellipse(579 + x, 70 + y, 0, 360, 50, 12);
	floodfill(580 + x, 71 + y, WHITE);

	setfillstyle(XHATCH_FILL, WHITE);
	ellipse(540 + x, 50 + y, 0, 360, 50, 18);
	floodfill(541 + x, 51 + y, WHITE);
}

void Moon(int x, int y) {

	setfillstyle(XHATCH_FILL, WHITE);
	circle(637 + x, 55 + y, 35);			
	floodfill(638 + x, 56 + y, WHITE);

	setcolor(DARKGRAY);					
	circle(627 + x, 55 + y, 7);
	setcolor(DARKGRAY);
	circle(648 + x, 50 + y, 3);
	setcolor(DARKGRAY);
	circle(640 + x, 70 + y, 5);
	setcolor(DARKGRAY);
	circle(637 + x, 38 + y, 8);
}

void Bird(float i, float y, int color) {

	setcolor(color);
	line(0 + i, y + 100, 20 + i, 120);			// Left wing
	line(20 + i, 120, 40 + i, y + 100);			// Right wing
	setcolor(WHITE);

}

void skater(float x, float y, int color) {

	// skater
	setcolor(color);
	circle(95 + x, 262 + y, 13);				// head
	line(95 + x, 275 + y, 95 + x, 313 + y);		// body
	line(95 + x, 288 + y, 70 + x, 313 + y);		// left arm
	line(95 + x, 288 + y, 120 + x, 288 + y);	// right arm
	line(95 + x, 313 + y, 82 + x, 350 + y);		// left leg
	line(95 + x, 313 + y, 108 + x, 350 + y);	// right leg


	//skateboard

	line(58 + x, 338 + y, 70 + x, 350 + y);		// tail
	line(133 + x, 338 + y, 120 + x, 350 + y);	// noze
	line(70 + x, 350 + y, 120 + x, 350 + y);	// deck
	circle(76 + x, 356 + y, 6);					// backwheels
	circle(114 + x, 356 + y, 6);				// frontwheels
	setcolor(WHITE);

}

void Cap(float x,float y,int color) {
	setcolor(color);
	arc(95+x, 262+y, 15, 165, 13);
	line(72 + x, 259 + y, 108 + x, 259 + y);
	setcolor(WHITE);
}

void obstacle_1(float x, float y) {
	setfillstyle(XHATCH_FILL, RED);
	rectangle(617 + x, 302 + y, 637 + x, 362 + y);
	floodfill(618 + x, 303 + y, WHITE);

}

void obstacle_2(float x, float y) {


	setfillstyle(XHATCH_FILL, GREEN);
	rectangle(617 + x, 332 + y, 635 + x, 362 + y);
	floodfill(618 + x, 333 + y, WHITE);

	setfillstyle(XHATCH_FILL, GREEN);
	rectangle(657 + x, 332 + y, 675 + x, 362 + y);
	floodfill(658 + x, 333 + y, WHITE);

	setfillstyle(XHATCH_FILL, GREEN);
	rectangle(590 + x, 312 + y, 700 + x, 332 + y);
	floodfill(591 + x, 313 + y, WHITE);
}

void obstacle_3(float x, float y) {


	setfillstyle(XHATCH_FILL, BROWN);
	rectangle(590 + x, 200 + y, 598 + x, 362 + y);
	floodfill(591 + x, 201 + y, WHITE);

	setfillstyle(XHATCH_FILL, BROWN);
	rectangle(667 + x, 200 + y, 675 + x, 362 + y);
	floodfill(668 + x, 201 + y, WHITE);

	setfillstyle(XHATCH_FILL, BROWN);
	rectangle(575 + x, 180 + y, 692 + x, 200 + y);
	floodfill(576 + x, 181 + y, WHITE);
}

int random(int n) {
	int r;
	srand(time(NULL));
	r = rand() % n;			// Gives ramdomly a interger btwn 0-n
	return r;
}

int Score(float S) {
	if (S < 15.0) { return '1'; }										// Level 1
	else if ((15.0 <= S) && (S < 20.0)) { return '2'; }					// Level 2
	else if ((20.0 <= S) && (S < 35.0)) { return '3'; }					// Level 3
	else if ((35.0 <= S) && (S < 45.0)) { return '4'; }					// Level 4
	else if ((45.0 <= S) && (S < 60.0)) { return '5'; }					// Level 5
	else if ((60.0 <= S) && (S < 90.0)) { return '6'; }					// Level 6
	else if ((90.0 <= S) && (S < 100.0)) { return '7'; }				// Level 7
	else if ((100.0 <= S) && (S < 120.0)) { return '8'; }				// Level 8
	else if ((120.0 <= S) && (S < 150.0)) { return '9'; }				// Level 9
	else return 'x';													// Infinte level
}

int DayNight(float z) {
	if (z < 20.0) { return 1; }								// Day
	else if ((20.0 <= z) && (z <= 35.0)) { return 2; }		// Night
	else { return 3; }										// Evil Mode
}

