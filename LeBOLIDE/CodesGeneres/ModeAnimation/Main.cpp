/********************************************************************
	Rhapsody	: 9.0 
	Login		: lakhaly
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: Main
//!	Generated Date	: Wed, 12, Oct 2022  
	File Path	: CodesGeneres\ModeAnimation\Main.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Main.h"
//#[ ignore
#define IHM_Objets_Main_Main_SERIALIZE OM_NO_OP

#define IHM_Objets_Main_getItsVehiculeMoteur_SERIALIZE OM_NO_OP

#define IHM_Objets_Main_getObjetSysVehicule_SERIALIZE OM_NO_OP

#define IHM_Objets_Main_startBehavior_SERIALIZE OM_NO_OP
//#]

//## package IHM_Objets

//## class Main
Main::Main(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Main, Main(), 0, IHM_Objets_Main_Main_SERIALIZE);
    setActiveContext(theActiveContext, false);
    {
        {
            objetSysVehicule.setShouldDelete(false);
        }
    }
}

Main::~Main() {
    NOTIFY_DESTRUCTOR(~Main, true);
}

_SysVehicule* Main::getItsVehiculeMoteur() const {
    NOTIFY_OPERATION(getItsVehiculeMoteur, getItsVehiculeMoteur() const, 0, IHM_Objets_Main_getItsVehiculeMoteur_SERIALIZE);
    //#[ operation getItsVehiculeMoteur() const
    return (_SysVehicule*) &objetSysVehicule;
    //#]
}

_SysVehicule* Main::getObjetSysVehicule() const {
    NOTIFY_OPERATION(getObjetSysVehicule, getObjetSysVehicule() const, 0, IHM_Objets_Main_getObjetSysVehicule_SERIALIZE);
    //#[ operation getObjetSysVehicule() const
    return (_SysVehicule*) &objetSysVehicule;
    //#]
}

bool Main::startBehavior() {
    NOTIFY_OPERATION(startBehavior, startBehavior(), 0, IHM_Objets_Main_startBehavior_SERIALIZE);
    //#[ operation startBehavior()
    bool done = true;
    done &= objetSysVehicule.startBehavior();
    done &= OMReactive::startBehavior();
    return done;
    //#]
}

void Main::destroy() {
    objetSysVehicule.destroy();
    OMReactive::destroy();
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedMain::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("objetSysVehicule", true, true);
    aomsRelations->ADD_ITEM(&myReal->objetSysVehicule);
}
//#]

IMPLEMENT_REACTIVE_META_SIMPLE_P(Main, IHM_Objets, IHM_Objets, false, OMAnimatedMain)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\Main.cpp
*********************************************************************/
