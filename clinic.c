#include<stdio.h>
#include"STD_Types.h"
#include"priv.h"

strPatient patient[PATIENT_MAX_NUMBERS] =
{
	{"John" , 28 , "male" , 7766 , "5to5.5PM"},{"Mark" , 30 , "male" , 7356, "5.5to6PM"},{"Sara" , 19 , "female" , 1119,"6to6.5PM"} 
};


void main (void)
{
	uint8 mode ;
	
	printf("  **WELCOME**\n\n");
	printf("pls enter the mode >> \nif user mode press: 1 \nif admin mode press: 2  \n");
	scanf("%d",&mode);
	if(mode == ADMIN_MODE)
	{
		AdminMode();
	}
	else if(mode == USER_MODE)
	{
		UserMode(); 
	}
	else 
	{
		printf("worng mode \n");
	}
	
}
void AdminMode(void)
{
	uint8 cntr1 = 0 , flag , cntr2 , feature , check ;
	uint16 pass , varID , IDLoc ;
	tenuErrorStatus ReturnValue ;
	
	
	do{
		printf("pls enter the pass : \n");
		scanf("%d",&pass);
		if(pass == 1234)
		{
			break ;
		}
		else if(cntr1 != 2)
		{
			printf("wrong pass .. try again \n");
		}
		cntr1++ ;
		}while(cntr1 < 3);
			
	if(cntr1 < 3 )
	{
	printf("To add new patient press 1 : \n\nTo edit patient info press : 2 \n\nTo reserve a slot with the doctor press : 3\n\nTo cancel reservation press : 4 \n\n");
	scanf("%d",&feature);
	}
	if(feature == 1) /*add new patient record*/
	{
		PatientInfo();
	}
	else if(feature == 2)
	{
		/*edit data*/
		printf("pls enter the ID of patient\n");
		scanf("%d",&varID);
		for(cntr2 = 0 ; cntr2 < 3 ; cntr2++)
		{	
			if(varID == patient[cntr2].ID)
			{
				flag = 100 ;
				break ;
			}	
		}		
			if(flag == 100)
			{	
				printf("the patient info is already exist.. the recorded data is : \n");
				printf("name : %s \nage : %d \ngender : %s \nID : %d \nslot : %s",patient[cntr2].name,patient[cntr2].age,patient[cntr2].gender,patient[cntr2].ID,patient[cntr2].slot);
				printf("To edit these data press: 1 \nif not press 2 \n");
				scanf("%d",&check);
				
				if(check == 1)
				{
					printf("enter the new name : \n");
					scanf("%s",&patient[cntr2].name);
					printf("enter the new age \n");
					scanf("%d",&patient[cntr2].age);
					printf("enter the new gender \n");
					scanf("%s",&patient[cntr2].gender);
					printf("enter the nem ID \n");
					scanf("%d",&patient[cntr2].ID);
					printf("THANK YOU");
				}	
				else if(check == 2)
				{
					printf("THANK YOU");
				}
				
				else 
				{
					printf("ERROR.. RESET and try again");
				}
			}	
			else
			{
				printf("the ID u entered is NOT exist");
			}
	}	
	
	else if(feature == 3)
	{
		/*reserve a slot with the doctor*/  
		ReturnValue = PatientInfo();
		if(ReturnValue == E_OK)
		{
			printf("\nToday available slots are \n\n");
			PrintSlots();	
		}
	}
 	else if(feature == 4)
	{
		/*cancel reservation*/
		printf("pls enter patient ID (only four numbers):\n");
		scanf("%d",&IDLoc);
		for(cntr2 = 0 ; cntr2 < 3 ; cntr2++)
		{
			if(IDLoc == patient[cntr2].ID)
			{
				printf("Already exist \n");
				cntr1 = 100;
				break ;
			}		
		}
		
		if(cntr1 == 100)
		{
			printf("%s",patient[cntr2].slot);
			printf("\nThe slot is canceled");
		}
		else
		{
			printf("The ID u entered is NOT exist");
		}
	}
	else 
	{
		printf("Pls RESET \n");
	}
}

