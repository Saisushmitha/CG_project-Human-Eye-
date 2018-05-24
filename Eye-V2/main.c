#include <GL/glut.h>
#include <stdlib.h>
#include <SOIL/SOIL.h>
int view = 0;
int xt=0,xu =0;
#define ESCAPE 27
#define FPS 30

static int pos = 10;
int show = 0;
GLint window;
GLint window2;

void addImage() {

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	//glColor4f(0,0,0,0);
	GLuint tex_2d1 = SOIL_load_OGL_texture
	(
		"eye1.jpeg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_COMPRESS_TO_DXT
	);
	//change vertex co-ordinates accordingly
	glBindTexture(GL_TEXTURE_2D, tex_2d1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(150, 150);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(30, 50);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(205, 40);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(10, 40);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glFlush();
}

GLvoid home()
{
	//Roof
	glColor3f(0.3, 0.5, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(0.2, 0.5);
	glVertex2f(0.600, 0.500);
	glVertex2f(0.700, 0.350);
	glVertex2f(0.300, 0.350);
	glEnd();

	//Roof line
	glColor3f(0.0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.00, 5.00);
	glVertex2f(6.00, 5.00);
	glVertex2f(7.00, 3.50);
	glVertex2f(3.00, 3.50);
	glEnd();

	// Top of Front Wall
	glColor3f(0.1, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(2.00, 5.00);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glEnd();

	// Top of Front Wall Line
	glColor3f(0, 0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.00, 5.00);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glEnd();

	// Front Door Lock
	glColor3f(0.3, 0.7, 0.9);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(2.30, 2.10);
	glEnd();

	// Front Door
	glColor3f(0.7, 0.2, 0.9);
	glBegin(GL_POLYGON);
	glVertex2f(1.50, 3.50);
	glVertex2f(2.50, 3.0);
	glVertex2f(2.50, 1.23);
	glVertex2f(1.50, 1.80);
	glEnd();

	// Front Door Line
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.50, 3.50);
	glVertex2f(2.50, 3.0);
	glVertex2f(2.50, 1.23);
	glVertex2f(1.50, 1.80);
	glEnd();

	// Front Wall
	glColor3f(0.7, 0.2, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glVertex2f(3.00, 1.00);
	glVertex2f(1.00, 2.00);
	glEnd();

	// Front Wall Line
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glVertex2f(3.00, 1.00);
	glVertex2f(1.00, 2.00);
	glEnd();

	// window one
	glColor3f(0.2, 0.4, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(3.30, 3.20);
	glVertex2f(4.50, 3.20);
	glVertex2f(4.50, 2.30);
	glVertex2f(3.30, 2.30);
	glEnd();

	// line of window one
	glColor3f(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
    glVertex2f(3.30, 3.20);
	glVertex2f(4.50, 3.20);
	glVertex2f(4.50, 2.30);
	glVertex2f(3.30, 2.30);
	glEnd();

	// window two
	glColor3f(0.2, 0.4, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(5.30, 3.20);
	glVertex2f(6.50, 3.20);
	glVertex2f(6.50, 2.30);
	glVertex2f(5.30, 2.30);
	glEnd();

	// lines of window two
	glColor3f(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2f(5.30, 3.20);
	glVertex2f(6.50, 3.20);
	glVertex2f(6.50, 2.30);
	glVertex2f(5.30, 2.30);
	glEnd();

	//side Wall
	glColor3f(0.1, 0.2, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(3.00, 3.50);
	glVertex2f(7.00, 3.50);
	glVertex2f(7.00, 1.00);
	glVertex2f(3.00, 1.00);
	glEnd();

	//side wall line
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(3.00, 3.50);
	glVertex2f(7.00, 3.50);
	glVertex2f(7.00, 1.00);
	glVertex2f(3.00, 1.00);
	glEnd();
}


void display_string(int x, int y, char *string, int font)
{
	int len,i;
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		if(font==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		else if(font==2)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		else if(font==3)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
		else if(font==4)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}

void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	display_string(500,540,"PES INSTITUTE OF TECHNOLOGY",1);
	display_string(420,500,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",1);
	display_string(490,400,"A MINI PROJECT ON  :",2);
	display_string(630,400,"HUMAN EYE",2);
	display_string(500,210,"BY:",2);
	display_string(540,210,"SAI SUSHMITHA ",3);
	display_string(540,190,"USN : 1PE15CS130",3);
	//display_string(700,310,"GUIDES: ",2);
	//display_string(700,280,"PROF. PREETHI/NEETA",3);
	//display_string(700,260,"DR. SARASWATHI",3);
	display_string(540,100,"PRESS SPACE BAR TO ENTER",2);
	display_string(590,50,"ESCAPE TO EXIT",4);
	glutSwapBuffers();
}

void draw_mark_line(float x1, float y1, float x2, float y2)
 {
     glBegin(GL_LINES);
        glColor3f(0.55,0.55,0.55);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    glBegin(GL_POINT);
        glPointSize(14.0);
        glVertex2f(x2,y2);
    glEnd();
}

//front page keys
void NormalKey(GLubyte key, GLint x, GLint y)
{
	switch ( key )    {
		case ESCAPE : printf("Escape pressed. Exit.\n");
                        glutDestroyWindow(window);	/* Close the window */
                        exit(0);
                        break;

		case ' ':   view=1;
                    display();
                    break;
		default:break;
	}
}

//keys near the eye image
 void SpecialKeyFunc( int Key, int x, int y )
{
	switch ( Key ) {
		case GLUT_KEY_RIGHT:
			xt += 1;
			printf("%d\n",xt);
			display();
 			break;
        case GLUT_KEY_LEFT:
            xu +=1;
            printf("xu:%d\n",xu);
            display();
        default:break;
	}
}

void init()
{
	glClearColor(0,0,0,0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,900.0,0.0,600.0,50.0,-50.0);
}

 void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    //gluOrtho2D(-1, 1, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

GLvoid Transform(GLfloat width, GLfloat height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    //gluOrtho2D(-1, 1, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

GLvoid ReSizeGLScene(GLint Width, GLint Height)
{
	if (Height==0)     Height=1;                   /* Sanity checks */
	if (Width==0)      Width=1;
	Transform( Width, Height );                   /* Perform the transformation */
}

void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

 void display(void)
{
    if (view == 0){

		init();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		addImage();
		display1();

    }

    else{
    int signal, i, m;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

   // EyeBall
    glPushMatrix();
        //glColor3f(0.79215,0.862745,0.941176);
        glColor3d(0.8588235,0.9098029,0.95685274);
        glTranslated(0.689,0.27,-3.5);
        glRotated(-64, 1.0, 0.0, 0.0);
        glScalef(0.191,0.19,0.399);
        glutSolidSphere(1.0,50,50);
    glPopMatrix();

    // eye ball otline
    glPushMatrix();
        glColor3d(0,0,0);
        glTranslated(0.700,0.27,-3.6);
        glRotated(-64, 1.0, 0.0, 0.0);
        glScalef(0.191,0.19,0.399);
        glutSolidSphere(1.1,50,50);
    glPopMatrix();

    //bulg
    glPushMatrix();
        glColor3f(0.77254,0.82745,0.929411);
        glTranslated(1.0,0.37,-6.0);
        glRotated(-60, 1.0, 0.0, 0.0);
        glutSolidSphere(1.0,50,50);
    glPopMatrix();

    // inner bulg
    glPushMatrix();
        glColor3d(0.85 ,0.85,0.85);
        glTranslated(1.0,0.37,-5.5);
        glRotated(-60, 1.0, 0.0, 0.0);
        glutSolidSphere(0.85,50,50);
    glPopMatrix();

    //outer torus
    glPushMatrix();
        glColor3d(0.560784,0.560784, 0.737255);
        //glColor3b(0.5725490,0.666666,0.831372);
        glTranslated(2.5,0.5,-6);
        glRotated(-10, 1.0, 0.0, 0.0);
        glScalef(0.3,0.3,0.25);
        glutSolidTorus(2.99, 3.0, 10, 50);
    glPopMatrix();

    //next layer
    glPushMatrix();
        glColor3f(0.75686,0.4196078,0.4256862);
        glTranslated(2.3,0.49,-5.5);
        glRotated(-10, 1.0, 0.0, 0.0);
        glScalef(0.279,0.279,0.23);
        glutSolidTorus(2.7599, 2.750, 10, 50);
    glPopMatrix();

    glPushMatrix();
        glColor3d(0.92156,0.815686,0.556862);
        glTranslated(1.92,0.4,-4.3999);
        glRotated(-10, 1.0, 0.0, 0.0);
        glScalef(0.24,0.24,0.09);
        glutSolidTorus(2.0, 3.0, 10, 50);
    glPopMatrix();

    //inner most
    glPushMatrix();
        glColor3d(0.650980,0.345098,0.4);
        glTranslated(1.68,0.37,-4.0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glScalef(0.17,0.17,0.09);
        glutSolidTorus(3.0, 3.0, 10, 50);
    glPopMatrix();

    //cillary body upper
    glPushMatrix();
        glColor3f(0.42745,0.258823,0.188235);
        glLineWidth(6.0);
        glTranslated(0.75,1.02,-3.799);
        glRotated(100, 1.0, 0.0, 0.0);
        glScalef(0.05,0.5,1.0);
        glutWireCone(1,0.56,12,0.5);
    glPopMatrix();

    //cillary lower
    glPushMatrix();
        glColor3f(0.42745,0.258823,0.188235);
        glLineWidth(6.0);
        glTranslated(0.79,-0.430,-3.9);
        glRotated(-100, 1.0, 0.0, 0.0);
        glScalef(0.05,0.5,1.0);
        glutWireCone(1,0.56,12,0.5);
    glPopMatrix();

    // optical fibre outer
    glPushMatrix();
        glColor3f(0.58431372,0.631372, 0.7686274);
        glTranslated(6.7,-0.657,-8);
        glScaled(1,1,1);
        glRotated(-150,1,1,0);
        GLUquadricObj *cylinder1;
        cylinder1 = gluNewQuadric();
        gluQuadricDrawStyle(cylinder1,GLU_LINE);
        gluCylinder(cylinder1,0.57,0.57,1.2,1005,19005);
    glPopMatrix();

    // inner optical Fibre
    glPushMatrix();
        glColor3f(0.92156,0.815686,0.556862);
        glTranslated(3.5,-0.397,-4);
        glScaled(0.75,0.75,0.75);
        glRotated(-150,1,1,0);
        GLUquadricObj *cylinder2;
        cylinder2 = gluNewQuadric();
        gluQuadricDrawStyle(cylinder2,GLU_LINE);
        gluCylinder(cylinder1,0.3,0.3,1.0,1005,19005);
    glPopMatrix();

    //optic nurve
    glPushMatrix();
        glColor3f(0.650980,0.345098,0.4);
        glTranslated(3.0,-0.660,-2.5);
        glScaled(0.1,0.1,0.15);
        glRotated(-130.50,1,1,0);
        GLUquadricObj *cylinder3;
        cylinder3 = gluNewQuadric();
        gluQuadricDrawStyle(cylinder2,GLU_LINE);
        gluCylinder(cylinder2,0.3,0.3,12.0,1005,19005);
    glPopMatrix();

    draw_mark_line(1.49 ,2.2,0.0,3.4);
        display_string(-1.980  ,4.130 ,"PUPIL",2);
        draw_mark_line(1.00 ,-1.2,0.5,-3.5);
        display_string(0.00 ,-4.1999  ,"CORNEA",2);
        draw_mark_line(1.89 ,0.0,1.5,-3.9);
        display_string(1.589,-4.40 ,"LENS",2);
        draw_mark_line(2.09,4.2,3.0,7.1);
        display_string(3.2 ,7.5 ,"CILLARY MUSCLE",2);
        draw_mark_line(4.09 ,6.3,6.0,7.1);
        display_string(6.2 ,7.0 ,"CHOROID",2);
        draw_mark_line(6.59 ,5.0,8.0,5.3);
        display_string(8.999 ,5.6,"SCLERA",2);
        draw_mark_line(4.5,6.0,7.0,6.3);
        display_string(7.6 ,6.4,"RETINA",2);
        draw_mark_line(7.5,-1.0,6.5,-4.3);
        display_string(6.2 ,-5.1,"OPTICAL NERVE",2);
    //end of 3D-EYE

if((xt == 1) && (xu == 0) ){


    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-9.0, 9.0, -9.0, 9.0, 0.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //build house
    glPushMatrix();
        glTranslated(-9,-1.0,0);
        glRotated(-360,0,0,1);
        glScaled(0.6,0.6,0.6);
        home();
    glPopMatrix();

    //start of the lighting
    glColor3f(1.0, 0.972549, 0.8627);
    glRectf(-9.5 ,-0.5,0.32,2);

    glPushMatrix();
        glColor3f(1.0, 0.972549, 0.8627);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.32,2);
        glVertex2f(0.32,-0.5);
        glVertex2f(2.0,1.0);
        glEnd();
    glPopMatrix();
    //end of lighting

    //inverted house on the optical fibre
   glPushMatrix();
        glTranslated(6.9,3,0);
        glRotated(-180,0,0,1);
        glScaled(0.2,0.2,5);
        home();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.972549, 0.8627);
        glBegin(GL_TRIANGLES);
        glVertex2f(2.0,1.0);
        glVertex2f(2.0,1.0);
        glVertex2f(6.9,1.0);
        glVertex2f(6.6,3.70);
        glEnd();
    glPopMatrix();
}
     glPointSize(12);
     if(xt == 1){
        for(i=3;i>0;i = i-0.4){
        glBegin(GL_POINTS); // render with points
           //glColor3d(0.92156,0.815686,0.556862);
            glColor3b(1,0,0);
            glVertex3f(7.1,3.5-i,-5); //display a point
        glEnd();
        }
        glBegin(GL_POINTS);
            glColor3b(1,0,0);
            glVertex3f(7.1,2.5,-5);
        glEnd();
    }




 //labelling the parts of the eye
        draw_mark_line(1.49 ,2.2,0.0,3.4);
        display_string(-1.980  ,4.130 ,"PUPIL",2);
        draw_mark_line(1.00 ,-1.2,0.5,-3.5);
        display_string(0.00 ,-4.1999  ,"CORNEA",2);
        draw_mark_line(1.89 ,0.0,1.5,-3.9);
        display_string(1.589,-4.40 ,"LENS",2);
        draw_mark_line(2.09,4.2,3.0,7.1);
        display_string(3.2 ,7.5 ,"CILLARY MUSCLE",2);
        draw_mark_line(4.09 ,6.3,6.0,7.1);
        display_string(6.2 ,7.0 ,"CHOROID",2);
        draw_mark_line(6.59 ,5.0,8.0,5.3);
        display_string(8.999 ,5.6,"SCLERA",2);
        draw_mark_line(4.5,6.0,7.0,6.3);
        display_string(7.6 ,6.4,"RETINA",2);
        draw_mark_line(7.5,-1.0,6.5,-4.3);
        display_string(6.2 ,-5.1,"OPTICAL NERVE",2);

    glutSwapBuffers();

    }

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(2550,2540);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Human Eye");
    glutReshapeFunc(myreshape);
    //glutDisplayFunc(display);
    glutKeyboardFunc(NormalKey);
    glutReshapeFunc(ReSizeGLScene);
    glutSpecialFunc(SpecialKeyFunc);
    glutDisplayFunc(display);
    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutMainLoop();
    return EXIT_SUCCESS;
}
