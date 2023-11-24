#include "CharScreen.h"

void CharScreen::handleInput() {
    
    mainChar.handleInput();
}

void CharScreen::update() {
    
}
void CharScreen::draw() {
    DrawText("Test character!", 10, 10, 20, RED);

    // for testing
    static int cnt = 0, curr = 0;
    if (cnt++ > 5) {
        cnt = 0;
        curr = (curr + 1) % 8;
    }
     Rectangle buttonRect {50, 50, 200, 100};
    if(GuiButton(buttonRect, "Back!")) {
        screenManager->backScreen();
    }
    mainChar.draw();
    
    //DrawRectangle(Rectangle(200,200,100,100), RED);

    
}
void CharScreen::load()
{
    BaseScreen::load();
    if (!this->hasInit)
    {
        this->init();
        this->hasInit=true;
    }
}
void CharScreen::unload()
{
    BaseScreen::unload();
}
void CharScreen::init()
{
    cout<<"INIT CHAR SCREEN CALLED"<<endl;
    
}
CharScreen::~CharScreen()
{

}