void UserMode(void)
{
	uint8 featureLoc , cntr3 , temp = 0 ;
	uint16 IDLoc ;
	printf("To view patient record press 1 : \nTo view today's reservations press 2 : \n");
	scanf("%d",&featureLoc);
	
	if(featureLoc == 1)
	{
		printf("pls enter patient ID (only four numbers):\n");
		scanf("%d",&IDLoc);
		for(cntr3 = 0 ; cntr3 < 3 ; cntr3++)
		{
			if(IDLoc == patient[cntr3].ID)
			{
				printf("Already exist \n");
				temp = 100 ;
				break ;
			}		
		}
		if(temp == 100)
		{
			printf("name : %s \nage : %d \ngender : %s \nID : %d \nslot : %s",patient[cntr3].name,patient[cntr3].age,patient[cntr3].gender,patient[cntr3].ID,patient[cntr3].slot);
		}
		else
		{
			printf("The ID is NOT exist");
		}
	}
	else if(featureLoc == 2)
	{
		printf("The available slots are : \n\n");
		printf("From 2.5 to 3 PM \n\n");
		printf("From 3 to 3.5 PM \n\n");
		printf("From 3.5 to 4 PM \n\n");
		printf("From 4 to 4.5 PM \n\n");
		printf("From 4.5 to 5 PM \n\n");	
	}
	else
	{
		printf("Wrong choice !.. Pls RESET");
	}
}




