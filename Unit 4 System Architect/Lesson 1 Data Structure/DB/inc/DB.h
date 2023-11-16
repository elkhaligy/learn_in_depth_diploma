/*
*	Student_Database.h
*	Created on: 16 Nov 2023
*	Author: Shehab Elkhaligy
*/

#ifndef STUDENT_DATABASE_
#define STUDENT_DATABASE_

typedef struct DB_Student DB_Student;
struct DB_Student{
	unsigned int ID;
	char Name[50];
	float Height;
	DB_Student * Next_Student_P;
};

void DB_Add_Student		(DB_Student ** Head);
void DB_Fill_Data		(DB_Student * Head);
void DB_Delete_Student	(DB_Student ** Head, unsigned int ID);
void DB_Delete_All		(DB_Student ** Head);
void DB_View_Students 	(DB_Student * Head);
void DB_Students_Number	(DB_Student * Head);
void DB_Reverse			(DB_Student ** Head);
void DB_Middle			(DB_Student * Head);
#endif