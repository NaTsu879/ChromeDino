#include <iostream>
#include <windows.h>
using namespace std;
#include <mmsystem.h>  // include the multimedia library
#pragma comment(lib, "winmm.lib") // add the linker option for winmm.lib
#include "iGraphics.h"
#define length 118
#define birdstart 26250
#define birdstart1 16200

/*
	function iDraw() is called again and again by the system.

	*/
int gamemenu=-1;
int speed=60;
bool musicon=true;
//LAND VARIABLES

char land[length][20]={"lb//image1x1.bmp","lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp",
                    "lb//image7x1.bmp","lb//image8x1.bmp","lb//image9x1.bmp","lb//image10x1.bmp","lb//image1x1.bmp","lb//image2x1.bmp",
                    "lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp","lb//image7x1.bmp","lb//image8x1.bmp",
                    "lb//image9x1.bmp","lb//image10x1.bmp",
                    "c5//image1x1.bmp",
                    "lb//image1x1.bmp","lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp",
                    "lb//image7x1.bmp","lb//image8x1.bmp","lb//image9x1.bmp","lb//image10x1.bmp","lb//image1x1.bmp","lb//image1x1.bmp",
                    "lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp","lb//image7x1.bmp",
                    "lb//image8x1.bmp","lb//image9x1.bmp","lb//image10x1.bmp","lb//image1x1.bmp","lb//image2x1.bmp","lb//image3x1.bmp",
                    "lb//image4x1.bmp",
                    "c1//image1x1.bmp","c1//image2x1.bmp",
                    "lb//image1x1.bmp","lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp",
                    "lb//image7x1.bmp","lb//image8x1.bmp","lb//image9x1.bmp","lb//image10x1.bmp","lb//image1x1.bmp","lb//image1x1.bmp",
                    "lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp","lb//image7x1.bmp",
                    "lb//image8x1.bmp",
                    "c4//image1x1.bmp","c4//image2x1.bmp","c4//image3x1.bmp","c4//image4x1.bmp",
                    "lb//image1x1.bmp","lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp",
                    "lb//image7x1.bmp","lb//image8x1.bmp","lb//image9x1.bmp","lb//image10x1.bmp","lb//image1x1.bmp","lb//image2x1.bmp",
                    "lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp","lb//image7x1.bmp","lb//image8x1.bmp",
                    "lb//image9x1.bmp","lb//image10x1.bmp",
                    "c5//image1x1.bmp",
                    "lb//image1x1.bmp","lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp","lb//image1x1.bmp","lb//image2x1.bmp",
                    "lb//image3x1.bmp","lb//image4x1.bmp","lb//image5x1.bmp","lb//image6x1.bmp","lb//image7x1.bmp","lb//image8x1.bmp",
                    "lb//image9x1.bmp","lb//image10x1.bmp","lb//image1x1.bmp","lb//image2x1.bmp","lb//image3x1.bmp","lb//image4x1.bmp",
                    "lb//image5x1.bmp","lb//image6x1.bmp","lb//image7x1.bmp","lb//image8x1.bmp","lb//image9x1.bmp","lb//image10x1.bmp",
                    "c5//image1x1.bmp","c5//image1x1.bmp"};
int landindex=0;
int k=0;
int landx=0;
int landy=90;

//DINO VARIABLES

char dino[2][20]={"dino//dino1.bmp","dino//dino2.bmp"};             //global variables
int dinoindex=0;                                                    //index of dinosaur png animation
int dinox=100;                                                       //x,y co-ordinates of dino
int dinoy=100;

//BIRD VARIABLES

char bird[2][20]={"bird//bird1.bmp","bird//bird2.bmp"};
int birdindex=0;
int birdx=birdstart;
int birdy=250;

char bird1[2][20]={"bird//bird1.bmp","bird//bird2.bmp"};
int birdx1=birdstart1;
int birdy1=100;

//TIMER AND FUNCTION VARIABLES

