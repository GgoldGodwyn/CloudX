/* 
 * File:   calls.h
 * Author: Ogboye Godwin
 *
 * Created on March 5, 2018, 4:37 PM
 */


    const char  answer[] = "ATA";                   //sim800_verifyResponse(cmd,response);
    const char  hang[] =    "ATH";                  //sim800_verifyResponse(cmd,response);
    const char lnEndChar[] = "ATS3";                //sim800_verifyResponse(cmd,response);
    const char lnFormatChar[] = "ATS4";             //sim800_verifyResponse(cmd,response);
    const char lnEditChar[] = "ATS5";               //sim800_verifyResponse(cmd,response);
    const char redial[] = "ATDL";                   //sim800_verifyResponse(cmd,response);
    const char getDeviceId[] = "ATI";               //sim800_verifyResponse(cmd,response);
    const char  dataToCommandSwitch[] = "+++";      //sim800_verifyResponse(cmd,response);
    const char  commandToDataSwitch[] = "ATO";      //sim800_verifyResponse(cmd,response);
    const char pulseDial[] = "ATP";                 //sim800_verifyResponse(cmd,response);
    const char toneDialing[] = "ATT" ;              //sim800_verifyResponse(cmd,response);
    const char userReset[] = "ATZ" ;                //sim800_verifyResponse(cmd,response);
    const char factoryReset[] = "AT&F" ;            //sim800_verifyResponse(cmd,response);
    const char getActiveCfg[] = "AT&V" ;            //sim800_verifyResponse(cmd,response);
    const char saveActiveCfg[] = "AT&W" ;           //sim800_verifyResponse(cmd,response);
    const char getGsmSupport[] = "AT+GCAP" ;        //sim800_verifyResponse(cmd,response);
    const char endCallOnly[] = "AT+HVOIC" ;         //sim800_verifyResponse(cmd,response);
    const char  dial[] = "ATD";                     //call(char * );
    const char  spkLoudness[] = "ATL";              //sim800_command(char * ,cmd);
    const char ResultMode[] = "ATQ";                //sim800_command(char * ,cmd);
    const char monSpeakerMode[] = "ATM" ;           //sim800_command(char * ,cmd);
    const char setResponseFormat[] = "ATV" ;        //sim800_command(char * ,cmd);
    const char setCallMonitor[] = "ATX" ;           //sim800_command(char * ,cmd);
    const char setDcdMode[] = "AT&C" ;              //sim800_command(char * ,cmd);
    const char setDtrMode[] = "AT&D" ;              //sim800_command(char * ,cmd);
    const char getMakerID[] = "AT+GMI" ;            //sim800_command(char * ,cmd);
    const char getDeviceModelID[] = "AT+GMM " ;     //sim800_command(char * ,cmd);
    const char getSoftwareID[] = "AT+GMR" ;         //sim800_command(char * ,cmd);
    const char getGOI[] = "AT+GOI" ;                //sim800_command(char * ,cmd);
    const char getIMEI[] = "AT+GSN" ;               //sim800_command(char * ,cmd);
    const char autoAnswerAfter[] = "ATS0" ;         //sim800_commands(char *,cmd,  char * );
    const char blindDialPause[] = "ATS6" ;          //sim800_commands(char *,cmd,  char * );
    const char connWaitTime[] = "ATS7" ;            //sim800_commands(char *,cmd,  char * );
    const char commaWaitTime[] = "ATS8" ;           //sim800_commands(char *,cmd,  char * );
    const char carrierLostDelay[] = "ATS10" ;       //sim800_commands(char *,cmd,  char * );
    const char serialFraming[] = "AT+ICF" ;         //sim800_commands(char *,cmd,  char * );
    const char serialFlowCtrl[] = "AT+IFC" ;        //sim800_commands(char *,cmd,  char * );
    const char serialBauds[] = "AT+IPR" ;           //sim800_commands(char *,cmd,  char * );
    





int calls_verifyResponse(char *cmd , char expd[]){
    char ex1,i=0;
    char inMsg[5];
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

call(char numbr[]){
    serialWriteText(dial);
    serialWriteText(numbr);
    serialWrite(';');

}

    