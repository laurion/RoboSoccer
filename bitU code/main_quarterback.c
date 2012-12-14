#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef WIN32
# include <unistd.h>
#else
# include <process.h>
# define snprintf sprintf_s
#endif

#include <mosquitto.h>
//#include "quaterback_oriented.h"

#define mqtt_host "192.168.1.72"
#define mqtt_port 1883
//definite de mine
#define ypsus 275
#define ypjos 481
#define ceva_portar 4
#define idportar "in5"
//#define 0 0
//#define 0 "in0"
//#define fundas 2
//#define fundas "in2"
//#define xpoarta 116
//#define xfundas 176
//#define ypsusfundas 80
//#define ypjosfundas 140
#define ypsusa 275
#define ypjosa 481
#define ypcentrua 378
#define limatacant 700
#define xpa 123
#define atacant 1
#define idatacant "in1"
#define mijlocas1 2
#define mijlocas2 3
#define idmijlocas1 "in2"
#define idmijlocas2 "in3"
#define limfundas 325
//restructurare pt quaterback_oriented
#define k 10
#define PI 3.159265
#define minge 0
#define idminge "in0"
#define fundas 4
#define idfundas "in4"
#define xpoarta 116
#define xsusfundas 240
#define ysusfundas 80
//#define time
#define deplasare 60
//#define yjosfundas 140


#define xmap 480
#define ymap 864



struct control{
    int left;
    int right;
    int time;
} ctr[13];

struct robotCoords {
    int id; // id robot - 1..10
    int x;  // 0...800  - relative la terenul de joc
    int y;  // 0...600
    int angle; // unghi fata de baza ringului
    int timestamp; // timpul cand au fost calculate - UNIXTIME - Ex: 1352460922
}coordrob[13];

static int run = 1;
struct mosquitto *mosq;
int mid;

void handle_signal(int s)
{
run = 0;
}

void connect_callback(struct mosquitto *mosq, void *obj, int result)
{
}

void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
{
struct robotCoords *coordonate = (struct robotCoords *)message->payload;
coordrob[coordonate->id].angle = coordonate->angle;
coordrob[coordonate->id].timestamp = coordonate->timestamp;
coordrob[coordonate->id].x = coordonate->x;
coordrob[coordonate->id].y = coordonate->y;
}

