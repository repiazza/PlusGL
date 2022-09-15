#include <stdio.h>
#include <unistd.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>


// DEFINES DE LINHAS
//  LIMITES
#define Y_VERTEX_BOT         1.0f
#define Y_VERTEX_TOP        -1.0f
#define X_VERTEX_RIGHT       1.0f
#define X_VERTEX_LEFT       -1.0f

// POSICOES CHAVE
#define Y_VERTEX_CENTER_BOT  0.25f
#define Y_VERTEX_CENTER_TOP -0.25f
#define X_VERTEX_CENTER_RIGHT  0.25f
#define X_VERTEX_CENTER_LEFT  -0.25f

// CENTRO
#define X_Y_VERTEX_CENTER    0.0f

// Deixei essa cola aqui pq uso isso nos meus programas,
// pode ser util aqui, acabei transformando em macro
// typedef void  *(* GL_RGB_COLOR)(GLfloat fRedNumber,GLfloat fGreenNumber,GLfloat fBlueNumber);

#define GL_RGB_RED glColor3f(1.0f, 0.0f, 0.0f)
#define GL_RGB_GRN glColor3f(0.0f, 1.0f, 0.0f)
#define GL_RGB_BLU glColor3f(0.0f, 0.0f, 1.0f)

void vDrawSingleLine(GLfloat fX_Vrt_Ini, GLfloat fY_Vrt_Ini, GLfloat fX_Vrt_Dest, GLfloat fY_Vrt_Dest){

    glBegin(GL_LINES);

    GL_RGB_RED;
    glLineWidth(50.0f);

    glVertex2f(fX_Vrt_Ini,  fY_Vrt_Ini);
    glVertex2f(fX_Vrt_Dest, fY_Vrt_Dest);

    glEnd();
}
 
void display(void)
{
//     int const w = glutGet(GLUT_WINDOW_WIDTH);
//     int const h = glutGet(GLUT_WINDOW_HEIGHT);

    glScissor(100, 100, 400, 400);
    glEnable(GL_SCISSOR_TEST);

    // queria que esse canal de opacidade funcionasse :(
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Meio de campo

    vDrawSingleLine(X_Y_VERTEX_CENTER, Y_VERTEX_BOT, X_Y_VERTEX_CENTER, Y_VERTEX_TOP);


//     vDrawSingleLine(X_VERTEX_LEFT+0.40f, Y_VERTEX_BOT, X_VERTEX_LEFT+0.40f, Y_VERTEX_TOP);
//     vDrawSingleLine(X_VERTEX_LEFT+0.40f, Y_VERTEX_BOT, X_VERTEX_LEFT+0.40f, Y_VERTEX_TOP);
//     vDrawSingleLine(X_VERTEX_RIGHT-0.1f, Y_VERTEX_BOT, X_VERTEX_RIGHT-0.1f, Y_VERTEX_TOP);

    glFlush();  // Render now
}   

static void reshape(int w, int h) {
    glViewport(100, 100, 400, 400);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.5, 1.5);
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);

   // Initialize GLUT - Nao sei rpa q serve , tem uns buffer duplo e pans parece interessante
   // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   // glutInitDisplayMode(GLUT_RGB);

   // inicializacao de Janela
   glutInitWindowPosition(300, 300);
   glutInitWindowSize(600, 600);
   glutCreateWindow("Plus Plong");

//    glEnable(GL_LIGHT0);
//    glEnable(GL_NORMALIZE);

   glutDisplayFunc(display);     // esse callback tem que sempre registrar pq quando redesenha chama ele

//   Quando fizer esse reshape vai ter que recalcular as proporcoes das lines
//   por isso nao mexi nisso, mas eh o certo
//   glutReshapeFunc(reshape);

   glutMainLoop();                        // Loop eterno de redraw ( main do programa ) principio de toda animacao

   return 0;
}

