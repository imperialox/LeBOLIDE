/*********************************************************************
	Rhapsody	: 9.0 
	Login		: lakhaly
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: Main
//!	Generated Date	: Wed, 12, Oct 2022  
	File Path	: CodesGeneres\ModeAnimation\Main.h
*********************************************************************/

#ifndef Main_H
#define Main_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "Windows.h"
//## auto_generated
#include "stdlib.h"
//## auto_generated
#include "stdio.h"
//## auto_generated
#include "string.h"
//## auto_generated
#include "stdint.h"
//## auto_generated
#include "tchar.h"
//## auto_generated
#include "IHM_Objets.h"
//## auto_generated
#include <oxf\omthread.h>
//## auto_generated
#include <oxf\omreactive.h>
//## auto_generated
#include <oxf\state.h>
//## auto_generated
#include <oxf\event.h>
//## classInstance objetSysVehicule
#include "_SysVehicule.h"
//## package IHM_Objets

//## class Main
class Main : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedMain;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Main(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    virtual ~Main();
    
    ////    Operations    ////
    
    //## operation getItsVehiculeMoteur() const
    _SysVehicule* getItsVehiculeMoteur() const;
    
    //## operation getObjetSysVehicule() const
    _SysVehicule* getObjetSysVehicule() const;
    
    //## operation startBehavior()
    virtual bool startBehavior();
    
    ////    Relations and components    ////

protected :

    _SysVehicule objetSysVehicule;		//## classInstance objetSysVehicule
    
    ////    Framework operations    ////

public :

    //## auto_generated
    virtual void destroy();
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedMain : virtual public AOMInstance {
    DECLARE_META(Main, OMAnimatedMain)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\Main.h
*********************************************************************/
