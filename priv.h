#ifndef PRIV_H 
#define PRIV_H 

#define USER_MODE  1
#define ADMIN_MODE 2
#define PATIENT_MAX_NUMBERS   20 
void AdminMode();
void UserMode(void);
tenuErrorStatus PatientInfo(void);
void PrintSlots(void);
typedef struct 
{
	uint8 name[25];
	uint8 age ;
	uint8 gender[20]; /*male or female*/
	uint16 ID ;
	uint8 slot[10];
}strPatient ;
 

 
#endif