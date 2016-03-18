#include <glew.h> // glew.h must be included before gl.h/glu.h/freeglut.h
#include <freeglut.h>
#include <cstdio>
#include <cstdlib>

#define MENU_TIMER_START 1
#define MENU_TIMER_STOP 2
#define MENU_EXIT 3

const GLfloat tri_v1[3] = {-0.5f, -0.4f, 0.0f};
const GLfloat tri_v2[3] = { 0.5f, -0.4f, 0.0f};
const GLfloat tri_v3[3] = { 0.0f,  0.6f, 0.0f};

GLubyte timer_cnt = 0;
bool timer_enabled = true;
unsigned int timer_speed = 16;

int view_x,view_y,view_z;
int press;
int angle=1,dir=0;
int angle2=1, dir2=0;
int angle3=1, dir3=0;

// Print OpenGL context related information.
void dumpInfo(void)
{
    printf("Vendor: %s\n", glGetString (GL_VENDOR));
    printf("Renderer: %s\n", glGetString (GL_RENDERER));
    printf("Version: %s\n", glGetString (GL_VERSION));
    printf("GLSL: %s\n", glGetString (GL_SHADING_LANGUAGE_VERSION));
}

void drawCube(float R,float G, float B,float vertex)
{ 
	glColor3f(R,G,B);
	glutSolidCube(vertex);
	
}
void drawSphere(float R,float G, float B,float radius)
{
	glColor3f(R,G,B);
	glutSolidSphere(radius,100,20);
}
void drawCone(float R,float G, float B,float base , float height)
{
	glColor3f(R,G,B);
	glutSolidCone(base,height ,100,20);
}
void createbody()
{
	{						//body
		glPushMatrix();

		glPushMatrix();
		glScaled(2.0,3.0,1.0);
		drawCube(0.3,0.4,0.5,2.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-1.0,2.0,1.5);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,1.3);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1.0,2.0,1.5);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,1.3);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.75,0.7,1.2);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.75,0.7,1.2);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.75,-0.05,1.2);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.75,-0.05,1.2);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.75,-0.85,1.2);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.75,-0.85,1.2);
		glScaled(1.0,0.7,0.5);
		drawSphere(1.0,1.0,0.0,0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.0,-2.5,1.0);
		glScaled(4.0,1.0,0.2);
		drawCube(1.0,1.0,0.0,1.0);
		glPopMatrix();

		

		glPopMatrix();
	}
}

void createhead()
{
	{					//head
		glPushMatrix();
		glTranslated(0.0,4.0,0.0);
		glRotated(angle,0.0,1.0,0.0);

		glPushMatrix();
		glScaled(1.0,2.0,1.0);
		drawSphere(0.5,0.7,0.8,1.0);
		glPopMatrix();

		glTranslated(0.0,0.5,0.8);

		glPushMatrix();
		glScaled(2.0,0.7,0.7);
		glTranslated(-0.35,0.0,0.0);
		drawSphere(0.2,0.7,0.0,0.3);
		glPopMatrix();

		glPushMatrix();
		glScaled(2.0,0.7,0.7);
		glTranslated(0.35,0.0,0.0);
		drawSphere(0.2,0.7,0.0,0.3);
		glPopMatrix();

		glTranslated(0.0,0.6,-0.8);

		glPushMatrix();		//hat
		glScaled(1.5,0.0,0.7);
		drawSphere(0.8,0.2,0.1,1.5);
		glPopMatrix();

		

		glPushMatrix();
		glRotated(-90,1.0,0.0,0.0);
		drawCone(0.8,0.2,0.1,0.9,2.0);
		glPopMatrix();

		glPopMatrix();
	}
}

