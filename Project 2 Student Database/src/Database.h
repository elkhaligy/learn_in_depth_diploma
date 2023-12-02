/*
 * 	Database.h
 *
 *  Created on: 2 Dec 2023
 *  Author: Shehab Elkhaligy
 */
#ifndef DATABASE_H
#define DATABASE_H
#define Read(Var) fgets(Var,sizeof(Var),stdin); Var[strlen(Var) - 1] = '\0'


// Forwared declaration
typedef struct Queue Queue_T;

typedef struct Student{
	char First_Name[50];
	char Last_Name[50];
	unsigned int Roll_Number;
	float GPA;
	unsigned int Course_ID[10]; 
}Student_T;


void Get_Data_File(Queue_T *Database_Queue); 		//✅
void Get_Data_Manually(Queue_T *Database_Queue); 	//✅
void Find_By_Roll_Number(Queue_T *Database_Queue); 	//✅
void Find_By_First_Name(Queue_T *Database_Queue);	//✅
void Find_Course(Queue_T *Database_Queue);			//✅
void Find_Students_Count(Queue_T *Database_Queue); 	//✅
void Delete_By_Roll_Number(Queue_T *Database_Queue);
void Update_By_Roll_Number(Queue_T *Database_Queue);
void Show_All_Students(Queue_T *Database_Queue);	//✅
void Show_A_Student(Student_T *Student); 			//✅











#endif