/*
 * File:   sim800.c
 * Author: Ogboye Godwin
 *
 * Created on March 5, 2018, 11:45 AM
 */
#include <string.h>
// GENERAL

    const char lastCommand = 'A';               //void          ();
    const char verify[] = "AT";                 //void          ();
    const char  echoOff[] = "ATE0";             //void          ();
    const char  echoOn[] = "ATE1";              //void          ();
    const char  powerOff[] = "AT+CPOWD";        //void          ();
    // below only has test( =?) and read/execute(empty)
    //command        read, test
    const char reqMakerID[] = "AT+CGMI" ;       //sim800_command(char * ,cmd);
    const char reqDeviceModelID[] = "AT+CGMM" ; //sim800_command(char * ,cmd);
    const char reqSoftwareID[] = "AT+CGMR" ;    //sim800_command(char * ,cmd);
    const char reqIMEI[] = "AT+CGSN" ;          //sim800_command(char * ,cmd);
    const char reqIMSI[] = "AT+CIMI" ;          //sim800_command(char * ,cmd);
    const char activity[] = "AT+CPAS" ;         //sim800_command(char * ,cmd);
    const char signalQuality[] = "AT+CSQ" ;     //sim800_command(char * ,cmd);
    const char getSelfAddr[] = "AT+CNUM" ;      //sim800_command(char *,cmd);
    const char listAllOperators[] = "AT+COPN" ; //sim800_command(char *,cmd);
    const char battery[] = "AT+CBC" ;           //sim800_command(char *,cmd);
    

    // below only has test(=?) , read/execute(?)  and write (=<parameter>)
    //command       read, test or write           value
    const char callMeter[] = "AT+CACM" ;        //sim800_commands(char *,cmd,  char * );
    const char callMeterMax[] = "AT+CAMM" ;     //sim800_commands(char *,cmd,  char * );
    const char chargeAdvice[] = "AT+CAOC" ;     //sim800_commands(char *,cmd,  char * );
    const char dataCallService[] = "AT+CBST" ;  //sim800_commands(char *,cmd,  char * );
    const char callForward[] = "AT+CCFC" ;      //sim800_commands(char *,cmd,  char * );
    const char callWait[] = "AT+CCWA" ;         //sim800_commands(char *,cmd,  char * );
    const char errorReport[] = "AT+CEER" ;      //sim800_commands(char *,cmd,  char * );
    const char charset[] = "AT+CSCS" ;          //sim800_commands(char *,cmd,  char * );
    const char addressType[] = "AT+CSTA" ;      //sim800_commands(char *,cmd,  char * );
    const char callHold[] = "AT+CHLD" ;         //sim800_commands(char *,cmd,  char * );
    const char activeCalls[] = "AT+CLCC" ;      //sim800_commands(char *,cmd,  char * );
    const char facilityLock[] = "AT+CLCK" ;     //sim800_commands(char *,cmd,  char * );
    const char showCallerID[] = "AT+CLIP" ;     //sim800_commands(char *,cmd,  char * );
    const char hideSelfID[] = "AT+CLIR" ;       //sim800_commands(char *,cmd,  char * );
    const char deviceError[] = "AT+CMEE" ;      //sim800_commands(char *,cmd,  char * );
    const char callerID[] = "AT+COLP" ;         //sim800_commands(char *,cmd,  char * );
    const char netOps[] = "AT+COPS" ;           //sim800_commands(char *,cmd,  char * );
    const char pbFind[] = "AT+CPBF" ;           //sim800_commands(char *,cmd,  char * );
    const char pbRead[] = "AT+CPBR" ;           //sim800_commands(char *,cmd,  char * );
    const char pbStorage[] = "AT+CPBS" ;        //sim800_commands(char *,cmd,  char * );
    const char pbWrite[] = "AT+CPBW" ;          //sim800_commands(char *,cmd,  char * );
    const char pinCode[] = "AT+CPIN" ;          //sim800_commands(char *,cmd,  char * );
    const char changePwd[] = "AT+CPWD" ;        //sim800_commands(char *,cmd,  char * );
    const char serviceReport[] = "AT+CR" ;      //sim800_commands(char *,cmd,  char * );
    const char ringCodeMode[] = "AT+CRC" ;      //sim800_commands(char *,cmd,  char * );
    const char netReg[] = "AT+CREG" ;           //sim800_commands(char *,cmd,  char * );
    const char radioLinkParams[] = "AT+CRLP" ;  //sim800_commands(char *,cmd,  char * );
    const char simRawAccess[] = "AT+CRSM" ;     //sim800_commands(char *,cmd,  char * );
    const char dtmfDuration[] = "AT+VTD" ;      //sim800_commands(char *,cmd,  char * );
    const char dtmfPlay[] = "AT+VTS" ;          //sim800_commands(char *,cmd,  char * );
    const char muxControl[] = "AT+CMUX" ;       //sim800_commands(char *,cmd,  char * );
    const char prefOperators[] = "AT+CPOL" ;    //sim800_commands(char *,cmd,  char * );
    const char deviceMode[] = "AT+CFUN" ;       //sim800_commands(char *,cmd,  char * );
    const char clock[] = "AT+CCLK" ;            //sim800_commands(char *,cmd,  char * );
    const char simStrAccess[] = "AT+CSIM" ;     //sim800_commands(char *,cmd,  char * );
    const char alertMode[] = "AT+CALM" ;        //sim800_commands(char *,cmd,  char * );
    const char alertSound[] = "AT+CALS" ;       //sim800_commands(char *,cmd,  char * );
    const char ringerVolume[] = "AT+CRSL" ;     //sim800_commands(char *,cmd,  char * );
    const char loudSpeakerVol[] = "AT+CLVL" ;   //sim800_commands(char *,cmd,  char * );
    const char mute[] = "AT+CMUT" ;             //sim800_commands(char *,cmd,  char * );
    const char pricePerUnit[] = "AT+CPUC" ;     //sim800_commands(char *,cmd,  char * );
    const char callMeterMaxEvent[] = "AT+CCWE" ;//sim800_commands(char *,cmd,  char * );
    const char usd[] = "AT+CUSD" ;              //sim800_commands(char *,cmd,  char * );
    const char ssn[] = "AT+CSSN" ;              //sim800_commands(char *,cmd,  char * );
    const char dtmfDetect[] = "AT+DDET" ;       //sim800_commands(char *,cmd,  char * );
