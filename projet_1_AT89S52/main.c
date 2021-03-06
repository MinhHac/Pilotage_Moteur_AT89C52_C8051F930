#include <REGX52.H>
#include "Test_pin.h"
#include "InitDevice.h"
#include "variables_globales.h"
#include "moteur.h"
#include "moteur_port.h"



// prototype
void scheduler(void);

void main(){ 
	
	initDevice();


	while (1){
		while(new_task==0);
		new_task=0;
		scheduler();
	}                       

}

void scheduler(void){

    static bit flag_init_moteur =0, etat_button=0; 

	switch(scheduler_ct) {
		case 0: {
		   //TEST =!TEST;
		    if(flag_init_moteur == 0){
				flag_init_moteur = 1;
				InitMoteur_Base100us(); 
		    }
		
		    if(BUTTON == 0 && etat_button != 0){
				demarage_arret_Moteur();
				//TEST =!TEST;
	    	                etat_button = 0;
	            }else if(BUTTON != 0){
	    		        etat_button = 1;
	           }  
		 
			 break;
		}
		default: break;
	}

	scheduler_ct++;
	if(scheduler_ct==240) scheduler_ct=0;
}