int jumptimer,feettimer,landtimer,scoretimer,birdtimer;                                            //timer variables
int m=-2,score=0,jump=0,pause=0;
char*stringscore=(char*)calloc(10,sizeof(char));
char*hscore=(char*)calloc(10,sizeof(char));                                                        //function variables

//FUNCTIONS

void feetanimation()                                        //basically loops the dino array so we get moving feet
{
    dinoindex++;
    if(dinoindex>=2){
        dinoindex=0;
    }
}


void winganimation()
{
    birdindex++;
    if(birdindex>=2)
    {
        birdindex=0;
    }
}

void birdmove()
{

    birdx=birdx-50;
    birdx1=birdx1-50;
    if(birdx<0){
        birdx=6000;
    }
    if(birdx1<0){
        birdx1=3000;
    }

}

void jumpanimation()                                        //increases dinoy by multiple of (-1)m10 , need to work on this
{   if(dinoy==100||dinoy==320)
    {
    jump=1;
    m=m*(-1);

    if(dinoy==100)
        {
            iPauseTimer(jumptimer);
            iResumeTimer(feettimer);
            jump=0;
        }
    else
        {
            dinoy=dinoy+(m)*10;
        }
    }else{
    jump=1;
    dinoy=dinoy+(m)*10;}
}

void gameovercheck()                                        //if the dinoy at index of cactus is less than height of cactus then collusion
{                                                           //for which value of k , the cactus x value will be equal to dinox was determined
    if(k>=18&&k<=19&&dinoy<180)
    {
       PlaySound("over.wav",NULL,SND_ASYNC);
       gamemenu=-3;
    }
    if(k>=43&&k<=46&&dinoy<180)
    {
       PlaySound("over.wav",NULL,SND_ASYNC);
       gamemenu=-3;
    }
    if(k>=66&&k<=70&&dinoy<150)
    {
       PlaySound("over.wav",NULL,SND_ASYNC);
       gamemenu=-3;
    }
    if(k>=88&&k<=90&&dinoy<150)
    {
       PlaySound("over.wav",NULL,SND_ASYNC);
       gamemenu=-3;
    }
    if(k>=113&&k<=116&&dinoy<150)
    {
       PlaySound("over.wav",NULL,SND_ASYNC);
       gamemenu=-3;
    }
    if(0<birdx&&birdx<200&&((dinoy<birdy&&birdy<(dinoy+122))||(dinoy<(birdy+87)&&(birdy+87)<(dinoy+122))))
    {
        PlaySound("over.wav",NULL,SND_ASYNC);
        gamemenu=-3;
    }
    if(0<birdx1&&birdx1<170&&dinoy<150)
    {
        PlaySound("over.wav",NULL,SND_ASYNC);
        gamemenu=-3;
    }

}

void landanimation()                                    //so basically this shit changes the index of the land blocks, like it shifts all indexes by 1 to the left
{
    if(gamemenu==-1||gamemenu==-3)
    {
        k=0;
    }else{
        k=k+1;
        if(k==length){                                          // value of k is always the block at the very beginning, so when k reaches the last block it is equal to the first block , this is done to stop overflow
            k=0;
        }
        gameovercheck();
    }
}

void its(char*str,int n)                                    //this function changes integer to string
{
                                                            //takes a certain memory and converts and stores the score and highscore
    int l=0,r,q,i;
    q=n;
    while(q!=0)
    {
        q=q/10;
        l++;
    }

    q=n;
    i=(l-1);
    while(q!=0)
    {
        r=q%10;
        *(str+i)=48+r;
        q=q/10;
        i--;
    }

}

void clearstring(char*str)                                  //this is to clear the highscore and score string memory
{
    for(int i=0;*(str+i)!='\0';i++)
    {
        *(str+i)='\0';
    }
}

