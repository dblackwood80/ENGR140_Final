#include "App.h"
#include "Tower.h"
#include "Enemy.h"
#include "CreateButton.h"
#include "Level.h"
#include "Store.h"
#include "Player.h"
#include <fstream>
#include <chrono>

CreateButton button;
Enemy enemy1;
Tower tower;
Store store;
Player player;

Level levels(Vector2(-1.0f, 0.98f));
typedef std::chrono::steady_clock Clock;
int nodes = 0;

float xChange = 0, yChange = 0;
std::vector<Tower> towerVec;
std::vector<CreateButton> buttons;

bool loopDone = false;

//std::ifstream level;

enum Menu {Main = 0, Options = 1, LevelSelect = 2, Play = 3};

Menu currentMenu = Main;

float tileWidth = 0.18f, tileHeight = 0.18f;
//int offsetW = 1, offsetH = 1;

//std::vector<std::vector<int> > map(9, std::vector<int> (11));

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0; 
    
	#if defined WIN32
    grass = loadTexture("Grass_Normal.bmp");
    path = loadTexture("Path.bmp");
	enemyTexture1 = loadTexture("Enemy1.bmp");
	greenTower = loadTexture("Turret_Green.bmp");
	#else
	monalisa = loadTexture("monalisa.bmp");
	wall = loadTexture("wall.bmp");
	#endif
    
    //background = new TexRect(-1, 1, 2, 2);
    scene = new TexRect(-1.0f, 0.98f, 0.18f, 0.18f); //top corner is (-1.0f, 0.98f) not -1, 1 so y goes from .98 to -.98 //.18 used to be .174
}

