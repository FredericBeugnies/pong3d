// pong3d.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#include "Color.h"
#include "glHelpers.h"


Color player1_scoreColor( 255, 255, 0 );
Color player2_scoreColor( 0, 255, 0 );
Color lightConeColor( 255, 0, 0 );
Color lightBulbColor( 255, 255, 0 );
Color ballColor( 0, 255, 255 ); // cyan
Color barColor1( 200, 0, 0 );
Color barColor2( 0, 0, 200 );
Color playerBarColor1( 0, 0, 255 );
Color playerBarColor2( 255, 255, 255 );
Color playerBarColor3( 60, 80, 150 );


GLfloat	 lightPosA[] = { 0.0f, 0.0f, 55.0f, 1.0f };
GLfloat	 lightPosB[] = { 0.0f, 0.0f, 65.0f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  DiffuseLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat  ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  spotDirA[] = { 0.0f, 0.0f, -1.0f };
GLfloat  spotDirB[] = { 0.0f, 0.0f, -1.0f };

GLfloat xRotA = 70.0f;
GLfloat yRotA = 0.0f;
GLfloat xRotB = 0.0f;
GLfloat yRotB = 0.0f;
GLfloat xVitRotA = 2.0f;
GLfloat yVitRotB = 2.0f;
GLfloat PosBarA = 1.0f;
GLfloat PosBarB = 1.0f;
GLfloat VitBarA = 2.0f;
GLfloat VitBarB = 2.0f;
GLfloat SphereX = 53.0f;
GLfloat SphereY = 0.0f;
GLfloat dirX = -1.0f;
GLfloat dirY = 1.0f;
GLfloat xDecorRot = 0.0f;
GLfloat xDecorVit = 0.0f;

bool perdu = false;
bool pause = false;
bool fini = false;

int ScoreA = 0;
int ScoreB = 0;
int i;

void ResetGameState()
{
    xRotA = 70.0f;
    yRotA = 0.0f;
    xRotB = 0.0f;
    yRotB = 0.0f;
    xVitRotA = 2.0f;
    yVitRotB = 2.0f;
    PosBarA = 1.0f;
    PosBarB = 1.0f;
    VitBarA = 2.0f;
    VitBarB = 2.0f;
    SphereX = 53.0f;
    SphereY = 0.0f;
    dirX = -1.0f;
    dirY = 1.0f;
    xDecorRot = 0.0f;
    xDecorVit = 0.0f;

    perdu = false;
    pause = false;
    fini = false;

    ScoreA = 0;
    ScoreB = 0;
}

void Decor()
{
    GLfloat fZ = 0.0;
    GLfloat bZ = -8.0;

    glFrontFace(GL_CCW);

    glBegin(GL_QUADS);

    // Barre du dessus
    // Face avant
    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor( barColor1 );
    glVertex3f(-60.0f, 50.0f, fZ);
    glVertex3f(-60.0f, 35.0f, fZ);
    glColor( barColor2 );
    glVertex3f(60.0f, 35.0f, fZ);
    glVertex3f(60.0f, 50.0f, fZ);

    // Face avant
    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor( barColor1 );
    glVertex3f(-60.0f, -35.0f, fZ);
    glVertex3f(-60.0f, -50.0f, fZ);
    glColor( barColor2 );
    glVertex3f(60.0f, -50.0f, fZ);
    glVertex3f(60.0f, -35.0f, fZ);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-60.0f, -50.0f, fZ);
    glVertex3f(-60.0f, -50.0f, bZ);
    glVertex3f(60.0f, -50.0f, bZ);
    glVertex3f(60.0f, -50.0f, fZ);
    glEnd();

    glFrontFace(GL_CW);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);

    glVertex3f(-60.0f, 50.0f, bZ);
    glVertex3f(-60.0f, 35.0f, bZ);
    glColor( barColor1 );
    glVertex3f(60.0f, 35.0f, bZ);
    glVertex3f(60.0f, 50.0f, bZ);

    glColor( barColor2 );
    glVertex3f(-60.0f, -35.0f, bZ);
    glVertex3f(-60.0f, -50.0f, bZ);
    glColor( barColor1 );
    glVertex3f(60.0f, -50.0f, bZ);
    glVertex3f(60.0f, -35.0f, bZ);

    glColor3ub(130, 130, 130);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-60.0f, 35.0f, fZ);
    glVertex3f(60.0f, 35.0f, fZ);
    glVertex3f(60.0f, 35.0f, bZ);
    glVertex3f(-60.0f, 35.0f, bZ);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-60.0f, -35.0f, fZ);
    glVertex3f(-60.0f, -35.0f, bZ);
    glVertex3f(60.0f, -35.0f, bZ);
    glVertex3f(60.0f, -35.0f, fZ);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glColor( barColor1 );
    glVertex3f(-60.0f, 50.0f, fZ);
    glVertex3f(-60.0f, 35.0f, fZ);
    glColor( barColor2 );
    glVertex3f(-60.0f, 35.0f, bZ);
    glVertex3f(-60.0f, 50.0f, bZ);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glColor( barColor2 );
    glVertex3f(60.0f, 35.0f, fZ);
    glVertex3f(60.0f, 50.0f, fZ);
    glColor( barColor1 );
    glVertex3f(60.0f, 50.0f, bZ);
    glVertex3f(60.0f, 35.0f, bZ);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glColor( barColor1 );
    glVertex3f(-60.0f, -35.0f, fZ);
    glVertex3f(-60.0f, -50.0f, fZ);
    glColor( barColor2 );
    glVertex3f(-60.0f, -50.0f, bZ);
    glVertex3f(-60.0f, -35.0f, bZ);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glColor( barColor2 );
    glVertex3f(60.0f, -50.0f, fZ);
    glVertex3f(60.0f, -35.0f, fZ);
    glColor( barColor1 );
    glVertex3f(60.0f, -35.0f, bZ);
    glVertex3f(60.0f, -50.0f, bZ);
    glEnd();
}