////

const char ok[] = "OK";
const char error[] = "ERROR";
const char all[] = "ALL"; // for message deleting
const int write=2,yes=1,read=1, no = 0, test=0;

char ex1;
int i;



/* 
 * File:   sim800.h
 * Author: Ogboye Godwin
 *
 * Created on March 5, 2018, 11:05 AM
 
timerInit(){
    OPTION_REG = 0X87; //9.984ms
    TMR0 = 61;
    INTCON=0XA0;
}
timerRESET(){
    TMR0IF = 0;
    TMR0 = 61;
}
timeUp(int tmStart){

}*/

unsigned int compareStrings(register const char *iinMsg , register const char *iexpd){
	register signed char	r;

	while (!(r = (unsigned char)*iinMsg - (unsigned char)*iexpd) && *iinMsg) {
		iinMsg++;
		iexpd++;
	}
	return r;
}

enter(){
    serialWrite('\r');
    serialWrite('\n');
}

clearBuffer(){
    char waste;
    while (serialAvailable()){
        waste = serialRead();
    }
    CREN=0;//OERR=0;
    CREN=1;
}
wasteAgain(){
    ex1=0;
    while(ex1!=0X0A){
        while(!serialAvailable());
        ex1 = serialRead();
    }
}

catchIncoming(){
    wasteAgain();
     i = ex1 = 0;
    char inMsgg[8];
    while (!serialAvailable());//or while (PIR1bits.RCIF==0);
    ex1 = serialRead();
    do{
        inMsgg[i]=ex1; //
        while (!serialAvailable());// or while (PIR1bits.RCIF==0); //
        ex1 = serialRead();
        i++;
    }
    while(ex1!='\r'); //0x0d;
    return inMsgg;
    
}

               //command       yes=read no=test
sim800_command(char *valU , int cmd     ){
    if(cmd==read) //1 is read
        serialWriteText("valU");
    else{ //test
        serialWriteText("valU");
        serialWriteText("=?");
    }
    enter();
}
               
sim800_commands(char *valU ,int cmd,  char *valU2 ){
    if(cmd==test) {//test
        serialWriteText("valU");
        serialWriteText("=?");
    }
    else if(cmd==1){ // read
        serialWriteText("valU");
        serialWrite('?');
    }
    else if(cmd==write){//write
        serialWriteText("valU");
        serialWriteText('=');
        serialWriteText("valU2");
    }
    enter();
}


sim800_verifyResponse(char *cmd , char expd[]){
    i = ex1 = 0;
    char inMsg[4];
    clearBuffer();

serialWriteText(cmd);
enter();
    wasteAgain();
    while (!serialAvailable());//or while (PIR1bits.RCIF==0);
    ex1 = serialRead();
    do{
        inMsg[i]=ex1;
        while (!serialAvailable());// or while (PIR1bits.RCIF==0); //
        ex1 = serialRead();
        i++;
    }
    while(ex1!='\r');

    if(compareStrings(inMsg , expd)!=0) //STRING COMPARISM
                return 0;
    else
                return 1;
}

