/********************************************************************
	Rhapsody	: 9.0 
	Login		: lakhaly
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: _SysVehicule
//!	Generated Date	: Tue, 18, Oct 2022  
	File Path	: CodesGeneres\ModeAnimation\_SysVehicule.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## dependency _SysVehicule
#include "_SysVehicule.h"
//#[ ignore
#define _MonPkg__SysVehicule__SysVehicule_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_Operation_103_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_accelerer_SERIALIZE aomsmethod->addAttribute("accelPedal", x2String(accelPedal));

#define _MonPkg__SysVehicule_arreter_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_calcul_vitesse_distance_SERIALIZE aomsmethod->addAttribute("throttle", x2String(throttle));

#define _MonPkg__SysVehicule_demarrer_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_freiner_SERIALIZE aomsmethod->addAttribute("brakePedal", x2String(brakePedal));

#define _MonPkg__SysVehicule_init_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_regulation_SERIALIZE OM_NO_OP

#define OMAnim__MonPkg__SysVehicule_setAccelPedal_double_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_accelPedal)

#define OMAnim__MonPkg__SysVehicule_setAccelPedal_double_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setAlpha_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_alpha)

#define OMAnim__MonPkg__SysVehicule_setAlpha_int_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setBrakePedal_double_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_brakePedal)

#define OMAnim__MonPkg__SysVehicule_setBrakePedal_double_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setIgnition_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_ignition)

#define OMAnim__MonPkg__SysVehicule_setIgnition_bool_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setLimiteur_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_limiteur)

#define OMAnim__MonPkg__SysVehicule_setLimiteur_bool_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setRegulateur_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_regulateur)

#define OMAnim__MonPkg__SysVehicule_setRegulateur_bool_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setVitesseLimite_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_vitesseLimite)

#define OMAnim__MonPkg__SysVehicule_setVitesseLimite_int_SERIALIZE_RET_VAL
//#]

//## package _MonPkg

//## class _SysVehicule
double _SysVehicule::accelerer(double accelPedal) {
    NOTIFY_OPERATION(accelerer, accelerer(double), 1, _MonPkg__SysVehicule_accelerer_SERIALIZE);
    //#[ operation accelerer(double)
    if(throttle<(MAX_THROTTLE-(accelPedal/3)))
        		throttle+=accelPedal/3;	
        	else 
        		 throttle=MAX_THROTTLE;   
        		 
    return throttle;
    //#]
}

void _SysVehicule::arreter() {
    NOTIFY_OPERATION(arreter, arreter(), 0, _MonPkg__SysVehicule_arreter_SERIALIZE);
    //#[ operation arreter()
    //stop engine
    ignition=false;
    //#]
}

void _SysVehicule::demarrer() {
    NOTIFY_OPERATION(demarrer, demarrer(), 0, _MonPkg__SysVehicule_demarrer_SERIALIZE);
    //#[ operation demarrer()
    ignition=true;
    
    //#]
}

void _SysVehicule::calcul_vitesse_distance(double& throttle) {
    NOTIFY_OPERATION(calcul_vitesse_distance, calcul_vitesse_distance(double&), 1, _MonPkg__SysVehicule_calcul_vitesse_distance_SERIALIZE);
    //#[ operation calcul_vitesse_distance(double)
    
    fspeed=fspeed-1.5*sin(alpha*3.14/180)+((throttle-fspeed/airResistance-2*brakePedal))/5;
    
    if(fspeed>MAX_SPEED) fspeed=MAX_SPEED;
    if(fspeed<0) fspeed=0;
    
    fdist=fdist+(fspeed/36.0)/5.0;
    
    speed=(int)fspeed;
    
    distance=(int)fdist;
    
    if(throttle>0.0) throttle-=(0.5/10.0);  
    
    
    
    //#]
}

double _SysVehicule::freiner(double brakePedal) {
    NOTIFY_OPERATION(freiner, freiner(double), 1, _MonPkg__SysVehicule_freiner_SERIALIZE);
    //#[ operation freiner(double)
     //if(throttle>(2.0*brakePedal))
     if(throttle>0.0)  
      {
        	throttle -= (brakePedal/2);
      }
     else throttle = 0.0;       
      
     return throttle;
    //#]
}

void _SysVehicule::init() {
    NOTIFY_OPERATION(init, init(), 0, _MonPkg__SysVehicule_init_SERIALIZE);
    //#[ operation init()
    fdist=0.0;
    fspeed=0.0; 
    throttle=0.0;   
    speed=0;
    airResistance=MAX_SPEED/MAX_THROTTLE;
    brakePedal=0;   
    accelPedal=0;     
    distance=0;
    //#]
}

_SysVehicule::_SysVehicule(IOxfActive* theActiveContext) : Alarme(false), LED(false), MAX_BRAKE(10), MAX_SPEED(120), MAX_THROTTLE(10.0), MemoryAccel(0.0), Voyant(false), _simu(true), accelPedal(0.0), airResistance(0.0), alpha(0), brakePedal(0.0), distance(0), error(0.0), fdist(0.0), fspeed(0.0), ignition(false), limiteur(false), regulateur(false), speed(0), steady(0.0), throttle(0.0), vitesseConsigne(0), vitesseLimite(0) {
    NOTIFY_ACTIVE_CONSTRUCTOR(_SysVehicule, _SysVehicule(), 0, _MonPkg__SysVehicule__SysVehicule_SERIALIZE);
    setActiveContext(this, true);
    initStatechart();
}

_SysVehicule::~_SysVehicule() {
    NOTIFY_DESTRUCTOR(~_SysVehicule, true);
    cancelTimeouts();
}

int _SysVehicule::getMAX_BRAKE() {
    return MAX_BRAKE;
}

void _SysVehicule::setMAX_BRAKE(int p_MAX_BRAKE) {
    MAX_BRAKE = p_MAX_BRAKE;
}

int _SysVehicule::getMAX_SPEED() {
    return MAX_SPEED;
}

void _SysVehicule::setMAX_SPEED(int p_MAX_SPEED) {
    MAX_SPEED = p_MAX_SPEED;
}

double _SysVehicule::getMAX_THROTTLE() {
    return MAX_THROTTLE;
}

void _SysVehicule::setMAX_THROTTLE(double p_MAX_THROTTLE) {
    MAX_THROTTLE = p_MAX_THROTTLE;
}

bool _SysVehicule::get_simu() {
    return _simu;
}

void _SysVehicule::set_simu(bool p__simu) {
    _simu = p__simu;
}

double _SysVehicule::getAccelPedal() {
    return accelPedal;
}

void _SysVehicule::setAccelPedal(double p_accelPedal) {
    accelPedal = p_accelPedal;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getAirResistance() {
    return airResistance;
}

void _SysVehicule::setAirResistance(double p_airResistance) {
    airResistance = p_airResistance;
}

int _SysVehicule::getAlpha() {
    return alpha;
}

void _SysVehicule::setAlpha(int p_alpha) {
    alpha = p_alpha;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getBrakePedal() {
    return brakePedal;
}

void _SysVehicule::setBrakePedal(double p_brakePedal) {
    brakePedal = p_brakePedal;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getDistance() {
    return distance;
}

void _SysVehicule::setDistance(int p_distance) {
    distance = p_distance;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getError() {
    return error;
}

void _SysVehicule::setError(double p_error) {
    error = p_error;
}

double _SysVehicule::getFdist() {
    return fdist;
}

void _SysVehicule::setFdist(double p_fdist) {
    fdist = p_fdist;
}

double _SysVehicule::getFspeed() {
    return fspeed;
}

void _SysVehicule::setFspeed(double p_fspeed) {
    fspeed = p_fspeed;
}

bool _SysVehicule::getIgnition() {
    return ignition;
}

int _SysVehicule::getSpeed() {
    return speed;
}

double _SysVehicule::getSteady() {
    return steady;
}

void _SysVehicule::setSteady(double p_steady) {
    steady = p_steady;
}

double _SysVehicule::getThrottle() {
    return throttle;
}

int _SysVehicule::getVitesseConsigne() {
    return vitesseConsigne;
}

void _SysVehicule::setVitesseConsigne(int p_vitesseConsigne) {
    vitesseConsigne = p_vitesseConsigne;
}

bool _SysVehicule::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    if(done)
        {
            startDispatching();
        }
    return done;
}

void _SysVehicule::setIgnition(bool p_ignition) {
    ignition = p_ignition;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::setSpeed(int p_speed) {
    speed = p_speed;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::setThrottle(double p_throttle) {
    throttle = p_throttle;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_9_subState = OMNonState;
    state_9_active = OMNonState;
    state_9_timeout = NULL;
    Allumage_subState = OMNonState;
    Allumage_timeout = NULL;
    state_49_subState = OMNonState;
    state_49_active = OMNonState;
    state_49_timeout = NULL;
    state_32_subState = OMNonState;
    state_32_active = OMNonState;
    state_32_timeout = NULL;
    state_2_subState = OMNonState;
    state_2_active = OMNonState;
    state_13_subState = OMNonState;
    state_13_timeout = NULL;
    state_1_subState = OMNonState;
    state_1_active = OMNonState;
    state_1_timeout = NULL;
}

void _SysVehicule::cancelTimeouts() {
    cancel(state_9_timeout);
    cancel(Allumage_timeout);
    cancel(state_49_timeout);
    cancel(state_32_timeout);
    cancel(state_13_timeout);
    cancel(state_1_timeout);
}

bool _SysVehicule::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_9_timeout == arg)
        {
            state_9_timeout = NULL;
            res = true;
        }
    if(Allumage_timeout == arg)
        {
            Allumage_timeout = NULL;
            res = true;
        }
    if(state_49_timeout == arg)
        {
            state_49_timeout = NULL;
            res = true;
        }
    if(state_32_timeout == arg)
        {
            state_32_timeout = NULL;
            res = true;
        }
    if(state_13_timeout == arg)
        {
            state_13_timeout = NULL;
            res = true;
        }
    if(state_1_timeout == arg)
        {
            state_1_timeout = NULL;
            res = true;
        }
    return res;
}

void _SysVehicule::regulation() {
    NOTIFY_OPERATION(regulation, regulation(), 0, _MonPkg__SysVehicule_regulation_SERIALIZE);
    //#[ operation regulation()
    if(vitesseConsigne<0){
       vitesseConsigne=0;
    }
    error  = (double) (5*(vitesseConsigne - speed) / 6.0);
    steady = (double) (vitesseConsigne / 12.0);
    throttle = steady+error;
    
    //#]
}

bool _SysVehicule::getRegulateur() {
    return regulateur;
}

void _SysVehicule::setRegulateur(bool p_regulateur) {
    regulateur = p_regulateur;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::Operation_103() {
    NOTIFY_OPERATION(Operation_103, Operation_103(), 0, _MonPkg__SysVehicule_Operation_103_SERIALIZE);
    //#[ operation Operation_103()
    //#]
}

bool _SysVehicule::getAlarme() {
    return Alarme;
}

void _SysVehicule::setAlarme(bool p_Alarme) {
    Alarme = p_Alarme;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getLED() {
    return LED;
}

void _SysVehicule::setLED(bool p_LED) {
    LED = p_LED;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getMemoryAccel() {
    return MemoryAccel;
}

void _SysVehicule::setMemoryAccel(double p_MemoryAccel) {
    MemoryAccel = p_MemoryAccel;
}

bool _SysVehicule::getVoyant() {
    return Voyant;
}

void _SysVehicule::setVoyant(bool p_Voyant) {
    Voyant = p_Voyant;
}

int _SysVehicule::getAugmentation_int_0() {
    return augmentation_int_0;
}

void _SysVehicule::setAugmentation_int_0(int p_augmentation_int_0) {
    augmentation_int_0 = p_augmentation_int_0;
}

int _SysVehicule::getDiminution_int_0() {
    return diminution_int_0;
}

void _SysVehicule::setDiminution_int_0(int p_diminution_int_0) {
    diminution_int_0 = p_diminution_int_0;
}

bool _SysVehicule::getLimiteur() {
    return limiteur;
}

void _SysVehicule::setLimiteur(bool p_limiteur) {
    limiteur = p_limiteur;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getVitesseLimite() {
    return vitesseLimite;
}

void _SysVehicule::setVitesseLimite(int p_vitesseLimite) {
    vitesseLimite = p_vitesseLimite;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("1");
        //#[ transition 1 
        init();
        //#]
        NOTIFY_STATE_ENTERED("ROOT.state_4");
        pushNullTransition();
        rootState_subState = state_4;
        rootState_active = state_4;
        NOTIFY_TRANSITION_TERMINATED("1");
    }
}

IOxfReactive::TakeEventStatus _SysVehicule::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State state_0
        case state_0:
        {
            res = state_0_processEvent();
        }
        break;
        // State state_4
        case state_4:
        {
            res = state_4_handleEvent();
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_4TakeNull() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    NOTIFY_TRANSITION_STARTED("0");
    popNullTransition();
    NOTIFY_STATE_EXITED("ROOT.state_4");
    state_0_entDef();
    NOTIFY_TRANSITION_TERMINATED("0");
    res = eventConsumed;
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_4_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            res = state_4TakeNull();
        }
    
    return res;
}

void _SysVehicule::state_0_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0");
    rootState_subState = state_0;
    rootState_active = state_0;
    state_1_entDef();
    state_2_entDef();
    state_9_entDef();
    state_32_entDef();
    state_49_entDef();
}

void _SysVehicule::state_0_exit() {
    switch (state_1_subState) {
        // State state_23
        case state_23:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_23");
        }
        break;
        // State state_24
        case state_24:
        {
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_24");
        }
        break;
        // State state_31
        case state_31:
        {
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_31");
        }
        break;
        default:
            break;
    }
    state_1_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.state_0.state_1");
    state_2_exit();
    switch (state_9_subState) {
        // State Allumage
        case Allumage:
        {
            popNullTransition();
            switch (Allumage_subState) {
                // State Acceleration
                case Acceleration:
                {
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Acceleration");
                }
                break;
                // State Freinage
                case Freinage:
                {
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Freinage");
                }
                break;
                default:
                    break;
            }
            Allumage_subState = OMNonState;
            NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage");
        }
        break;
        // State contact
        case contact:
        {
            popNullTransition();
            cancel(state_9_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_9.contact");
        }
        break;
        default:
            break;
    }
    state_9_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.state_0.state_9");
    state_32_exit();
    state_49_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_0");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_0_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_1
    if(state_1_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_2
    if(state_2_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_9
    if(state_9_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_32
    if(state_32_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_49
    if(state_49_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    
    return res;
}

void _SysVehicule::state_9_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9");
    NOTIFY_TRANSITION_STARTED("11");
    Allumage_entDef();
    NOTIFY_TRANSITION_TERMINATED("11");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_9_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_9_active) {
        // State Acceleration
        case Acceleration:
        {
            res = Acceleration_handleEvent();
        }
        break;
        // State Freinage
        case Freinage:
        {
            res = Freinage_handleEvent();
        }
        break;
        // State contact
        case contact:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_9_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("12");
                            popNullTransition();
                            cancel(state_9_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_9.contact");
                            //#[ transition 12 
                            freiner(brakePedal);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.contact");
                            pushNullTransition();
                            state_9_subState = contact;
                            state_9_active = contact;
                            state_9_timeout = scheduleTimeout(200, "ROOT.state_0.state_9.contact");
                            NOTIFY_TRANSITION_TERMINATED("12");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 10 
                    if(ignition)
                        {
                            NOTIFY_TRANSITION_STARTED("10");
                            popNullTransition();
                            cancel(state_9_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_9.contact");
                            Allumage_entDef();
                            NOTIFY_TRANSITION_TERMINATED("10");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void _SysVehicule::Allumage_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.Allumage");
    pushNullTransition();
    state_9_subState = Allumage;
    NOTIFY_TRANSITION_STARTED("8");
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.Allumage.Acceleration");
    pushNullTransition();
    Allumage_subState = Acceleration;
    state_9_active = Acceleration;
    Allumage_timeout = scheduleTimeout(300, "ROOT.state_0.state_9.Allumage.Acceleration");
    NOTIFY_TRANSITION_TERMINATED("8");
}

IOxfReactive::TakeEventStatus _SysVehicule::Allumage_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 9 
            if(!ignition)
                {
                    NOTIFY_TRANSITION_STARTED("9");
                    popNullTransition();
                    switch (Allumage_subState) {
                        // State Acceleration
                        case Acceleration:
                        {
                            popNullTransition();
                            cancel(Allumage_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Acceleration");
                        }
                        break;
                        // State Freinage
                        case Freinage:
                        {
                            popNullTransition();
                            cancel(Allumage_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Freinage");
                        }
                        break;
                        default:
                            break;
                    }
                    Allumage_subState = OMNonState;
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.contact");
                    pushNullTransition();
                    state_9_subState = contact;
                    state_9_active = contact;
                    state_9_timeout = scheduleTimeout(200, "ROOT.state_0.state_9.contact");
                    NOTIFY_TRANSITION_TERMINATED("9");
                    res = eventConsumed;
                }
        }
    
    
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::Freinage_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == Allumage_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Freinage");
                    //#[ transition 4 
                    freiner(brakePedal);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.Allumage.Freinage");
                    pushNullTransition();
                    Allumage_subState = Freinage;
                    state_9_active = Freinage;
                    Allumage_timeout = scheduleTimeout(200, "ROOT.state_0.state_9.Allumage.Freinage");
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 5 
            if(brakePedal==0)
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Freinage");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.Allumage.Acceleration");
                    pushNullTransition();
                    Allumage_subState = Acceleration;
                    state_9_active = Acceleration;
                    Allumage_timeout = scheduleTimeout(300, "ROOT.state_0.state_9.Allumage.Acceleration");
                    NOTIFY_TRANSITION_TERMINATED("5");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = Allumage_handleEvent();
        }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::Acceleration_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == Allumage_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Acceleration");
                    //#[ transition 3 
                    accelerer(accelPedal);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.Allumage.Acceleration");
                    pushNullTransition();
                    Allumage_subState = Acceleration;
                    state_9_active = Acceleration;
                    Allumage_timeout = scheduleTimeout(300, "ROOT.state_0.state_9.Allumage.Acceleration");
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 6 
            if(brakePedal!=0)
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_9.Allumage.Acceleration");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_9.Allumage.Freinage");
                    pushNullTransition();
                    Allumage_subState = Freinage;
                    state_9_active = Freinage;
                    Allumage_timeout = scheduleTimeout(200, "ROOT.state_0.state_9.Allumage.Freinage");
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = Allumage_handleEvent();
        }
    return res;
}

void _SysVehicule::state_49_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_49");
    NOTIFY_TRANSITION_STARTED("30");
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_50");
    pushNullTransition();
    state_49_subState = state_50;
    state_49_active = state_50;
    NOTIFY_TRANSITION_TERMINATED("30");
}

void _SysVehicule::state_49_exit() {
    switch (state_49_subState) {
        // State state_50
        case state_50:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_50");
        }
        break;
        // State state_51
        case state_51:
        {
            NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_51");
        }
        break;
        // State state_52
        case state_52:
        {
            cancel(state_49_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_52");
        }
        break;
        // State state_60
        case state_60:
        {
            cancel(state_49_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_60");
        }
        break;
        default:
            break;
    }
    state_49_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.state_49");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_49_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_49_active) {
        // State state_50
        case state_50:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 31 
                    if(IS_IN(Limitation))
                        {
                            NOTIFY_TRANSITION_STARTED("31");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_50");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_51");
                            state_49_subState = state_51;
                            state_49_active = state_51;
                            NOTIFY_TRANSITION_TERMINATED("31");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_51
        case state_51:
        {
            if(IS_EVENT_TYPE_OF(evPushM__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("27");
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_51");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_60");
                    state_49_subState = state_60;
                    state_49_active = state_60;
                    state_49_timeout = scheduleTimeout(500, "ROOT.state_0.state_49.state_60");
                    NOTIFY_TRANSITION_TERMINATED("27");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evPush__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("24");
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_51");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_52");
                    state_49_subState = state_52;
                    state_49_active = state_52;
                    state_49_timeout = scheduleTimeout(500, "ROOT.state_0.state_49.state_52");
                    NOTIFY_TRANSITION_TERMINATED("24");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State state_52
        case state_52:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_49_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("25");
                            cancel(state_49_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_52");
                            //#[ transition 25 
                            vitesseConsigne+=1;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_51");
                            state_49_subState = state_51;
                            state_49_active = state_51;
                            NOTIFY_TRANSITION_TERMINATED("25");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evPush__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("26");
                    cancel(state_49_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_52");
                    //#[ transition 26 
                    vitesseConsigne+=10;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_51");
                    state_49_subState = state_51;
                    state_49_active = state_51;
                    NOTIFY_TRANSITION_TERMINATED("26");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State state_60
        case state_60:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_49_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("29");
                            cancel(state_49_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_60");
                            //#[ transition 29 
                            vitesseConsigne-=10;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_51");
                            state_49_subState = state_51;
                            state_49_active = state_51;
                            NOTIFY_TRANSITION_TERMINATED("29");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evPushM__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("28");
                    cancel(state_49_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_49.state_60");
                    //#[ transition 28 
                    vitesseConsigne-=10;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_49.state_51");
                    state_49_subState = state_51;
                    state_49_active = state_51;
                    NOTIFY_TRANSITION_TERMINATED("28");
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void _SysVehicule::state_32_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_32");
    NOTIFY_TRANSITION_STARTED("37");
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.state_47");
    pushNullTransition();
    state_32_subState = state_47;
    state_32_active = state_47;
    NOTIFY_TRANSITION_TERMINATED("37");
}

void _SysVehicule::state_32_exit() {
    switch (state_32_subState) {
        // State state_47
        case state_47:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.state_47");
        }
        break;
        // State Limitation
        case Limitation:
        {
            popNullTransition();
            cancel(state_32_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.Limitation");
        }
        break;
        // State state_63
        case state_63:
        {
            cancel(state_32_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.state_63");
        }
        break;
        // State state_62
        case state_62:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.state_62");
        }
        break;
        default:
            break;
    }
    state_32_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.state_32");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_32_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_32_active) {
        // State state_47
        case state_47:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 21 
                    if(IS_IN(state_23)&&limiteur&&speed==vitesseLimite)
                        {
                            NOTIFY_TRANSITION_STARTED("21");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.state_47");
                            //#[ transition 21 
                            vitesseConsigne=vitesseLimite;
                            MemoryAccel=accelPedal;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.Limitation");
                            pushNullTransition();
                            state_32_subState = Limitation;
                            state_32_active = Limitation;
                            state_32_timeout = scheduleTimeout(50, "ROOT.state_0.state_32.Limitation");
                            NOTIFY_TRANSITION_TERMINATED("21");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 33 
                            if(IS_IN(state_23)&&limiteur&&speed>vitesseLimite)
                                {
                                    NOTIFY_TRANSITION_STARTED("33");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_0.state_32.state_47");
                                    //#[ transition 33 
                                    vitesseConsigne=vitesseLimite;
                                    LED=true;
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.state_62");
                                    pushNullTransition();
                                    state_32_subState = state_62;
                                    state_32_active = state_62;
                                    NOTIFY_TRANSITION_TERMINATED("33");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        // State Limitation
        case Limitation:
        {
            res = Limitation_handleEvent();
        }
        break;
        // State state_63
        case state_63:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_32_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("35");
                            cancel(state_32_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.state_63");
                            //#[ transition 35 
                            Alarme=false;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.state_47");
                            pushNullTransition();
                            state_32_subState = state_47;
                            state_32_active = state_47;
                            NOTIFY_TRANSITION_TERMINATED("35");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_62
        case state_62:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 34 
                    if(speed<=vitesseConsigne)
                        {
                            NOTIFY_TRANSITION_STARTED("34");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.state_62");
                            //#[ transition 34 
                            LED=false;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.Limitation");
                            pushNullTransition();
                            state_32_subState = Limitation;
                            state_32_active = Limitation;
                            state_32_timeout = scheduleTimeout(50, "ROOT.state_0.state_32.Limitation");
                            NOTIFY_TRANSITION_TERMINATED("34");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::Limitation_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_32_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("23");
                    popNullTransition();
                    cancel(state_32_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_32.Limitation");
                    //#[ transition 23 
                    regulation();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.Limitation");
                    pushNullTransition();
                    state_32_subState = Limitation;
                    state_32_active = Limitation;
                    state_32_timeout = scheduleTimeout(50, "ROOT.state_0.state_32.Limitation");
                    NOTIFY_TRANSITION_TERMINATED("23");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 22 
            if(!limiteur||accelPedal<0.50||brakePedal!=0||(accelPedal-MemoryAccel)>3)
                {
                    NOTIFY_TRANSITION_STARTED("22");
                    popNullTransition();
                    cancel(state_32_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_32.Limitation");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.state_47");
                    pushNullTransition();
                    state_32_subState = state_47;
                    state_32_active = state_47;
                    NOTIFY_TRANSITION_TERMINATED("22");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 32 
                    if(alpha>10||alpha<-10)
                        {
                            NOTIFY_TRANSITION_STARTED("32");
                            popNullTransition();
                            cancel(state_32_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_32.Limitation");
                            //#[ transition 32 
                            limiteur=false;
                            Alarme=true;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_32.state_63");
                            state_32_subState = state_63;
                            state_32_active = state_63;
                            state_32_timeout = scheduleTimeout(500, "ROOT.state_0.state_32.state_63");
                            NOTIFY_TRANSITION_TERMINATED("32");
                            res = eventConsumed;
                        }
                }
        }
    
    
    return res;
}

void _SysVehicule::state_2_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_2");
    NOTIFY_TRANSITION_STARTED("7");
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_2.state_13");
    state_2_subState = state_13;
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_2.state_13.state_13");
    state_13_subState = state_13_state_13;
    state_2_active = state_13_state_13;
    state_13_timeout = scheduleTimeout(50, "ROOT.state_0.state_2.state_13.state_13");
    NOTIFY_TRANSITION_TERMINATED("7");
}

void _SysVehicule::state_2_exit() {
    // State state_13
    if(state_2_subState == state_13)
        {
            state_13_exit();
        }
    state_2_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.state_2");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_2_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_13
    if(state_2_active == state_13_state_13)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_13_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("2");
                            cancel(state_13_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_2.state_13.state_13");
                            //#[ transition 2 
                            calcul_vitesse_distance(throttle);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_2.state_13.state_13");
                            state_13_subState = state_13_state_13;
                            state_2_active = state_13_state_13;
                            state_13_timeout = scheduleTimeout(50, "ROOT.state_0.state_2.state_13.state_13");
                            NOTIFY_TRANSITION_TERMINATED("2");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void _SysVehicule::state_13_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_2.state_13");
    state_2_subState = state_13;
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_2.state_13.state_13");
    state_13_subState = state_13_state_13;
    state_2_active = state_13_state_13;
    state_13_timeout = scheduleTimeout(50, "ROOT.state_0.state_2.state_13.state_13");
}

void _SysVehicule::state_13_exit() {
    // State state_13
    if(state_13_subState == state_13_state_13)
        {
            cancel(state_13_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_2.state_13.state_13");
        }
    state_13_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.state_2.state_13");
}

void _SysVehicule::state_1_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_1");
    NOTIFY_TRANSITION_STARTED("36");
    NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_23");
    pushNullTransition();
    state_1_subState = state_23;
    state_1_active = state_23;
    NOTIFY_TRANSITION_TERMINATED("36");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_1_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_1_active) {
        // State state_23
        case state_23:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 13 
                    if(IS_IN(state_47)&&regulateur && speed>50)
                        {
                            NOTIFY_TRANSITION_STARTED("13");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_23");
                            //#[ transition 13 
                            vitesseConsigne=speed;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_24");
                            pushNullTransition();
                            state_1_subState = state_24;
                            state_1_active = state_24;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_0.state_1.state_24");
                            NOTIFY_TRANSITION_TERMINATED("13");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_24
        case state_24:
        {
            res = state_24_handleEvent();
        }
        break;
        // State state_31
        case state_31:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_1_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("20");
                            popNullTransition();
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_31");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_31");
                            pushNullTransition();
                            state_1_subState = state_31;
                            state_1_active = state_31;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_0.state_1.state_31");
                            NOTIFY_TRANSITION_TERMINATED("20");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 19 
                    if(accelPedal==0)
                        {
                            NOTIFY_TRANSITION_STARTED("19");
                            popNullTransition();
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_31");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_24");
                            pushNullTransition();
                            state_1_subState = state_24;
                            state_1_active = state_24;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_0.state_1.state_24");
                            NOTIFY_TRANSITION_TERMINATED("19");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_24_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evPushM__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("17");
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_24");
            //#[ transition 17 
            vitesseConsigne-=1;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_24");
            pushNullTransition();
            state_1_subState = state_24;
            state_1_active = state_24;
            state_1_timeout = scheduleTimeout(50, "ROOT.state_0.state_1.state_24");
            NOTIFY_TRANSITION_TERMINATED("17");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_1_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("15");
                    popNullTransition();
                    cancel(state_1_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_24");
                    //#[ transition 15 
                    regulation();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_24");
                    pushNullTransition();
                    state_1_subState = state_24;
                    state_1_active = state_24;
                    state_1_timeout = scheduleTimeout(50, "ROOT.state_0.state_1.state_24");
                    NOTIFY_TRANSITION_TERMINATED("15");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 14 
            if(!regulateur||brakePedal!=0||speed<50)
                {
                    NOTIFY_TRANSITION_STARTED("14");
                    popNullTransition();
                    cancel(state_1_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_24");
                    //#[ transition 14 
                    regulateur=false;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_23");
                    pushNullTransition();
                    state_1_subState = state_23;
                    state_1_active = state_23;
                    NOTIFY_TRANSITION_TERMINATED("14");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 18 
                    if(accelPedal!=0)
                        {
                            NOTIFY_TRANSITION_STARTED("18");
                            popNullTransition();
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_24");
                            //#[ transition 18 
                            accelerer(accelPedal);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_31");
                            pushNullTransition();
                            state_1_subState = state_31;
                            state_1_active = state_31;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_0.state_1.state_31");
                            NOTIFY_TRANSITION_TERMINATED("18");
                            res = eventConsumed;
                        }
                }
        }
    else if(IS_EVENT_TYPE_OF(evPush__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("16");
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.state_1.state_24");
            //#[ transition 16 
            vitesseConsigne+=1;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_0.state_1.state_24");
            pushNullTransition();
            state_1_subState = state_24;
            state_1_active = state_24;
            state_1_timeout = scheduleTimeout(50, "ROOT.state_0.state_1.state_24");
            NOTIFY_TRANSITION_TERMINATED("16");
            res = eventConsumed;
        }
    
    
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimated_SysVehicule::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("fspeed", x2String(myReal->fspeed));
    aomsAttributes->addAttribute("fdist", x2String(myReal->fdist));
    aomsAttributes->addAttribute("airResistance", x2String(myReal->airResistance));
    aomsAttributes->addAttribute("speed", x2String(myReal->speed));
    aomsAttributes->addAttribute("brakePedal", x2String(myReal->brakePedal));
    aomsAttributes->addAttribute("ignition", x2String(myReal->ignition));
    aomsAttributes->addAttribute("MAX_SPEED", x2String(myReal->MAX_SPEED));
    aomsAttributes->addAttribute("MAX_BRAKE", x2String(myReal->MAX_BRAKE));
    aomsAttributes->addAttribute("MAX_THROTTLE", x2String(myReal->MAX_THROTTLE));
    aomsAttributes->addAttribute("distance", x2String(myReal->distance));
    aomsAttributes->addAttribute("throttle", x2String(myReal->throttle));
    aomsAttributes->addAttribute("alpha", x2String(myReal->alpha));
    aomsAttributes->addAttribute("accelPedal", x2String(myReal->accelPedal));
    aomsAttributes->addAttribute("error", x2String(myReal->error));
    aomsAttributes->addAttribute("steady", x2String(myReal->steady));
    aomsAttributes->addAttribute("_simu", x2String(myReal->_simu));
    aomsAttributes->addAttribute("vitesseConsigne", x2String(myReal->vitesseConsigne));
    aomsAttributes->addAttribute("regulateur", x2String(myReal->regulateur));
    aomsAttributes->addAttribute("limiteur", x2String(myReal->limiteur));
    aomsAttributes->addAttribute("vitesseLimite", x2String(myReal->vitesseLimite));
    aomsAttributes->addAttribute("diminution_int_0", x2String(myReal->diminution_int_0));
    aomsAttributes->addAttribute("augmentation_int_0", x2String(myReal->augmentation_int_0));
    aomsAttributes->addAttribute("MemoryAccel", x2String(myReal->MemoryAccel));
    aomsAttributes->addAttribute("Alarme", x2String(myReal->Alarme));
    aomsAttributes->addAttribute("LED", x2String(myReal->LED));
    aomsAttributes->addAttribute("Voyant", x2String(myReal->Voyant));
}

void OMAnimated_SysVehicule::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case _SysVehicule::state_0:
        {
            state_0_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_4:
        {
            state_4_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_4_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_4");
}

void OMAnimated_SysVehicule::state_0_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0");
    state_1_serializeStates(aomsState);
    state_2_serializeStates(aomsState);
    state_9_serializeStates(aomsState);
    state_32_serializeStates(aomsState);
    state_49_serializeStates(aomsState);
}

void OMAnimated_SysVehicule::state_9_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_9");
    switch (myReal->state_9_subState) {
        case _SysVehicule::Allumage:
        {
            Allumage_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::contact:
        {
            contact_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::contact_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_9.contact");
}

void OMAnimated_SysVehicule::Allumage_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_9.Allumage");
    switch (myReal->Allumage_subState) {
        case _SysVehicule::Acceleration:
        {
            Acceleration_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::Freinage:
        {
            Freinage_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::Freinage_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_9.Allumage.Freinage");
}

void OMAnimated_SysVehicule::Acceleration_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_9.Allumage.Acceleration");
}

void OMAnimated_SysVehicule::state_49_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_49");
    switch (myReal->state_49_subState) {
        case _SysVehicule::state_50:
        {
            state_50_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_51:
        {
            state_51_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_52:
        {
            state_52_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_60:
        {
            state_60_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_60_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_49.state_60");
}

void OMAnimated_SysVehicule::state_52_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_49.state_52");
}

void OMAnimated_SysVehicule::state_51_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_49.state_51");
}

void OMAnimated_SysVehicule::state_50_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_49.state_50");
}

void OMAnimated_SysVehicule::state_32_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_32");
    switch (myReal->state_32_subState) {
        case _SysVehicule::state_47:
        {
            state_47_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::Limitation:
        {
            Limitation_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_63:
        {
            state_63_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_62:
        {
            state_62_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_63_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_32.state_63");
}

void OMAnimated_SysVehicule::state_62_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_32.state_62");
}

void OMAnimated_SysVehicule::state_47_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_32.state_47");
}

void OMAnimated_SysVehicule::Limitation_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_32.Limitation");
}

void OMAnimated_SysVehicule::state_2_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_2");
    if(myReal->state_2_subState == _SysVehicule::state_13)
        {
            state_13_serializeStates(aomsState);
        }
}

void OMAnimated_SysVehicule::state_13_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_2.state_13");
    if(myReal->state_13_subState == _SysVehicule::state_13_state_13)
        {
            state_13_state_13_serializeStates(aomsState);
        }
}

void OMAnimated_SysVehicule::state_13_state_13_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_2.state_13.state_13");
}

void OMAnimated_SysVehicule::state_1_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_1");
    switch (myReal->state_1_subState) {
        case _SysVehicule::state_23:
        {
            state_23_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_24:
        {
            state_24_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_31:
        {
            state_31_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_31_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_1.state_31");
}

void OMAnimated_SysVehicule::state_24_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_1.state_24");
}

void OMAnimated_SysVehicule::state_23_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.state_1.state_23");
}
//#]

IMPLEMENT_REACTIVE_META_P(_SysVehicule, _MonPkg, _MonPkg, false, OMAnimated_SysVehicule)

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setAccelPedal_double, "setAccelPedal", FALSE, "setAccelPedal(double)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setAccelPedal_double, _SysVehicule, setAccelPedal(p_accelPedal), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setAlpha_int, "setAlpha", FALSE, "setAlpha(int)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setAlpha_int, _SysVehicule, setAlpha(p_alpha), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setBrakePedal_double, "setBrakePedal", FALSE, "setBrakePedal(double)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setBrakePedal_double, _SysVehicule, setBrakePedal(p_brakePedal), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setIgnition_bool, "setIgnition", FALSE, "setIgnition(bool)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setIgnition_bool, _SysVehicule, setIgnition(p_ignition), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setLimiteur_bool, "setLimiteur", FALSE, "setLimiteur(bool)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setLimiteur_bool, _SysVehicule, setLimiteur(p_limiteur), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setRegulateur_bool, "setRegulateur", FALSE, "setRegulateur(bool)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setRegulateur_bool, _SysVehicule, setRegulateur(p_regulateur), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setVitesseLimite_int, "setVitesseLimite", FALSE, "setVitesseLimite(int)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setVitesseLimite_int, _SysVehicule, setVitesseLimite(p_vitesseLimite), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\_SysVehicule.cpp
*********************************************************************/