//============quaterback_oriented===============
int travel_quarterback()
{   int x,y;
    double unghi_deplasare;
    int xjosfundas = xmap - xsusfundas;
//    int yjosfundas = ymap - ysusfundas;
  double panta = (coordrob[0].y - coordrob[fundas].y)/(coordrob[0].x - coordrob[fundas].x);
  double  unghi = atan2((double)(coordrob[0].y - coordrob[fundas].y),(double)(coordrob[0].x - coordrob[fundas].x));
   unghi  = unghi*180/3.1415 + 180;
  //parcurgere distanta robot bila in functie de panta dreptei in partea de jos
  if(coordrob[0].x <= xmap/2 && coordrob[fundas].angle > 270 && coordrob[fundas].angle < (2* unghi ) && coordrob[fundas].x <= xsusfundas)
  {
      if(unghi_deplasare >= 0)
      {
                ctr[fundas].left = -50;
                ctr[fundas].right = 50;
                //ctr[fundas].time = 100;
                usleep(10);

                ctr[fundas].left = -deplasare;
                ctr[fundas].right = deplasare/10;
                x = coordrob[fundas].x;
                y = coordrob[fundas].y;
      }
      else
      if(unghi_deplasare <= 90 && unghi_deplasare > 0 )
      {
            ctr[fundas].left = deplasare/10;
            ctr[fundas].right = -deplasare;
            usleep(10);
            x = coordrob[fundas].x;
            y = coordrob[fundas].y;
      }
      else
        if(unghi_deplasare <= 180 && unghi_deplasare < 90)
        {
            ctr[fundas].left = - deplasare;
            ctr[fundas].right = 2*deplasare/10;
            usleep(20);
            x = coordrob[fundas].x;
            y = coordrob[fundas].y;
        }
        else
            if(unghi_deplasare <= 270 && unghi_deplasare > 180)
            {
                ctr[fundas].left = -deplasare;
                ctr[fundas].right = deplasare/10;
                usleep(42);
                x = coordrob[fundas].x;
                y = coordrob[fundas].y;

            }
            else
            if(unghi_deplasare == 360 && unghi_deplasare > 180)
            {
                ctr[fundas].left = -50;
                ctr[fundas].right = 50;
                usleep(10);

                ctr[fundas].left = -deplasare;
                ctr[fundas].right = deplasare/10;
                x = coordrob[fundas].x;
                y = coordrob[fundas].y;
            }
            coordrob[fundas].x = coordrob[0].x + 10;
            coordrob[fundas].y = coordrob[0].y + 10;
            usleep(10);
            float panta1 = (y- coordrob[fundas].y)/(x- coordrob[fundas].x);
            if(panta <= panta1)
            {
                ctr[fundas].left = 100;
                ctr[fundas].right = 100;
                usleep(100);

                ctr[fundas].left = 20;
                ctr[fundas].right = 100;
                usleep(10);
            }
            else
            {
                ctr[fundas].left = 80;
                ctr[fundas].right = 80;
                //k = k + 30;
                usleep(10);
            }
            //lovire 0
            if(coordrob[fundas].y -10 == coordrob[0].y)
            {
                ctr[fundas].left = 80;
                ctr[fundas].right = 80;
                usleep(10);
            }
            else
            {
                ctr[fundas].left = 80;
                ctr[fundas].right = 80;
                usleep(10);
            }

  }
  else  if(coordrob[0].x <= xmap/2 && coordrob[fundas].angle < 270 && coordrob[fundas].angle > (180 - unghi) && coordrob[fundas].x >= xsusfundas && coordrob[fundas].x <= xjosfundas)
        {
                if(unghi_deplasare >= 0)
      {
                ctr[fundas].left = -50;
                ctr[fundas].right = 50;
                usleep(10);
                x = coordrob[fundas].x;
                y = coordrob[fundas].y;
      }
      else
      if(unghi_deplasare <= 90 && unghi_deplasare > 0 )
      {
            ctr[fundas].left = deplasare;
            ctr[fundas].right = -deplasare;
            usleep(10);
            x = coordrob[fundas].x;
            y = coordrob[fundas].y;
      }
      else
        if(unghi_deplasare <= 180 && unghi_deplasare < 90)
        {
            ctr[fundas].left = - deplasare;
            ctr[fundas].right = 2*deplasare/10;
            usleep(45);
            x = coordrob[fundas].x;
            y = coordrob[fundas].y;
        }
        else
            if(unghi_deplasare <= 270 && unghi_deplasare > 180)
            {
                ctr[fundas].left = -deplasare;
                ctr[fundas].right = deplasare;
                usleep(30);
                x = coordrob[fundas].x;
                y = coordrob[fundas].y;

            }
            else
            if(unghi_deplasare == 360 && unghi_deplasare > 180)
            {
                ctr[fundas].left = deplasare;
                ctr[fundas].right = -deplasare/10;
                usleep(32);
                x = coordrob[fundas].x;
                y = coordrob[fundas].y;
            }
            coordrob[fundas].x = coordrob[0].x + 10;
            coordrob[fundas].y = coordrob[0].y + 10;
            usleep(10);
            float panta1 = (y- coordrob[fundas].y)/(x - coordrob[fundas].x);
            if(panta <= panta1)
            {
                ctr[fundas].left = 100;
                ctr[fundas].right = 100;
                usleep(100);

                ctr[fundas].left = 100;
                ctr[fundas].right = 10;
                usleep(10);
            }
            else
            {
                ctr[fundas].left = 80;
                ctr[fundas].right = 80;
                //k = k+30;
                usleep(10);
            }
            //lovire 0
            if(coordrob[fundas].y -10 == coordrob[0].y)
            {
                ctr[fundas].left = 80;
                ctr[fundas].right = 80;
                usleep(10);
            }
            else
            {
                ctr[fundas].left = 80;
                ctr[fundas].right = 80;
                usleep(10);
            }


        }
        if(coordrob[0].x <= xmap/2 )
            {
                ctr[fundas].left = 100;
                ctr[fundas].right = 100;
                if(coordrob[fundas].x == (coordrob[fundas].y - coordrob[0].y - 10) && coordrob[fundas].x < xsusfundas)
                   {
                       ctr[fundas].left = -80;
                       ctr[fundas].right = 80;
                       usleep(200);

                       ctr[fundas].left = 80;
                       ctr[fundas].right = -80;
                       usleep(200);

                       ctr[fundas].left = 100;
                       ctr[fundas].right = 100;
                       usleep(100);
                   }

            }
            else
                {
                    ctr[fundas].left = 100;
                    ctr[fundas].right = 100;
                    if(coordrob[fundas].x == (coordrob[fundas].y - coordrob[0].y - 10) && coordrob[fundas].x > xjosfundas)
                       {

                       ctr[fundas].left = 80;
                       ctr[fundas].right = -80;
                       usleep(200);

                        ctr[fundas].left = -80;
                       ctr[fundas].right = 80;
                       usleep(200);

                       ctr[fundas].left = 100;
                       ctr[fundas].right = 100;
                       usleep(100);
                       }
                }
                printf("Panta Fundas_0: %lf", panta);
                return panta;
}
void quarterback_oriented()
{
    int xjosfundas = xmap - xsusfundas;
    int yjosfundas = ymap - ysusfundas;

        if(coordrob[fundas].x <= xmap/2 && ymap <= 3*ymap/2 )
            {
                if(xsusfundas <= xmap/2 && coordrob[fundas].x > xsusfundas)
                {
                    travel_quarterback();
                   // mosquitto_publish(mosq, &mid, fundas, sizeof(struct control), &ctr[fundas], 0, false);
                }
                else
                    if(xjosfundas >= xmap/2 && coordrob[fundas].x < xsusfundas)
                    {
                        travel_quarterback();
                        //mosquitto_publish(mosq, &mid, fundas, sizeof(struct control), &ctr[fundas], 0, false);
                    }

            }
}
//============================================================




