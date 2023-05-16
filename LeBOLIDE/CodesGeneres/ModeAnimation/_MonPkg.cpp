/********************************************************************
	Rhapsody	: 9.0 
	Login		: lakhaly
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: _MonPkg
//!	Generated Date	: Tue, 18, Oct 2022  
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "_MonPkg.h"
//## auto_generated
#include "_SysVehicule.h"
//#[ ignore
#define evPush_SERIALIZE OM_NO_OP

#define evPush_UNSERIALIZE OM_NO_OP

#define evPush_CONSTRUCTOR evPush()

#define evPushM_SERIALIZE OM_NO_OP

#define evPushM_UNSERIALIZE OM_NO_OP

#define evPushM_CONSTRUCTOR evPushM()

#define tm500_SERIALIZE OM_NO_OP

#define tm500_UNSERIALIZE OM_NO_OP

#define tm500_CONSTRUCTOR tm500()
//#]

//## package _MonPkg


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

IMPLEMENT_META_PACKAGE(_MonPkg, _MonPkg)

static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}
#endif // _OMINSTRUMENT

//## event evPush()
evPush::evPush() {
    NOTIFY_EVENT_CONSTRUCTOR(evPush)
    setId(evPush__MonPkg_id);
}

bool evPush::isTypeOf(const short id) const {
    return (evPush__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evPush, _MonPkg, _MonPkg, evPush())

//## event evPushM()
evPushM::evPushM() {
    NOTIFY_EVENT_CONSTRUCTOR(evPushM)
    setId(evPushM__MonPkg_id);
}

bool evPushM::isTypeOf(const short id) const {
    return (evPushM__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evPushM, _MonPkg, _MonPkg, evPushM())

//## event tm500()
tm500::tm500() {
    NOTIFY_EVENT_CONSTRUCTOR(tm500)
    setId(tm500__MonPkg_id);
}

bool tm500::isTypeOf(const short id) const {
    return (tm500__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(tm500, _MonPkg, _MonPkg, tm500())

/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.cpp
*********************************************************************/
