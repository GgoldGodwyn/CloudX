/* 
 * File:   simMain.c
 * Author: Ogboye Godwin
 *
 * Created on March 5, 2018, 11:01 AM
 */

#include <CloudX\CloudX.h>
#include <CloudX/Serial.h>
#include "sim800.h"
//#include "calls.h" //auto include string.h from sim800.h
#include "sms.h"

setup(){
    serialBegin(9600);
    int response;
    loop(){
       /* delayms(1500);
        while(response!=1){
            response=sim800_verifyResponse(echoOff,ok);
            delayms(500);
        }
       sim800_verifyResponse(verify,ok);
       //serialWriteText(catchIncoming());
        sms_verifyResponse(massageFormat,yes,TxtMode,ok);//PduMode
        response = sendSms("08161111269","welcome BOSS");
       */
    }
}
 