int main(int argc, char *argv[])
{
char clientid[24]="FcBitu'";
int rc = 0;
//int nr = 0;

struct mosquitto *mosq;
int mid;

signal(SIGINT, handle_signal);
signal(SIGTERM, handle_signal);

mosquitto_lib_init();
mosq = mosquitto_new(clientid, true, NULL);

if(mosq){
mosquitto_connect_callback_set(mosq, connect_callback);
mosquitto_message_callback_set(mosq, message_callback);
rc = mosquitto_connect(mosq, mqtt_host, mqtt_port, 60);
mosquitto_subscribe(mosq, NULL, "coords", 0);

while(run){
rc = mosquitto_loop(mosq, 1, 1);
if(run && rc){
        sleep(2);
        printf ("\n run: %d   rc: %d  \n", run,rc);
        mosquitto_reconnect(mosq);
        }
printf("robot: timestamp: %d     X: %d        Y: %d    unghi: %d\n ",coordrob[4] .timestamp,coordrob[4] .x,coordrob[4] .y,coordrob[4] .angle);
printf("0: timestamp: %d     X: %d        Y: %d    unghi: %d\n ",coordrob[0] .timestamp,coordrob[0] .x,coordrob[0] .y,coordrob[0] .angle);

quarterback_oriented();
mosquitto_publish(mosq, &mid, idfundas, sizeof(struct control), &ctr[fundas], 0, false);
mosquitto_publish(mosq, &mid, idminge, sizeof(struct control), &ctr[0], 0, false);
//mosquitto_publish(mosq, &mid, idportar, sizeof(struct control), &ctr[ceva_portar], 0, false);

//usleep(1000);
/*if (nr >= 255) nr = 0;
ctr.right = nr; ctr.left = nr;
nr = nr + 1;
printf ("comenzi robot: ctr.right: %d  ctr.left: %d timestamp: %d\n", ctr.right,ctr.left,coordrob[0].timestamp);
fflush(stdout);*/
}
mosquitto_destroy(mosq);
}

mosquitto_lib_cleanup();

return rc;
}