void highscore()                                            //this is to change highscore
{
    int u=0;
    FILE * ifp = fopen("highscore.txt", "r");// read         //reads highscore file and saves the data in hscore string
    while(1)
    {
        *(hscore+u)=fgetc(ifp);
        if(*(hscore+u)==EOF)break;
        u++;
    }

    int hscorec=atoi(hscore);                               //hscore string was converted to int and was compared with current score , if current score higher than highscore file is re-written
    fclose(ifp);
    if(score>hscorec)
    {
        if(musicon)
        {
            PlaySound("yay.wav",NULL,SND_ASYNC);
            musicon=false;
        }
        FILE * ofp = fopen("highscore.txt", "w");
        fputs(stringscore,ofp);
        fclose(ofp);
    }
}


void scoreing()                                             //function to calculate scores
{
    if(gamemenu==-1)
    {
        score=0;
        clearstring(stringscore);
    }else if(gamemenu==-2)
    {
    score++;
    its(stringscore,score);
    highscore();
    }else if(gamemenu==-3)
    {
        highscore();
    }

}

void speedincrease()
{
    speed=speed-1;
}

void iDraw() {
	//place your drawing codes here
	iClear();
	iSetColor(172, 172, 172);

	if(gamemenu==-1)
    {
        iShowBMP(0,0,"gamemenu.bmp");
    }
    else if(gamemenu==-2)
    {
        iShowBMP(0,0,"dinobg.bmp");
        iText(800,450,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(900,450,stringscore,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,450,"HIGHSCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(700,450,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP2(birdx,birdy,bird[birdindex],0);
        iShowBMP2(birdx1,birdy1,bird1[birdindex],0);
        iShowBMP2(dinox,dinoy,dino[dinoindex],0);
        while(landx<1000)                                   //this while loop runs 50 times ..... i need to like reduce this
        {
            iShowBMP2(landx,landy,land[landindex%length],0);
            landx=landx+50;                                     //this is like the block difference , there is some work left to be done
            landindex++;                                        //increases value of land index so that like we cann get entire land
        }
        landx=0;                                            //re states the value of landx
        landindex=k;                                        //re states value of landindex for the settimer function

    }else if(gamemenu==-3)
    {
        iShowBMP2(0,100,"game menu3.bmp",0);
        iText(300,150,"HIGHSCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(470,150,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(570,150,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(670,150,stringscore,GLUT_BITMAP_TIMES_ROMAN_24);

    }

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == ' ') {
       if(gamemenu==-1)
        {
            gamemenu=-2;
        }
        else if(gamemenu==-2)
        {
            if(jump==0){
            PlaySound("beep.wav",NULL,SND_ASYNC);
            iPauseTimer(feettimer);
            dinoy=dinoy+(m)*10;
            iResumeTimer(jumptimer);}
        }
        else if(gamemenu==-3)
        {
            PlaySound("beep.wav",NULL,SND_ASYNC);
            score=0;
            speed=60;
            musicon=true;
            birdx=birdstart;
            birdx1=birdstart1;
            clearstring(stringscore);
            gamemenu=-2;
        }
	}
	if (key== 'w')
	{
        if(pause==0)
	    {
        iPauseTimer(feettimer);
	    iPauseTimer(scoretimer);
	    iPauseTimer(landtimer);
	    iPauseTimer(birdtimer);
	    iPauseTimer(jumptimer);
	    pause=1;
	    }
	    else if(pause==1)
        {
        iResumeTimer(feettimer);
	    iResumeTimer(scoretimer);
	    iResumeTimer(landtimer);
	    iResumeTimer(birdtimer);
	    iResumeTimer(jumptimer);
	    pause=0;
        }

	}
	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main()
{
    scoretimer=iSetTimer(100,scoreing);
    feettimer=iSetTimer(100,feetanimation);
    landtimer=iSetTimer(speed,landanimation);
    iSetTimer(1000,speedincrease);                    //addmore filters for smooth game play
    jumptimer=iSetTimer(15,jumpanimation);
    iSetTimer(100,winganimation);
    birdtimer=iSetTimer(45,birdmove);

//    place your own initialization codes here.
	iInitialize(1000, 500, "Chrome Dino");
	return 0;
}
