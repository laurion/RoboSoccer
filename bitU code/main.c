#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#ifndef WIN32
# include <unistd.h>
#else
# include <process.h>
# define snprintf sprintf_s
#endif

#include <mosquitto.h>

#define mqtt_host "192.168.1.72"
#define mqtt_port 1883

//ale mele

#define PI 3.1415
#define corectie 15
#define tcorectie 30
#define ypsus 280
#define ypjos 420
#define portar 92
#define idportar "in92"

#define minge 0
#define idminge "in0"
#define fundas 9
#define idfundas "in9"
#define limfundas 325
#define atacant 10
#define idatacant "in10"
#define limatacant 700
#define xpoarta 116
#define xfundas 176
#define ypsusfundas 80
#define ypjosfundas 140
#define ypsusa 275
#define ypjosa 481
#define ypcentrua 378
#define xpa 123
#define timpmiscareportar 0
#define coordonateinitialefundasx 300


struct control{
	int left;
	int right;
	int time;
}ctr[13];

struct robotCoords {
	int id;/*id robot - 1..10*/
	int x;  /*// 0...800  - relative la terenul de joc*/
	int y;  /*// 0...600*/
	int angle; /*// unghi fata de baza ringului*/
	int timestamp; /*// timpul cand au fost calculate - UNIXTIME - Ex: 1352460922*/
}coordrob[13];

struct timeval tv;
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
void progportar ()
{   /*if (coordrob[minge].x > 430)   //se schimba daca jucam in partea dreapta
        {if (coordrob[portar].x > xpoarta + 15)
            {
                if (coordrob[portar].angle < 270 && coordrob[portar].angle > 90)
                    {
                        ctr[portar].right = 70;
                        ctr[portar].left = 70;
                        ctr[portar].time = timpmiscareportar;
                    }
                    else
                    {
                        ctr[portar].right = -70;
                        ctr[portar].left = -70;
                        ctr[portar].time = timpmiscareportar;
                    }
            }
        if (coordrob[portar].angle > 285) {ctr[portar].right= -50; ctr[portar].left= 50;ctr[portar].time=30;
                                           }
        if (coordrob[portar].angle < 255) {ctr[portar].right= 50; ctr[portar].left= -50; ctr[portar].time = 30;
                                           }
        }
        else
    {*/printf ("\n portar x:%d    y:%d    \n'\n",coordrob[portar].x,coordrob[portar].y);
    if ((abs(coordrob[portar].y - ypsus)< 15)   && (coordrob[minge].y < coordrob[portar].y))
        {
            ctr[portar].right = 0;
            ctr[portar].left = 0;
            ctr[portar].time = timpmiscareportar;
        }
        else
            if((coordrob[portar].y - ypsus > 15) && (coordrob[minge].y < coordrob[portar].y))
                {
                    ctr[portar].right = -50;
                    ctr[portar].left = -50;
                    ctr[portar].time = timpmiscareportar;
                }
    if ((abs(coordrob[portar].y - ypjos) < 15)  && (coordrob[minge].y > coordrob[portar].y))
        {
            ctr[portar].right = 0;
            ctr[portar].left = 0;
            ctr[portar].time = timpmiscareportar;
        }
        else
            if ((coordrob[portar].y - ypjos < -15)  && (coordrob[minge].y > coordrob[portar].y))
                {
                    ctr[portar].right = 50;
                    ctr[portar].left = 50;
                    ctr[portar].time = timpmiscareportar;
                }

    if ((coordrob[minge].y < ypjos) && (coordrob[minge].y > ypsus))
        if (coordrob[portar].y > coordrob[minge].y)
            {
                ctr[portar].right = -40; ctr[portar].left = -40; ctr[portar].time = timpmiscareportar;
            }
        if (coordrob[portar].y < coordrob[minge].y)
            {
                ctr[portar].right = 40; ctr[portar].left = 40;ctr[portar].time = timpmiscareportar;
            }

    if (ypsus - coordrob[portar].y >15)
        {
            ctr[portar].left = 40;
            ctr[portar].right = 40;
            ctr[portar].time = timpmiscareportar;
        }
    if (coordrob[portar].y - ypjos > 15)
        {
            ctr[portar].left = -40;
            ctr[portar].right = -40;
            ctr[portar].time = timpmiscareportar;
        }
    //}
}



