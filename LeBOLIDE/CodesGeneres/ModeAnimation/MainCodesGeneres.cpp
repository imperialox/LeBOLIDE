/********************************************************************
	Rhapsody	: 9.0 
	Login		: lakhaly
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: ModeAnimation
//!	Generated Date	: Wed, 12, Oct 2022  
	File Path	: CodesGeneres\ModeAnimation\MainCodesGeneres.cpp
*********************************************************************/

//## auto_generated
#include "MainCodesGeneres.h"
//## auto_generated
#include "Main.h"
int main(int argc, char* argv[]) {
    int status = 0;
    if(OXF::initialize(argc, argv, 6423))
        {
            Main * p_Main;
            p_Main = new Main;
            p_Main->startBehavior();
            //#[ configuration CodesGeneres::ModeAnimation 
            //#]
            OXF::start();
            delete p_Main;
            status = 0;
        }
    else
        {
            status = 1;
        }
    return status;
}

/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\MainCodesGeneres.cpp
*********************************************************************/