void App::initializeLevel(std::string filename)
{
	enemy1.init(enemyTexture1, Vector2(-1.0f, 0.98f), 1000, 10, 0.005f);
	enemy1.SetWaypoints(levels.Waypoints());
	player.init(levels, greenTower);
	
	std::cout << "should be once" << levels.Waypoints().at(0).X << std::endl;
//	towerVec.push_back(Tower(greenTower, Vector2(0.0f, 0.0f)));
	/*level.open("Levels/" + filename);

	if (level.is_open())
	{
	std::cout << "opened" << std::endl;
	}

	while (level.good())
	{
	for (int i = 0; i < 11; i++)
	{
	for (int j = 0; j < 9; j++)
	{
	level >> map[i][j];
	std::cout << map[j][i];
	}
	std::cout << std::endl;
	}
	}

	level.close();
	std::cout << "done" << std::endl;

	for (int k = 0; k < 11; k++)
	{
	for (int l = 0; l < 9; l++)
	{
	std::cout << map[k][l];
	}
	std::cout << std::endl;
	}*/
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
    
    // Set background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
	
	//std::cout << currentMenu << std::endl;
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	//std::cout << currentMenu << std::endl;
    
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
		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();

		glPushMatrix();

		// Set Color
		glColor3d(1.0, 1.0, 1.0);
		

		tower.Draw(towerVec);
		/*glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glTranslatef(0.5f, 0.5f, 0.0f);
		glRotatef(tower.rotation, 0.0f, 0.0f, 1.0f);
		glTranslatef(-0.5f, -0.5f, 0.0f);
		glMatrixMode(GL_MODELVIEW);*/

		//Tower tower3(greenTower, Vector2().zeroVector());

		Clock::time_point t1 = Clock::now();

		/*if (yChange <=0.54f)
		{
			yChange += 0.0005f;
			std::cout << "ychange: " << yChange << std::endl;
			enemy.drawEnemy(-1.0f + xChange, 0.98f - yChange);
			redraw();
		}*/

		store.Draw();

		if (enemy1.alive)
		{
			enemy1.drawEnemy();
			/*if (yChange < 0.535f)
			{
				yChange += enemy1.speed;
				enemy1.drawEnemy(enemy1.position.X + xChange, enemy1.position.Y - yChange, enemyTexture1);
				glMatrixMode(GL_TEXTURE);
				glLoadIdentity();
				glTranslatef(0.5f, 0.5f, 0.0f);
				glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
				glTranslatef(-0.5f, -0.5f, 0.0f);
				glMatrixMode(GL_MODELVIEW);
			}
			else if (yChange >= 0.535f && xChange >= 0.0f && xChange <= 1.075f)
			{
				yChange = 0.540f;
				xChange += enemy1.speed;
				enemy1.drawEnemy(enemy1.position.X + xChange, enemy1.position.Y - yChange, enemyTexture1);
				glMatrixMode(GL_TEXTURE);
				glLoadIdentity();
				glTranslatef(0.5f, 0.5f, 0.0f);
				glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
				glTranslatef(-0.5f, -0.5f, 0.0f);
				glMatrixMode(GL_MODELVIEW);
			}
			else if (yChange >= 0.540f && yChange <= 1.075f && xChange >= 1.075f)
			{
				yChange += enemy1.speed;
				enemy1.drawEnemy(enemy1.position.X + xChange, enemy1.position.Y - yChange, enemyTexture1);
				glMatrixMode(GL_TEXTURE);
				glLoadIdentity();
				glTranslatef(0.5f, 0.5f, 0.0f);
				glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
				glTranslatef(-0.5f, -0.5f, 0.0f);
				glMatrixMode(GL_MODELVIEW);
				//std::cout << "Current x and y changes: X: " << xChange << " Y: " << yChange << std::endl;
			}
			else if (yChange >= 1.075f && xChange <= 1.08f && xChange >= 0.5375f)
			{
				//xChange -= enemy.speed; 
				enemy1.drawEnemy(enemy1.position.X + xChange, enemy1.position.Y - yChange, enemyTexture1);
				//std::cout << "2 Current x and y changes: X: " << xChange << " Y: " << yChange << std::endl;
			}*/
			redraw();
		}

		//std::cout << enemy.y << " the y value" << std::endl;

		for (int xTile = 1; xTile < 12; xTile++)
		{
			//std::cout << "done 1" << std::endl;
			for (int yTile = 1; yTile < 10; yTile++)
			{	
				//std::cout << "done 2" << std::endl;
				if (levels.map[yTile - 1][xTile - 1] == 0) //if grass
				{
					//std::cout << map[yTile - 1][xTile - 1] << ", " << tileWidth * xTile << ", " << tileHeight * yTile << std::endl;
					glBindTexture(GL_TEXTURE_2D, grass);
					scene->draw(tileWidth * xTile, tileHeight * yTile);
					//offsetH++;
					//glDisable(GL_TEXTURE_2D);
				}
				else if (levels.map[yTile - 1][xTile - 1] == 1) //else if path
				{
					//std::cout << map[yTile - 1][xTile - 1] << ", " << map[yTile - 1][xTile - 1] << std::endl;
					//std::cout << map[yTile - 1][xTile - 1] << ", " << tileWidth * xTile << ", " << tileHeight * yTile << std::endl;
					glBindTexture(GL_TEXTURE_2D, path);
					scene->draw(tileWidth * xTile, tileHeight * yTile);
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

void App::idle()
{
	if (enemy1.currentHealth <= 0 && currentMenu == Play)
	{
		enemy1.alive = false;
	}
	
	if (currentMenu == Play)
	{
		enemy1.Updates();
		tower.Updates();

		/*if (tower.Target().center.X == NULL && nodes == 0)
		{
			nodes++;
			std::vector<Enemy> enemies;
			enemies.push_back(enemy1);
			tower.GetEnemy(enemies);
		}*/

		if (enemy1.currentHealth > 0)
		{
			float healthPercentage = (float)enemy1.currentHealth / (float)enemy1.startHealth;
			// tower.RotateToTarget(enemy1);
			//enemy1.currentHealth -= 5.0f;
			//std::cout << enemy1.currentHealth << " " << healthPercentage << std::endl;
		}
	}

}

void App::mouseDown(float x, float y){ //Left click button down
    // Update app state
    mx = x;
    my = y;

	if (currentMenu == Play && tower.InBounds(y) && !(tower.Contains(mx, my, towerVec)) && towerVec.size() > 0 && !(levels.CheckPlacement(mx, my, levels.AllPathPoints())))
	{
		std::cout << "Push 1" << std::endl;
		//towerVec.push_back(Tower(greenTower, Vector2(0.0f, 0.0f)));
		towerVec.push_back(Tower(greenTower, Vector2(mx, my)));
		player.Updates();
	}
	else if(currentMenu == Play && tower.InBounds(y) && towerVec.size() <= 0 && !(levels.CheckPlacement(mx, my, levels.AllPathPoints())))
	{
		std::cout << "Push 2" << std::endl;
		towerVec.push_back(Tower(greenTower, Vector2(mx, my)));
	}
	else if (currentMenu == Play && tower.InBounds(y) && tower.Contains(mx, my, towerVec) && towerVec.size() > 0)
	{
		tower.DeleteTower(mx, my, towerVec);
		std::cout << "OPTIONS POP UP" << std::endl;
	}
    
    // Redraw the scene
    redraw();
}

void App::mouseUp(float x, float y) //Left click button up
{
	mx = x;
	my = y;

	if (button.Contains(x, y, buttons) && currentMenu == Main)
	{
		currentMenu = Play;
		initializeLevel("Level1.txt");
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

	if (key == 32)
	{
		if (yChange < 0.535f)
		{
			yChange += .005f;
		}
		else if (yChange >= 0.535f && xChange >= 0.0f && xChange <= 1.075f)
		{
			xChange += .005f;
		}
		else if (yChange >= 0.535f && yChange <= 1.075f && xChange >= 1.075f)
		{
			yChange += .005f;
		}
		else if (yChange >= 1.075f && xChange >= 1.075f && xChange <= 1.0f)
		{
			xChange = 1.0f;
		}
		//1.085 1.080
		redraw();
		//std::cout << "doing " << xChange << ", " << yChange << std::endl;
		redraw();
	}
}
