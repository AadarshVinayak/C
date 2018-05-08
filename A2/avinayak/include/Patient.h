#ifndef _PATIENT_
#define _PATIENT_

#include <stdio.h>
#include <stdlib.h>

/**
 *The patient struct that has all the patients data 
 **/
typedef struct hospitalPatient{
   char *id;
   int priority;
   char* symptom;
   int time;
}Patient;

/** Allocates space and populates data with all the information
 *@param the Id of the patient
 *@param the priority of the patient
 *@param the symptom of the patient
 *@return Patient
 **/
Patient *initializePatient(char* id,int priority, char* symptom); 

/**frees all the data in the Patient
 *@param void data that is a patient
 **/
void deletePatient(void* toBeDeleted);

/**Prints the patients data
 *@param Patient to be printed
 **/
void printPatient(void* toBePrinted);

/** Compares to priorities and returns a number stating either bigger or smaller
 *@param the first patient
 *@param the second patient
 *@return int representing bigger or smaller
 **/
int comparePriority(const void* first, const void *second);

/**Gets the time of the symptom
 *@param char symptom 
 *@return int representing the time  
**/
int getTime(char* symptom);
#endif
