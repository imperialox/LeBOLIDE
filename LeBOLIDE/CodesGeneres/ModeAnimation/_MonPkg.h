/*********************************************************************
	Rhapsody	: 9.0 
	Login		: lakhaly
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: _MonPkg
//!	Generated Date	: Tue, 18, Oct 2022  
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.h
*********************************************************************/

#ifndef _MonPkg_H
#define _MonPkg_H

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
#include <oxf\event.h>
//## auto_generated
class _SysVehicule;

//#[ ignore
#define evPush__MonPkg_id 13401

#define evPushM__MonPkg_id 13402

#define tm500__MonPkg_id 13403
//#]

//## package _MonPkg



//## event evPush()
class evPush : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevPush;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evPush();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevPush : virtual public AOMEvent {
    DECLARE_META_EVENT(evPush)
};
//#]
#endif // _OMINSTRUMENT

//## event evPushM()
class evPushM : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevPushM;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evPushM();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevPushM : virtual public AOMEvent {
    DECLARE_META_EVENT(evPushM)
};
//#]
#endif // _OMINSTRUMENT

//## event tm500()
class tm500 : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedtm500;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    tm500();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedtm500 : virtual public AOMEvent {
    DECLARE_META_EVENT(tm500)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.h
*********************************************************************/
