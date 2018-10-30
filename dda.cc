// Algoritma DDA

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

//identifier fungsi
void init();
void display(void);
void dda(void);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char* judul_window = (char *)("DDA Algorithm");

int main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window);


	init();

	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background
	glColor3f(0.0, 1.0, 0.0); //set warna titik
	glPointSize(5.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	dda(); //panggil fungsi dda
	glutSwapBuffers(); //swap buffer
}

void dda(void) {
    int steps;
    float *xy, *inc;
    int *d, *xy2, *xy1;
    xy1 = (int *)calloc(2, sizeof(int));
    xy2 = (int *)calloc(2, sizeof(int));
    inc = (float *)calloc(2, sizeof(float));
    xy = (float *)calloc(2, sizeof(float));
    d = (int *)calloc(2, sizeof(int));
    cout << "Input Starting Coordinate x: ";
    cin >> xy1[0];
    cout << "Input Starting Coordinate y: ";
    cin >> xy1[1];
    cout << "Input Finish Coordinate x: ";
    cin >> xy2[0];
    cout << "Input Finish Coordinate y: ";
    cin >> xy2[1];
    d[0] = xy2[0] - xy1[0];
    d[1] = xy2[1] - xy1[1];
    //cout << d[0] << ' ' << d[1] << endl;
    steps = abs((abs(d[0]) > abs(d[1])) ? d[0] : d[1]);
    steps = (steps != 0) ? steps : 1;
    //cout << steps << endl;
    inc[0] = (float) d[0] / (float) steps;
    inc[1] = (float) d[1] / (float) steps;
    xy[0] = xy1[0];
    xy[1] = xy1[1];
    //cout << inc[0] << ' ' << inc[1] << endl;
    //exit(0);
    glBegin(GL_POINTS);
    while(1){
        //cout << xy[0] << ' ' << xy[1] << endl;
        glVertex2i(round(xy[0]), round(xy[1]));
        xy[0] += inc[0];
        xy[1] += inc[1];
        if(round(xy[0]) == xy2[0] && round(xy[1]) == xy2[1]) break;
    }
    //cout << dx << ' ' << dy << endl;
	//cout << x_inc << ' ' << y_inc << endl;
	//gambar titik awal
	//glBegin(GL_POINTS);
	//glVertex2i(x, y); // gambar titik awal
	free(xy);
	free(inc);
	free(d);
    free(xy2);
    free(xy1);
	glEnd();
	glFlush();
}