void AfficheBarre(void)
{
    glFrontFace(GL_CCW);

    glBegin(GL_QUADS);

    glColor( playerBarColor1 );

    //Face avant
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-2.f, -6.f, 4.f);
    glVertex3f(2.f, -6.f, 4.f);
    glVertex3f(2.f, 6.f, 4.f);
    glVertex3f(-2.f, 6.f, 4.f);

    //  Face arriere
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-2.f, -6.f, -4.f);
    glVertex3f(-2.f, 6.f, -4.f);
    glVertex3f(2.f, 6.f, -4.f);
    glVertex3f(2.f, -6.f, -4.f);

    glColor( playerBarColor2 );

    // Face superieure
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-2.f, 6.f, -4.f);
    glVertex3f(-2.f, 6.f, 4.f);
    glVertex3f(2.f, 6.f, 4.f);
    glVertex3f(2.f, 6.f, -4.f);

    // Face inferieure
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-2.f, -6.f, -4.f);
    glVertex3f(2.f, -6.f, -4.f);
    glVertex3f(2.f, -6.f, 4.f);
    glVertex3f(-2.f, -6.f, 4.f);

    glColor( playerBarColor3 );

    // face de droite
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(2.f, -6.f, -4.f);
    glVertex3f(2.f, 6.f, -4.f);
    glVertex3f(2.f, 6.f, 4.f);
    glVertex3f(2.f, -6.f, 4.f);

    // Face de gauche
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-2.f, -6.f, -4.f);
    glVertex3f(-2.f, -6.f, 4.f);
    glVertex3f(-2.f, 6.f, 4.f);
    glVertex3f(-2.f, 6.f, -4.f);
    glEnd();
}

void Carre(void)
{
    glBegin(GL_LINES);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);

    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);

    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);

    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
}

void DessinerScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();

    // Score A
    glTranslatef(-35.0, -25.0, -50.0);
	glColor( player1_scoreColor );
    for (i = 0; i < ScoreA; i++)
    {
        Carre();
        glTranslatef(5.0, 0.0, 0.0);
    }

    // Score B
    glPopMatrix();
    glPushMatrix();
    glTranslatef(35.0, -25.0, -50.0);
	glColor( player2_scoreColor );
	for (i = 0; i < ScoreB; i++)
    {
        Carre();
        glTranslatef(-5.0, 0.0, 0.0);
    }

    // Les 2 spots
    glPopMatrix();
    glTranslatef(0.0f, 0.0f, -130.0f);
    glRotatef(xDecorRot, 0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(yRotA, 0.0f, 1.0f, 0.0f);
    glRotatef(xRotA, 1.0f, 0.0f, 0.0f);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosA);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirA);

	glColor( lightConeColor );
    glTranslatef(lightPosA[0], lightPosA[1], lightPosA[2]);
    glutSolidCone(4.0f, 6.0f, 15, 15);

    glPushAttrib(GL_LIGHTING_BIT);

    glDisable(GL_LIGHTING);
    glColor( lightBulbColor );
    glutSolidSphere(3.0f, 15, 15);

    glPopAttrib();

    glPopMatrix();
    glPushMatrix();

    glRotatef(yRotB, 0.0f, 1.0f, 0.0f);
    glRotatef(xRotB, 1.0f, 0.0f, 0.0f);

    glLightfv(GL_LIGHT1, GL_POSITION, lightPosB);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirB);

	glColor( lightConeColor );

    glTranslatef(lightPosB[0], lightPosB[1], lightPosB[2]);

    glutSolidCone(4.0f, 6.0f, 15, 15);

    glPushAttrib(GL_LIGHTING_BIT);

    glDisable(GL_LIGHTING);
	glColor( lightBulbColor );
	glutSolidSphere(3.0f, 15, 15);

    glPopAttrib();

    glPopMatrix();
    glPushMatrix();

    // Decor

    glTranslatef(0.0f, 0.0f, 4.0f);
    Decor();

    // Balle

    glPopMatrix();
    glPushMatrix();
    glColor( ballColor );
    glTranslatef(SphereX, SphereY, 0.0f);
    glFrontFace(GL_CCW);
    glutSolidSphere(3.0, 30, 30);

    // Barre A
    glPopMatrix();
    glPushMatrix();
    glTranslatef(58.0f, PosBarA, 0.0f);
    AfficheBarre();

    // Barre B
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-58.0f, PosBarB, 0.0f);
    AfficheBarre();
    glPopMatrix();

    glutSwapBuffers();
}


