/* 
 * File:   sms.h
 * Author: Ogboye Godwin
 *
 * Created on March 5, 2018, 6:17 PM
 */


const char  deleteMassage[] = "AT+CMGD";        //   sim800_commands(char *,cmd,  char * );
const char  massageFormat[] = "AT+CMGF";        //   sim800_commands(char *,cmd,  char * );
const char  listSms[] = "AT+CMGL";              //   sim800_commands(char *,cmd,  char * ); from prefered storage
const char  ReadSMS[] = "AT+CMGR";              //   sim800_commands(char *,cmd,  char * );
const char sendMessage[] = "AT+CMGS";           //   sms_verifyResponse(char *cmd ,Val, char *,char*)
const char WriteSmsTomemeory[] = "AT+CMGW";     //   sms_verifyResponse(char *cmd ,Val, char *,char*)
const char smsSendFromStore[] = "AT+CMSS";      //   sim800_commands(char *,cmd,  char * );
const char  newSmsIndications[] = "AT+CNMI";    //   sim800_commands(char *,cmd,  char * );
const char  PreferedStorade[] = "AT+CPMS";      //   sim800_commands(char *,cmd,  char * );
const char RestoreSmsConfig[] = "AT+CRES";      //   sim800_commands(char *,cmd,  char * );
const char  saveSmsSettings[] = "AT+CSAS";      //   sim800_commands(char *,cmd,  char * );
const char  smsCenterAddress[] = "AT+CSCA";     //   sim800_commands(char *,cmd,  char * );
const char  smsCellCast[] = "AT+CSCB";          //   sim800_commands(char *,cmd,  char * );
const char  smsGetParams[] = "AT+CSDH";         //   sim800_commands(char *,cmd,  char * );
const char  smsSetParams[] = "AT+CSMP";         //   sim800_commands(char *,cmd,  char * );
const char  smsService[] = "AT+CSMS";           //   sim800_commands(char *,cmd,  char * );
const char textSendDone[] = "+CMGF=1"; //sending Successful for Text mode
const char PSUSendDone[] = "+CMGF=0"; //sending Successful for PSU mode

const char TxtMode = '1',PduMode ='0';




int sms_verifyResponse(char *cmd ,int QuestionVal, char valU[],  char expd[]){
    int rre;
    rre=strlen(valU);
    ex1,i=0;
    char inMsg[5];
    clearBuffer();
    if(QuestionVal==yes){
        serialWriteText(cmd);
        serialWriteText("=");
        if(strlen(valU)>1){
            serialWriteText("\"");
            serialWriteText(valU);
            serialWriteText("\"");
        }
        else
            serialWrite(valU);
    }
    else
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
        if(ex1==0x20)  //for message
            return 1;
    }
    while(ex1!=0x0D );//

    if(compareStrings(inMsg , expd)!=0) //STRING COMPARISM
                return 0;
    else
                return 1;
}


sendSms(char numbs[],char messTsend[]){
    int rsse;
    rsse=sms_verifyResponse(sendMessage,yes,numbs,'>');
    if(rsse==1){
        serialWriteText(messTsend);
        serialWrite(0x1A);
        return 1;
    }
    else
        return 0;
}