void PrintSlots(void)
{
	uint32 slot , AnotherSlot , num ;	
	
	printf("From 2 to 2.5 PM -- To reserve press 1\n\n");
	printf("From 2.5 to 3 PM -- To reserve press 2\n\n");
	printf("From 3 to 3.5 PM -- To reserve press 3\n\n");
	printf("From 3.5 to 4 PM -- To reserve press 4\n\n");
	printf("From 4 to 4.5 PM -- To reserve press 5\n\n");
	printf("From 4.5 to 5 PM -- To reserve press 6\n\n");
	scanf("%d",&slot);
	if(slot == 1)
	{
		printf("\nDone! You have reserved from 2 to 2.5 PM \n");
	}
	else if(slot == 2)
	{
		printf("\nDone! You have reserved from 2.5 to 3 PM\n");
	}
	else if(slot == 3)
	{
		printf("\nDone! You have reserved from 3 to 3.5 PM\n");
	}
	else if(slot == 4)
	{
		printf("\nDone! You have reserved from 3.5 to 4 PM\n");
	}
	else if(slot == 5)
	{
		printf("\nDone! You have reserved from 4 to 4.5 PM\n");
	}
	else if(slot == 6)
	{
		printf("\nDone! You have reserved from 4.5 to 5 PM\n");
	}
	else 
	{
		printf("\nWrong choice.. Pls RESET");
	}	

	printf("\nTo reserve another slot press 1 , if not press 0 \n");
	scanf("%d",&AnotherSlot);
	if(slot == 1 && AnotherSlot == 1)
	   {
		printf("The available slots are \n\n");
		printf("From 2.5 to 3 PM -- To reserve press 2\n\n");
		printf("From 3 to 3.5 PM -- To reserve press 3\n\n");
		printf("From 3.5 to 4 PM -- To reserve press 4\n\n");
		printf("From 4 to 4.5 PM -- To reserve press 5\n\n");
		printf("From 4.5 to 5 PM -- To reserve press 6\n\n");
		scanf("%d",&slot);
		if(slot == 2)
	    {
	    	printf("\nDone! You have reserved from 2.5 to 3 PM");
	    }
	    else if(slot == 3)
	    {
	    	printf("\nDone! You have reserved from 3 to 3.5 PM");
	    }
	    else if(slot == 4)
	    {
	    	printf("\nDone! You have reserved from 3.5 to 4 PM");
	    }
	    else if(slot == 5)
	    {
	    	printf("\nDone! You have reserved from 4 to 4.5 PM");
	    }
	    else if(slot == 6)
	    {
	    	printf("\nDone! You have reserved from 4.5 to 5 PM");
	    }
	    else 
	    {
	    	printf("\nWrong choice.. Pls RESET");
	    }	
	    }
	   else if(slot == 2 && AnotherSlot == 1)
	   {
		printf("The available slots are \n\n");
		printf("From 2 to 2.5 PM -- To reserve press 1\n\n");
		printf("From 3 to 3.5 PM -- To reserve press 3\n\n");
		printf("From 3.5 to 4 PM -- To reserve press 4\n\n");
		printf("From 4 to 4.5 PM -- To reserve press 5\n\n");
		printf("From 4.5 to 5 PM -- To reserve press 6\n\n");
		scanf("%d",&slot);
		if(slot == 1)
	    {
	    	printf("\nDone! You have reserved from 2 to 2.5 PM");
	    }
	    else if(slot == 3)
	    {
	    	printf("\nDone! You have reserved from 3 to 3.5 PM");
	    }
	    else if(slot == 4)
	    {
	    	printf("\nDone! You have reserved from 3.5 to 4 PM");
	    }
	    else if(slot == 5)
	    {
	    	printf("\nDone! You have reserved from 4 to 4.5 PM");
	    }
	    else if(slot == 6)
	    {
	    	printf("\nDone! You have reserved from 4.5 to 5 PM");
	    }
	    else 
	    {
	    	printf("\nWrong choice.. Pls RESET");
	    }	
	    }
	   else if(slot == 3 && AnotherSlot == 1)
	   {
		printf("The available slots are \n\n");   
		printf("From 2 to 2.5 PM -- To reserve press 1\n\n");
		printf("From 2.5 to 3 PM -- To reserve press 2\n\n");
		printf("From 3.5 to 4 PM -- To reserve press 4\n\n");
		printf("From 4 to 4.5 PM -- To reserve press 5\n\n");
		printf("From 4.5 to 5 PM -- To reserve press 6\n\n");
		scanf("%d",&slot);
		if(slot == 1)
	    {
	    	printf("\nDone! You have reserved from 2 to 2.5 PM");
	    }
	    else if(slot == 2)
	    {
	    	printf("\nDone! You have reserved from 2.5 to 3 PM");
	    }
	    else if(slot == 4)
	    {
	    	printf("\nDone! You have reserved from 3.5 to 4 PM");
	    }
	    else if(slot == 5)
	    {
	    	printf("\nDone! You have reserved from 4 to 4.5 PM");
	    }
	    else if(slot == 6)
	    {
	    	printf("\nDone! You have reserved from 4.5 to 5 PM");
	    }
	    else 
	    {
	    	printf("\nWrong choice.. Pls RESET");
	    }	
	    }
	   
	   else if(slot == 4 && AnotherSlot == 1)
	   {
		printf("The available slots are \n\n");   
		printf("From 2 to 2.5 PM -- To reserve press 1\n\n");
		printf("From 2.5 to 3 PM -- To reserve press 2\n\n");
		printf("From 3 to 3.5 PM -- To reserve press 3\n\n");
		printf("From 4 to 4.5 PM -- To reserve press 5\n\n");
		printf("From 4.5 to 5 PM -- To reserve press 6\n\n");
		scanf("%d",&slot);
		if(slot == 2)
	    {
	    	printf("\nDone! You have reserved from 2.5 to 3 PM");
	    }
	    else if(slot == 3)
	    {
	    	printf("\nDone! You have reserved from 3 to 3.5 PM");
	    }
	    else if(slot == 1)
	    {
	    	printf("\nDone! You have reserved from 2 to 2.5 PM");
	    }
	    else if(slot == 5)
	    {
	    	printf("\nDone! You have reserved from 4 to 4.5 PM");
	    }
	    else if(slot == 6)
	    {
	    	printf("\nDone! You have reserved from 4.5 to 5 PM");
	    }
	    else 
	    {
	    	printf("\nWrong choice.. Pls RESET");
	    }	
	    }
	   
	   else if(slot == 5 && AnotherSlot == 1)
	   {
		printf("The available slots are \n\n");   
		printf("From 2 to 2.5 PM -- To reserve press 1\n\n");
		printf("From 2.5 to 3 PM -- To reserve press 2\n\n");
		printf("From 3 to 3.5 PM -- To reserve press 3\n\n");
		printf("From 3.5 to 4 PM -- To reserve press 4\n\n");
		printf("From 4.5 to 5 PM -- To reserve press 6\n\n");
		scanf("%d",&slot);
		if(slot == 2)
	    {
	    	printf("\nDone! You have reserved from 2.5 to 3 PM");
	    }
	    else if(slot == 3)
	    {
	    	printf("\nDone! You have reserved from 3 to 3.5 PM");
	    }
	    else if(slot == 4)
	    {
	    	printf("\nDone! You have reserved from 3.5 to 4 PM");
	    }
	    else if(slot == 1)
	    {
	    	printf("\nDone! You have reserved from 2 to 2.5 PM");
	    }
	    else if(slot == 6)
	    {
	    	printf("\nDone! You have reserved from 4.5 to 5 PM");
	    }
	    else 
	    {
	    	printf("\nWrong choice.. Pls RESET");
	    }	
	    }
	   else if(slot == 6 && AnotherSlot == 1)
	   {
		printf("From 2 to 2.5 PM -- To reserve press 1\n\n");
		printf("From 2.5 to 3 PM -- To reserve press 2\n\n");
		printf("From 3 to 3.5 PM -- To reserve press 3\n\n");
		printf("From 3.5 to 4 PM -- To reserve press 4\n\n");
		printf("From 4 to 4.5 PM -- To reserve press 5\n\n");
		scanf("%d",&slot);
		if(slot == 2)
	    {
	    	printf("\nDone! You have reserved from 2.5 to 3 PM");
	    }
	    else if(slot == 3)
	    {
	    	printf("\nDone! You have reserved from 3 to 3.5 PM");
	    }
	    else if(slot == 4)
	    {
	    	printf("\nDone! You have reserved from 3.5 to 4 PM");
	    }
	    else if(slot == 5)
	    {
	    	printf("\nDone! You have reserved from 4 to 4.5 PM");
	    }
	    else if(slot == 1)
	    {
	    	printf("\nDone! You have reserved from 2 to 2.5 PM");
	    }
	    else 
	    {
	    	printf("\nWrong choice.. Pls RESET");
	    }	
	    }
		if(AnotherSlot == 0)
		{
			printf("\nTHANK YOU\n");
		}
	}

tenuErrorStatus PatientInfo(void)
{
	uint8 num , cntr2 ;
	tenuErrorStatus Return = E_OK ;
	
	printf("pls enter patient number : \n");
	scanf("%d",&num);
	printf("pls enter patient ID (only four numbers):\n");
	scanf("%d",&patient[num].ID);
	for(cntr2 = 0 ; cntr2 < num ; cntr2++)
		{
			if(patient[num].ID == patient[cntr2].ID)
			{
				printf("Already exist \n");
				cntr2 = 100;
				Return = E_NOK ;
				break ;
			}		
		}
			
			
		if((num < PATIENT_MAX_NUMBERS) && cntr2 == num)
		{
		printf("pls enter the patient name : \n");
		scanf("%s",&patient[num].name);
		
		printf("pls enter the patient age : \n");
		scanf("%d",&patient[num].age);
		
		printf("pls enter the patient gender : male or female : \n");
		scanf("%s",&patient[num].gender);
		
		printf("THANK YOU.. You added a new patient\n");
		}
		else if((num >= PATIENT_MAX_NUMBERS))
		{
			printf("worng patient number.. !");
			Return = E_NOK ;
		}	
		
		return Return ;
}	


