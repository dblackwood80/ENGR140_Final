#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "RgbImage.h"
#include "TexRect.hpp"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
	void mouseUp(float x, float y);
    void mouseDrag(float x, float y);
	void MenuChoices();
    
    GLuint loadTexture(const char* filename);
    
    GLuint grass;
    GLuint path;
	GLuint enemy1;
    
    
    TexRect* painting;
    TexRect* background;
};

#endif