int unghiuldorit(int id,int x,int y)
{
    double m;
	m = atan2((double)(y - coordrob[id].y), (double)(x - coordrob[id].x));
	m = m * 180 / PI;
	printf ("panta: %lf        unghi: %d\n \n \n" , m, coordrob[atacant].angle);
	return m;

}

void mergi_drept(int id, int putere, int unghi_dorit)
{ /*  int dist2 = distanta(coordrob[id].x,coordrob[id].y,coordrob[minge].x,coordrob[minge].y);

    while (dist2 > 20)
    {*/
    int eroare= unghi_dorit - coordrob[id].angle;

    if((unghi_dorit>90 ) && (unghi_dorit<270))
    {
        if (eroare<0)
        {
            ctr[id].left  = putere + corectie;
            ctr[id].right = putere - corectie;
            ctr[id].time   = tcorectie;
        }
        else
        {
            ctr[id].left  = putere - corectie;
            ctr[id].right = putere +corectie;
            ctr[id].time   = tcorectie;
        }
    }
    else
    {
        if (eroare<0)
        {
            ctr[id].left  = putere - corectie;
            ctr[id].right = putere + corectie;
            ctr[id].time   = tcorectie;
        }
        else
        {
            ctr[id].left  = putere + corectie;
            ctr[id].right = putere - corectie;
            ctr[id].time   = tcorectie;
        }
    }
    /*dist2 = distanta(coordrob[id].x,coordrob[id].y,coordrob[minge].x,coordrob[minge].y);

    }
*/}

int travel (char* idid, int id, int x, int y)
{
	int c= x - coordrob[id].x;
	int b= y - coordrob[id].y;
	float distance = b*b + c*c;

	if (distance < 20*20) {ctr[id].right = 0; ctr[id].left = 0;}
		else
		{
			ctr[id].right = 80;
			ctr[id].left = 80;
			ctr[id].time = 100;

		}
	printf("\n distanta la patrat: %lf", distance);
	return distance;
}

void calculate_robot_next_movement() {
    //Orienteaza-te la un anumit unghi
    struct robotCoords thisR = coordrob[atacant];
    double m = unghiuldorit(minge, coordrob[atacant].x,coordrob[atacant].y);
    // Vreau la 90deg
    if(thisR.angle> m - 25 && thisR.angle < m + 25) {
            //mergi_drept(atacant,100,m);
            travel(idatacant,atacant,coordrob[minge].x,coordrob[minge].y);
        } else {
                ctr[atacant].left = 50;
                ctr[atacant].right = -20;
                ctr[atacant].time = 30;
                }

    progportar();
}

void do_robot_control_loop() {
    int mid;

    printf("Angle: %d\n", coordrob[atacant].angle);
    fflush(stdout);

    calculate_robot_next_movement();

    mosquitto_publish(mosq, &mid, idatacant, sizeof(struct control), &ctr[atacant], 0, false);
    mosquitto_publish(mosq, &mid, idportar, sizeof(struct control), &ctr[portar], 0, false);
    //mosquitto_loop(mosq, 1, 50);
    gettimeofday(&tv, NULL);
}

int need_to_send() {
    struct timeval now;

    gettimeofday(&now, NULL);

    if(tv.tv_usec > 800000)
        gettimeofday(&tv, NULL);

    if(now.tv_usec >= tv.tv_usec + 100000) {
            return 1;
    }

    return 0;
}
int main(int argc, char *argv[])
{
    char clientid[24]="FcBitu'";
	int rc = 0;
	signal(SIGINT, handle_signal);
	signal(SIGTERM, handle_signal);
	mosquitto_lib_init();
	mosq = mosquitto_new(clientid, true, NULL);
 	if(mosq){
		mosquitto_connect_callback_set(mosq, connect_callback);
		mosquitto_message_callback_set(mosq, message_callback);
		rc = mosquitto_connect(mosq, mqtt_host, mqtt_port, 60);
		mosquitto_subscribe(mosq, NULL, "coords", 0);
		mosquitto_loop_start(mosq);
        gettimeofday(&tv,NULL);
    	while(run){
			if(run && rc){
				sleep(2);
				printf ("\n run: %d   rc: %d  \n", run,rc);
				mosquitto_reconnect(mosq);
			}
			// incepe softul propriuzis
		    calculate_robot_next_movement();

            if(need_to_send())
                {
                printf ("coaieieeeeeieeieiie \n\n\n");
                do_robot_control_loop();
                }
		    fflush(stdout);
        }
		mosquitto_destroy(mosq);
	}

	mosquitto_lib_cleanup();

	return rc;
}