void SetupRC()
{
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    // Spot A
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosA);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirA);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 91.f);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 100.0f);
    glLoadIdentity();

    // Spot B
    glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosB);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirB);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 91.0f);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 100.0f);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
}


void TimerFunction(int value)
{
    if (!fini)
    {
        if (!pause)
        {
            if ((xDecorRot + xDecorVit < 360.0) && (xDecorRot + xDecorVit > -360.0))
            {
                xDecorRot += xDecorVit;
            }
            else
            {
                if (xDecorRot + xDecorVit < 360.0)
                    xDecorRot = xDecorRot + xDecorVit - 360.0;
                else
                    xDecorRot = xDecorRot + xDecorVit + 360.0;
            }

            if (xRotA + xVitRotA < 360. || xRotA + xVitRotA > -360.)
                xRotA = xRotA + xVitRotA;
            else
                xRotA = 0.;

            if (yRotB + yVitRotB < 360. || yRotB + yVitRotB > -360.)
                yRotB = yRotB + yVitRotB;
            else
                yRotB = 0.;

            if (!perdu)
            {
                if ((SphereY + dirY >= 32.0) || (SphereY + dirY <= -32.0))
                    dirY = -dirY;

                if (SphereX + dirX < -54.0)
                {
                    if ((SphereY > (PosBarB + 7.0f)) || (SphereY < (PosBarB - 7.0f)))
                    {
                        perdu = true;
                        ScoreA++;
                        if (ScoreA == 5) fini = true;
                    }
                    else
                    {
                        dirX = -dirX;
                    }
                }
                else if (SphereX + dirX > 54.0)
                {
                    if ((SphereY > (PosBarA + 7.0f)) || (SphereY < (PosBarA - 7.0f)))
                    {
                        perdu = true;
                        ScoreB++;
                        if (ScoreB == 5) fini = true;
                    }
                    else
                    {
                        dirX = -dirX;
                    }
                }
            }
            else
            {
                if ((SphereX > 90.0) || (SphereX < -90.0))
                {
                    SphereX = 0.0;
                    SphereY = 0.0;
                    perdu = false;
                }
            }
            SphereX += dirX;
            SphereY += dirY;
        }
        //if (GetAsyncKeyState(0x50)) pause = !pause;
    }

    glutTimerFunc(10, TimerFunction, 1);
    glutPostRedisplay();

}


void ChangeSize(int w, int h)
{
    //GLfloat nRange = 100.0f;
    GLfloat fAspect;

    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, fAspect, 1.0, 200.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    switch (theKey)
    {
        /* 'p' key -> toggle pause */
    case 'p':
        pause = !pause;
        break;
        /* reset game state */
    case 'm':
        ResetGameState();;
        break;
        /* lightspots management */
    case 'r':
        if (xVitRotA < 20.0)
            xVitRotA += 0.5;
        break;
    case 't':
        if (yVitRotB < 20.0)
            yVitRotB += 0.5;
        break;
    case 'f':
        if (xVitRotA > -20.0)
            xVitRotA -= 0.5;
        break;
    case 'g':
        if (yVitRotB > -20.0)
            yVitRotB -= 0.5;
        break;
        /* scene rotation */
    case 'z':
        if (xDecorVit < 5.0)
            xDecorVit += 0.2;
        break;
    case 's':
        if (xDecorVit > -5.0)
            xDecorVit -= 0.2;
        break;
        /* ball speed */
    case 'e':
        if (fabs(dirX) < 3.0)
        {
            dirX = dirX * 1.2;
            dirY = dirY * 1.2;
        }
        break;
    case 'd':
        if (dirX != 0.0)
        {
            dirX = dirX * 0.8;
            dirY = dirY * 0.8;
        }
        break;
        /* player bars */
    case 'a':
        if (PosBarB + VitBarB < 30)
            PosBarB += VitBarB;
        break;
    case 'q':
        if (PosBarB - VitBarB > -30)
            PosBarB -= VitBarB;
        break;
    case 'y':
        if (PosBarA + VitBarA < 30)
            PosBarA += VitBarA;
        break;
    case 'h':
        if (PosBarA - VitBarA > -30)
            PosBarA -= VitBarA;
        break;
    default:
        break;
    }
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Pong3D");
    glutReshapeWindow(1280, 960);
    glutFullScreen();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(DessinerScene);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(50, TimerFunction, 1);
    SetupRC();
    glutMainLoop();
    return 0;
}
