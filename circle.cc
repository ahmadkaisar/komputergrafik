// Algoritma DDA

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

//identifier fungsi
void init();
void display(void);
void lingkaran(void);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char* judul_window = (char *)("Circle Algorithm");

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
	lingkaran(); //panggil fungsi dda
	glutSwapBuffers(); //swap buffer
}

void lingkaran(void) {
    int p, r;
    int *xy, *xyc;
    xyc = (int *)calloc(2, sizeof(int));
    xy = (int *)calloc(2, sizeof(int));
    cout << "Input Coordinate x: ";
    cin >> xyc[0];
    cout << "Input Coordinate y: ";
    cin >> xyc[1];
    cout << "Input Rings: ";
    cin >> r;
    p = 1 - r;
    xy[0] = 0;
    xy[1] = r;
    glBegin(GL_POINTS);
    while(xy[0] <= xy[1]){
        //cout << xy[0] << ' ' << xy[1] << endl;
        xy[0]++;
        if(p < 0) p = p + 2 * xy[0] + 1;
        else{
            xy[1]--;
            p = p + 2 * (xy[0] - xy[1]) + 1;
        }
        glVertex2i(xyc[0] + xy[0], xyc[1] + xy[1]);
        glVertex2i(xyc[0] - xy[0], xyc[1] + xy[1]);
        glVertex2i(xyc[0] + xy[0], xyc[1] - xy[1]);
        glVertex2i(xyc[0] - xy[0], xyc[1] - xy[1]);
        glVertex2i(xyc[0] + xy[1], xyc[1] + xy[0]);
        glVertex2i(xyc[0] - xy[1], xyc[1] + xy[0]);
        glVertex2i(xyc[0] + xy[1], xyc[1] - xy[0]);
        glVertex2i(xyc[0] - xy[1], xyc[1] - xy[0]);
    }
    //cout << dx << ' ' << dy << endl;
	//cout << x_inc << ' ' << y_inc << endl;
	//gambar titik awal
	//glBegin(GL_POINTS);
	//glVertex2i(x, y); // gambar titik awal
	free(xy);
    free(xyc);
	glEnd();
	glFlush();
}


