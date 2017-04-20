#include "App.h"
#include "Tower.h"
#include "CreateButton.h"

Tower towers;
CreateButton button;

std::vector<Tower> towerVec;
std::vector<CreateButton> buttons;

bool loopDone = false;

enum Menu {Main = 0, Options = 1, LevelSelect = 2, Play = 3};

Menu currentMenu = Main;

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
   /* glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(1.0, 0.0, 0.0, 1.0);
	
	std::cout << currentMenu << std::endl;
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();*/

	std::cout << currentMenu << std::endl;
    
	if (currentMenu == Main)
	{
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << currentMenu << endl;
		// Set background color to white
		glClearColor(1.0, 1.0, 1.0, 1.0);

		//button.make(0.0f, 0.0f, 0.4f, 0.1f); 
		//buttons.push_back(CreateButton(0.0f, 0.0f, 0.4f, 0.1f));

		if (buttons.size() > 0)
		{
			for (int j = 0; j < buttons.size(); j++)
			{
				for (int k = 1; k < buttons.size() - 1; j++)
				{
					if (buttons.at(j).x == buttons.at(k).x && buttons.at(j).y == buttons.at(k).y)
					{
						buttons.push_back(CreateButton(0.0f, 0.0f, 0.4f, 0.1f));
						loopDone = true;
						break;
					}
				}

				if (loopDone)
					break;

			}
		}
		else
		{
			buttons.push_back(CreateButton(0.0f, 0.0f, 0.4f, 0.1f));
		}

		button.DrawButton(buttons);

		loopDone = false;

		//button.make(-0.5f, 0.0f, 0.4f, 0.1f);

		// Set up the transformations stack
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	if (currentMenu == Options)
	{
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << currentMenu << endl;
		// Set background color to white
		glClearColor(1.0, 1.0, 1.0, 1.0);

		// Set up the transformations stack
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(-0.48f, -0.07f);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"ONE PLAYER");

		glRasterPos2f(0.0125f, -0.07f);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"TWO PLAYER");

		glColor3f(0.75f, 0.75f, 0.75f);

		glBegin(GL_QUADS);

		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.4f, 0.0f);
		glVertex2f(0.4f, -0.1f);
		glVertex2f(0.0f, -0.1f);

		glVertex2f(-0.5f, 0.0f);
		glVertex2f(-0.1f, 0.0f);
		glVertex2f(-0.1f, -0.1f);
		glVertex2f(-0.5f, -0.1f);

		glEnd();
	}

	if (currentMenu == Play)
	{

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Set background color to white
		glClearColor(1.0, 1.0, 1.0, 1.0);

		// Set up the transformations stack
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Set Color
		glColor3d(1.0, 1.0, 1.0);

		towers.Draw(towerVec);

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
					//std::cout << map[yTile - 1][xTile - 1] << ", " << map[yTile][xTile] << ", " << yTile << ", " << xTile << std::endl;
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


		/*if (game.player1Won())
		{
			// Set background color to white
			glClearColor(1.0, 1.0, 1.0, 1.0);
			glColor3f(0.5f, 0.0f, 0.5f);

			// Set up the transformations stack
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(-1.0f, 0.0f, -1.0f);
			glScalef(0.0018f, 0.0015f, 1.0f);

			glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char *)"  IT'S A TIE! ");
		}*/
	}

	
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){ //Left click button down
    // Update app state
    mx = x;
    my = y;

	if (currentMenu == Play)
	{
		towerVec.push_back(Tower(mx, my));
	}
    
    // Redraw the scene
    redraw();
}

void App::mouseUp(float x, float y) //Left click button up
{
	mx = x;
	my = y;

	if (button.Contains(mx, my, buttons))
	{
		currentMenu = Play;
	}

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
