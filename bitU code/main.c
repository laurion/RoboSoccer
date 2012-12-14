#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#ifndef WIN32
# include <unistd.h>
#else
# include <process.h>
# define snprintf sprintf_s
#endif

#include <mosquitto.h>

#define mqtt_host "192.168.1.72"
#define mqtt_port 1883



#define ypsus 271
#define ypjos 420
#define portar 5
#define idportar "in5"
#define minge 0
#define idminge "in0"
#define fundas 2
#define idfundas "in2"
#define xpoarta 116
#define xfundas 176
#define ypsusfundas 80
#define ypjosfundas 140
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
#define ctrportar 1
#define ctrfundas 2
#define coordonateinitialefundasx 300


struct control{
    int left;
    int right;
    int time;
}ctr[6];

/*   */
struct robotCoords {
    int id;/*id robot - 1..10*/
    int x;  /*// 0...800  - relative la terenul de joc*/
    int y;  /*// 0...600*/
    int angle; /*// unghi fata de baza ringului*/
    int timestamp; /*// timpul cand au fost calculate - UNIXTIME - Ex: 1352460922*/
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

int distanta (int id, int id2)
{
    int c = coordrob[id].x - coordrob[id2].x;
    int b = coordrob[id].y - coordrob[id2].y;
    float dist = sqrt (b*b + c*c);
    return dist;
}

int travel (int id, int x, int y)
{
    //trb vazut cum ne invartim pt in jurul lui 0/360
    float m;
    m = (y - coordrob[id].y)/(x - coordrob[id].x);
    m = atan(m);
    int c= x - coordrob[id].x;
    int b= y - coordrob[id].y;
    float distance = sqrt (b*b + c*c);
    if (coordrob[id].angle < m-15)
        {
            ctr[id].left = 50;
            ctr[id].right = -50;
          //functie de id
          //  mosquitto_publish(mosq, &mid, "in2", sizeof(ctr), &ctr, 0, false);
        }
        else
            if (coordrob[id].angle > m+15)
                {
                    ctr[id].left = -50;
                    ctr[id].right = 50;
                }
                else
                    if ((coordrob[id].angle > m - 15) && (coordrob[id].angle < m-4))
                        {
                            ctr[id].left = 100;
                            ctr[id].right = 30;
                        }
                        else
                            if ((coordrob[id].angle >= m+4) && (coordrob[id].angle < m + 15))
                                {
                                    ctr[id].left = 30;
                                    ctr[id].right = 100;
                                }
                                else
                                    {
                                        ctr[id].left = 150;
                                        ctr[id].right = 150;
                                    }
    printf("\n distance: %lf", distance);
    return distance;
}

void progportar()
{
    if (coordrob[portar].angle > 274 && coordrob[portar].angle < 266)
    {
        if (coordrob[portar].angle > 274) {ctr[portar].right=50; ctr[portar].left=-50;}
            else
                if (coordrob[portar].angle < 266) {ctr[portar].right=-50; ctr[portar].left=50;}
    }
        else
            {if (coordrob[minge].y < ypsus)
                {
                    if (coordrob[portar].y > ypsus - 5) { ctr[portar].right = -50; ctr[portar].left = -50;}
                }
                else
                    if (coordrob[minge].y > ypjos)
                        {
                            if (coordrob[portar].y < ypjos - 5) { ctr[portar].right = 50; ctr[portar].left = 50;}
                        }
                        else
                            if ((coordrob[minge].y < ypjos) && (coordrob[minge].y > ypsus))
                                {if (coordrob[portar].y > coordrob[minge].y)
                                    {
                                        ctr[portar].right = -50; ctr[portar].left = -50;
                                    }
                                 if (coordrob[portar].y < coordrob[minge].y)
                                    {
                                        ctr[portar].right = 50; ctr[portar].left = 50;
                                    }
                                }
            if (coordrob[portar].y > ypjos)
                {
                    ctr[portar].right = -50;
                    ctr[portar].left = -50;
                }
                else
                    if (coordrob[portar].y < ypsus)
                        {
                            ctr[portar].right = 50;
                            ctr[portar].left = 50;
                        }
            }
mosquitto_loop(mosq, 5, 1);  // mai trb loop daca nu mai dau comanda in functie
}

void progfundas()
{//aranjare fundas
    if (coordrob[minge].x > limatacant)
        {
            if ((coordrob[fundas].x > coordonateinitialefundasx + 5) || (coordrob[fundas].x < coordonateinitialefundasx - 5))
                {
                    travel(fundas,coordonateinitialefundasx,325);
                }
                else
                    if (coordrob[fundas].angle <266 || coordrob[fundas].angle > 274)
                        {
                            ctr[fundas].right = 50;
                            ctr[fundas].left = -50;
                        }
        }
    //atac minge daca este pe langa fundas
        else
            {
                float distfb;
                distfb = distanta (fundas,minge);
                if ((coordrob[fundas].x < coordrob[minge].x) && (distfb < 105))
                    {
                        travel(fundas,coordrob[minge].x,coordrob[minge].y);
                    }
                    else
                        if (coordrob[fundas].x > coordrob[minge].x)
                            {
                        //atac la minge deja schimbat in spatele mingei, ca apoi sa dea in minge
                                travel(fundas,coordrob[minge].x - 15,coordrob[minge].y+30); // depinde unde e mingea..+ cand e sus, - cand e jos
                            }
                            else
                            //sa stea dupa minge
                                if (coordrob[minge].y < ypsusfundas)
                                    {
                                        if (coordrob[fundas].y > ypsusfundas - 5) { ctr[fundas].right = -50; ctr[fundas].left = -50;}
                                    }
                                    else
                                        if (coordrob[minge].y > ypjosfundas)
                                            {
                                                if (coordrob[fundas].y < ypjosfundas-5) { ctr[fundas].right = 50; ctr[fundas].left = 50;}
                                            }
                                            else
                                               {
                                                    if (coordrob[fundas].y > coordrob[minge].y)
                                                        {
                                                        ctr[fundas].right = -50; ctr[fundas].left = -50;
                                                        }
                                                    if (coordrob[fundas].y < coordrob[minge].y)
                                                        {
                                                        ctr[fundas].right = 50; ctr[fundas].left = 50;
                                                        }
                                               }
            }
}

void progmijlocasiatacant()
{
    if ((coordrob[minge].x > limfundas) && (coordrob[minge].x < limatacant))
        {
            float m,m1,m2;
            m = (coordrob[minge].y - ypcentrua)/(coordrob[minge].x - xpa);
            m1 = (coordrob[mijlocas1].y - ypcentrua)/(coordrob[mijlocas1].x - xpa);
            m2 = (coordrob[mijlocas2].y - ypcentrua)/(coordrob[mijlocas2].x - xpa);
            m = atan(m);
            m1 = atan(m1);
            m2 = atan(m2);
            if (abs(m1 - m) < abs(m2 - m))
                {
                    travel(mijlocas1,coordrob[minge].x,coordrob[minge].y);
                }
                else
                    {
                    travel(mijlocas2,coordrob[minge].x,coordrob[minge].y);
                    }
        }
        else
            if (coordrob[minge].x > limatacant)
                {
                    float m,m1,m2,m3;
                    m = (coordrob[minge].y - ypcentrua)/(coordrob[minge].x - xpa);
                    m1 = (coordrob[atacant].y - ypcentrua)/(coordrob[atacant].x - xpa);
                    m2 = (coordrob[mijlocas1].y - ypcentrua)/(coordrob[mijlocas1].x - xpa);
                    m3 = (coordrob[mijlocas2].y - ypcentrua)/(coordrob[mijlocas2].x - xpa);
                    m = atan(m);
                    m1 = atan(m1);
                    m2 = atan(m2);
                    m3 = atan(m3);
                    if (((m1 - m)<(m2 - m)) && ((m1 - m) < (m3 - m)))
                        {
                            travel(atacant,coordrob[minge].x,coordrob[minge].y);
                        }
                        else
                            {
                            if (((m2 - m) < (m1 - m)) && ((m2 - m) < (m3 - m)))
                                {
                                    travel(mijlocas1,coordrob[minge].x,coordrob[minge].y);
                                }
                                else
                                    {
                                    travel(mijlocas2,coordrob[minge].x,coordrob[minge].y);
                                    }
                            }
                }

}





int main(int argc, char *argv[])
{
char clientid[24]="FcBitu'";
int rc = 0;

signal(SIGINT, handle_signal);
signal(SIGTERM, handle_signal);

mosquitto_lib_init();
mosq = mosquitto_new(clientid, true, NULL);

//mosquitto_loop_start(mosq);

if(mosq){
mosquitto_connect_callback_set(mosq, connect_callback);
mosquitto_message_callback_set(mosq, message_callback);
rc = mosquitto_connect(mosq, mqtt_host, mqtt_port, 60);
mosquitto_subscribe(mosq, NULL, "coords", 0);

while(run){
    if(run && rc){
                sleep(2);
                printf ("\n run: %d   rc: %d  \n", run,rc);
                mosquitto_reconnect(mosq);
                }
// incepe softul propriuzis
    printf("robot: timestamp: %d     X: %d        Y: %d    unghi: %d\n ",coordrob[2] .timestamp,coordrob[2] .x,coordrob[2] .y,coordrob[2] .angle);
    printf("minge: timestamp: %d     X: %d        Y: %d    unghi: %d\n ",coordrob[0] .timestamp,coordrob[0] .x,coordrob[0] .y,coordrob[0] .angle);
    progportar();
  //  progfundas();
  //  progmijlocasiatacant();
//  mosquitto_publish(mosq, &mid, idportar, sizeof(struct control), &ctr[portar], 0, false);
//  printf ("comenzi robot: ctr.right: %d  ctr.left: %d timestamp: %d\n", ctr[portar].right,ctr[portar].left,coordrob[0].timestamp);

    mosquitto_publish(mosq, &mid, idportar, sizeof(struct control), &ctr[portar], 0, false);
  //  mosquitto_publish(mosq, &mid, idfundas, sizeof(struct control), &ctr[fundas], 0, false);
    //mosquitto_publish(mosq, &mid, idmijlocas1, sizeof(struct control), &ctr[mijlocas1], 0, false);
   // mosquitto_publish(mosq, &mid, idmijlocas2, sizeof(struct control), &ctr[mijlocas2], 0, false);
  //  mosquitto_publish(mosq, &mid, idatacant, sizeof(struct control), &ctr[atacant], 0, false);
    usleep(10000);
    //sa reinitializez ctr?
    fflush(stdout);
    rc = mosquitto_loop(mosq, 1, 1);
    }
mosquitto_destroy(mosq);
}

mosquitto_lib_cleanup();

return rc;
}
