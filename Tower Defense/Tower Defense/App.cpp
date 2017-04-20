#include "App.h"

enum Menu {Main = 0, LevelSelect = 1, Play = 3};

float tileWidth = 0.18f, tileHeight = 0.18f;
//int offsetW = 1, offsetH = 1;

int map[9][11] = { //our map
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1 },
	{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1 },
};

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
	#if defined WIN32
    grass = loadTexture("Grass.bmp");
    path = loadTexture("Path.bmp");
	enemy1 = loadTexture("Enemy1.bmp");
	#else
	monalisa = loadTexture("monalisa.bmp");
	wall = loadTexture("wall.bmp");
	#endif
    
    //background = new TexRect(-1, 1, 2, 2);
    painting = new TexRect(-1.0f, 0.98f, 0.174f, 0.174f); //top corner is (-1.0f, 0.98f) not -1, 1 so y goes from .98 to -.98
}


GLuint App::loadTexture(const char *filename) {
    GLuint texture_id;
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    RgbImage theTexMap( filename );
    
    // Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
    //    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );
    
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    

    
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
    
    return texture_id;
    
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, enemy1);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0 - tileHeight);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(0 + tileWidth, 0 - tileHeight);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(0 + tileWidth, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	for (int xTile = 1; xTile < 12; xTile++)
	{
		for (int yTile = 1; yTile < 10; yTile++)
		{
			if (map[yTile - 1][xTile - 1] == 1) //if grass
			{
				std::cout << map[yTile - 1][xTile - 1] << ", " << map[yTile][xTile] << ", " << yTile << ", " << xTile << std::endl;
				glBindTexture(GL_TEXTURE_2D, grass);
				painting->draw(tileWidth * xTile, tileHeight * yTile);
				//offsetH++;
				//glDisable(GL_TEXTURE_2D);
			}
			else if (map[yTile - 1][xTile - 1] == 0) //else if path
			{
				//std::cout << map[yTile - 1][xTile - 1] << ", " << map[yTile - 1][xTile - 1] << std::endl;
				glBindTexture(GL_TEXTURE_2D, path);
				painting->draw(tileWidth * xTile, tileHeight * yTile);
				//offsetH++;
				//glDisable(GL_TEXTURE_2D);
			}
		}
		//offsetW++;
	}
    
    glDisable(GL_TEXTURE_2D);
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