void createhands()
{
	{				//hand
		glPushMatrix();
		
		glTranslated(0.0,2.0,0.0);

		glPushMatrix();			//left_hand start
		glTranslated(-2.5,0.0,0.0);
		drawSphere(1.0,0.0,0.3,0.5);

		glRotated(angle2, 1.0,0.0,0.0);

		glPushMatrix();
		glRotated(75,0.0,0.0,1.0);
		glTranslated(-1.5,0.0,0.0);

		glPushMatrix();				//left-mid-hand
		glScaled(2.0,1.0,1.0);
		drawCube(0.5,0.5,0.5,1.0);
		glPopMatrix();

		glTranslated(-1.5,0.0,0.0);
		drawSphere(1.0,0.0,0.3,0.5);

		glRotated(angle3, 0.0, 1.0,0.0);

		glTranslated(-1.0,0.0,0.0);
		glPushMatrix();				
		glScaled(1.5,1.5,1.0);
		drawCube(0.5,0.5,0.5,1.0);
		glPopMatrix();

		glPopMatrix();

		glPopMatrix();		//left_hand end

		glPushMatrix();			//right_hand start
		glTranslated(2.5,0.0,0.0);
		drawSphere(1.0,0.0,0.3,0.5);

		glRotated(angle2, -1.0,0.0,0.0);

		glPushMatrix();
		glRotated(75,0.0,0.0,-1.0);
		glTranslated(1.5,0.0,0.0);

		glPushMatrix();				//right-mid-hand
		glScaled(2.0,1.0,1.0);
		drawCube(0.5,0.5,0.5,1.0);
		glPopMatrix();

		glTranslated(1.5,0.0,0.0);
		drawSphere(1.0,0.0,0.3,0.5);

		glRotated(angle3, 0.0, 1.0,0.0);

		glTranslated(1.0,0.0,0.0);
		glPushMatrix();				
		glScaled(1.5,1.5,1.0);
		drawCube(0.5,0.5,0.5,1.0);
		glPopMatrix();

		glPopMatrix();

		glPopMatrix();		//right_hand end

		glPopMatrix();

		


		glPopMatrix();

	}
}

void createlegs()
{
	{
	
		
	glPushMatrix();

	glTranslated(0.0,-3.5,0.0);

	glPushMatrix();					//left-leg start
	glTranslated(-1.0,0.0,0.0);
	drawSphere(0.0,1.0,0.5,0.5);

		glRotated(angle2,-1.0,0.0,0.0);
		glPushMatrix();			
		glRotated(80,0.0,0.0,1.0);
		glTranslated(-1.5,0.0,0.0);

		glPushMatrix();				//left-mid-leg
		glScaled(2.0,1.0,1.0);
		drawCube(0.7,0.2,0.2,1.0);
		glPopMatrix();

		glTranslated(-1.5,0.0,0.0);
		drawSphere(0.0,1.0,0.5,0.5);

		glRotated(angle3,0.0,-1.0,0.0);

		glTranslated(-1.0,0.0,0.0);
		glPushMatrix();				
		glScaled(1.5,1.5,1.0);
		drawCube(0.7,0.2,0.2,1.0);
		glPopMatrix();

		glTranslated(-1.0,0.0,0.5);
		glPushMatrix();
		glScaled(0.5,1.5,2.0);
		drawCube(0.8,0.7,0.2,1.0);
		glPopMatrix();

		glPopMatrix();			

		glPopMatrix();		//left-leg end

		glPushMatrix();					//right-leg start
		glTranslated(1.0,0.0,0.0);
		drawSphere(0.0,1.0,0.5,0.5);

		glRotated(angle2,1.0,0.0,0.0);
		glPushMatrix();			
		glRotated(80,0.0,0.0,-1.0);
		glTranslated(1.5,0.0,0.0);

		glPushMatrix();				//right-mid-leg
		glScaled(2.0,1.0,1.0);
		drawCube(0.7,0.2,0.2,1.0);
		glPopMatrix();

		glTranslated(1.5,0.0,0.0);
		drawSphere(0.0,1.0,0.5,0.5);

		glRotated(angle3,0.0,1.0,0.0);

		glTranslated(1.0,0.0,0.0);
		glPushMatrix();				
		glScaled(1.5,1.5,1.0);
		drawCube(0.7,0.2,0.2,1.0);
		glPopMatrix();

		glTranslated(1.0,0.0,0.5);
		glPushMatrix();
		glScaled(0.5,1.5,2.0);
		drawCube(0.8,0.7,0.2,1.0);
		glPopMatrix();

		glPopMatrix();			

		glPopMatrix();		//right-leg end

	glPopMatrix();
	

	}
}
void lighting()
{
	
	GLfloat diffuse0[]={1.0, 1.0, 1.0, 1.0};
GLfloat ambient0[]={0.0, 0.0, 0.0, 1.0};
GLfloat specular0[]={0.0, 0.2, 0.4, 0.0};
GLfloat light0_pos[]={-500.0, 100.0, 100,0, 0.0};
GLfloat a = 0.8;
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, a);
}
void material()
{
	GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
GLfloat diffuse[] = {0.8, 0.5, 0.2, 1.0};
GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat shine = 20.0;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialf(GL_FRONT, GL_SHININESS, shine);
}

// GLUT callback. Called to draw the scene.
void My_Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	lighting();
	material();


	

	glRotated(view_x,0.0,1.0,0.0);
	glRotated(view_y,1.0,0.0,0.0);
	glRotated(view_z,0.0,0.0,1.0);

	glPushMatrix();
	glTranslated(0.0,2.0,0.0);

	createbody();
	
	createhead();

	createlegs();
	
	createhands();

	

	glPopMatrix();

	glutSwapBuffers();
}


void My_Reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	float viewportAspect = (float)width / (float)height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,width/height,1,30);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	
}

void My_Timer(int val)
{
	timer_cnt++;
	if(press==1)
		view_y=10;
	else if(press==2)
		view_y=-10;
	else if(press==3)
		view_x=10;
	else if(press==4)
		view_x=-10;
	else if(press==5)
		view_z=10;
	else if(press==6)
		view_z=-10;
	else
	{
		view_x=0;
		view_y=0;
		view_z=0;
	}

	press=0;

	if(dir==0 )
		{
			if( angle<45)
			angle+=3;
			else
				dir=1;
	}
	else if(dir==1)
		{
			if(angle>-45)
			angle-=3;
			else 
				dir=0;
	}
	else angle=angle;

	if(dir2==0 )
		{
			if( angle2<30)
			angle2+=2;
			else
				dir2=1;
	}
	else if(dir2==1)
		{
			if(angle2>-30)
			angle2-=2;
			else 
				dir2=0;
	}
	else angle2=angle2;

	if(dir3==0 )
		{
			if( angle3<30)
			angle3+=1;
			else
				dir3=1;
	}
	else if(dir3==1)
		{
			if(angle3>0)
			angle3-=1;
			else 
				dir3=0;
	}
	else angle3=angle3;



	glutPostRedisplay();
	if(timer_enabled)
	{
		glutTimerFunc(timer_speed, My_Timer, val);
	}
}

void My_Mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		printf("Mouse %d is pressed at (%d, %d)\n", button, x, y);
	}
	else if(state == GLUT_UP)
	{
		printf("Mouse %d is released at (%d, %d)\n", button, x, y);
	}
}

void My_Keyboard(unsigned char key, int x, int y)
{
	if(key=='w')
		press=1;
	else if(key=='s')
		press=2;
	else if(key=='d')
		press=3;
	else if(key=='a')
		press=4;
	else if(key=='e')
		press=5;
	else if(key=='r')
		press=6;
	else {
		press=0;
	}
//	printf("%d\n",press);
	printf("Key %c is pressed at (%d, %d)\n", key, x, y);
}

void My_SpecialKeys(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_F1:
		printf("F1 is pressed at (%d, %d)\n", x, y);
		break;
	case GLUT_KEY_PAGE_UP:
		printf("Page up is pressed at (%d, %d)\n", x, y);
		break;
	case GLUT_KEY_LEFT:
		printf("Left arrow is pressed at (%d, %d)\n", x, y);
		break;
	default:
		printf("Other special key is pressed at (%d, %d)\n", x, y);
		break;
	}
}

void My_Menu(int id)
{
	switch(id)
	{
	case MENU_TIMER_START:
		if(!timer_enabled)
		{
			timer_enabled = true;
			glutTimerFunc(timer_speed, My_Timer, 0);
		}
		break;
	case MENU_TIMER_STOP:
		timer_enabled = false;
		break;
	case MENU_EXIT:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	// Initialize GLUT and GLEW, then create a window.
	////////////////////
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Quiz Framework"); // You cannot use OpenGL functions before this line; The OpenGL context must be created first by glutCreateWindow()!
	glewInit();
    dumpInfo();
	////////////////////
	
	// Initialize OpenGL states.
	////////////////////////
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	////////////////////////

	// Create a menu and bind it to mouse right button.
	////////////////////////////
	int menu_main = glutCreateMenu(My_Menu);
	int menu_timer = glutCreateMenu(My_Menu);

	glutSetMenu(menu_main);
	glutAddSubMenu("Timer", menu_timer);
	glutAddMenuEntry("Exit", MENU_EXIT);

	glutSetMenu(menu_timer);
	glutAddMenuEntry("Start", MENU_TIMER_START);
	glutAddMenuEntry("Stop", MENU_TIMER_STOP);

	glutSetMenu(menu_main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	////////////////////////////

	// Register GLUT callback functions.
	///////////////////////////////
	glutDisplayFunc(My_Display);
	glutReshapeFunc(My_Reshape);
	glutMouseFunc(My_Mouse);
	glutKeyboardFunc(My_Keyboard);
	glutSpecialFunc(My_SpecialKeys);
	glutTimerFunc(timer_speed, My_Timer, 0); 
	///////////////////////////////

	// Enter main event loop.
	//////////////
	glutMainLoop();
	//////////////
	return 0;
}