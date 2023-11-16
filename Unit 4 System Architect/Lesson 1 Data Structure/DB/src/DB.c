/*
*	Student_Database.c
*	Created on: 16 Nov 2023
*	Author: Shehab Elkhaligy
*/
#include "../inc/DB.h"
#include "stdio.h"
#include "stdlib.h"
unsigned int Student_Count = 0;
void DB_Add_Student(DB_Student ** Head){
	DB_Student * Last_Student_P;
	DB_Student * New_Student_P;
	if(*Head == NULL){
		New_Student_P = (DB_Student *)malloc(sizeof(DB_Student));
		*Head = New_Student_P;
	} 
	else
	{
		Last_Student_P = *Head;
		while(Last_Student_P -> Next_Student_P != NULL)
			Last_Student_P = Last_Student_P -> Next_Student_P;  
		New_Student_P = (DB_Student *)malloc(sizeof(DB_Student));
		Last_Student_P -> Next_Student_P = New_Student_P;
	}
	New_Student_P -> Next_Student_P = NULL;
	DB_Fill_Data(New_Student_P);
	Student_Count++;
}
void DB_Fill_Data(DB_Student * Head){
	char Temp[50];
	printf("=== Student Number %d Data Entry ===\n",Student_Count+1);
	printf("Enter ID: ");
	gets(Temp);
	printf("\n");
	Head -> ID = atoi(Temp);
	printf("Enter Student Full Name: ");
	gets(Head -> Name);
	printf("\n");
	printf("Enter Height: ");
	gets(Temp);
	printf("\n");
	Head -> Height = atof(Temp);
}
void DB_Delete_Student(DB_Student ** Head, unsigned int ID){
	if(*Head == NULL)
		return;
	DB_Student * Prev_Student_P = NULL;
	DB_Student * Curr_Student_P= *Head;
	while(Curr_Student_P != NULL){
		if(Curr_Student_P -> ID == ID){
			if(Prev_Student_P != NULL)
				Prev_Student_P -> Next_Student_P = Curr_Student_P -> Next_Student_P;
			else
				*Head = Curr_Student_P -> Next_Student_P;
			printf("Deleted!\n");
			Student_Count--;
			return;
		}
		Prev_Student_P = Curr_Student_P;
		Curr_Student_P = Curr_Student_P -> Next_Student_P;
	}
	printf("Cannot find student with this ID.\n");
}
void DB_Delete_All(DB_Student ** Head){
	if(*Head == NULL)
		printf("Empty List\n");
	while(*Head!=NULL){
		DB_Student * Temp = *Head;
		*Head = (*Head) -> Next_Student_P;
		free(Temp);
	}
	*Head = NULL;
}

void DB_View_Students(DB_Student * Head){
	DB_Student * Temp = Head;
	unsigned int Count = 1;
	if(Temp == NULL){
		printf("Empty List\n");
		return;
	}
	printf("=== There Are Total of %d Students in The Database ===\n",Student_Count);
	while(Temp != NULL){
		printf("Displaying Student Number %d Data\n",Count);
		printf("ID: %d\n",Temp -> ID);
		printf("Name: %s\n",Temp -> Name);
		printf("Height: %.1f\n",Temp -> Height);
		Temp = Temp -> Next_Student_P;
		Count ++;
	}
}
void DB_Students_Number(DB_Student * Head){
	unsigned int Cnt=0;
	if(Head==NULL){
		printf("\nNumber of students: %u\n",Cnt);
		return;
	}
	while(Head!=NULL){
		Head = Head -> Next_Student_P;
		Cnt ++;
	}
	printf("\nNumber of students: %u\n",Cnt);
}

void DB_Reverse	(DB_Student ** Head){
	DB_Student * Prev_P	= NULL;
	DB_Student * Cur_P	= *Head;
	DB_Student * Next_P	= *Head;

	while(Cur_P!=NULL){
		Next_P = Cur_P -> Next_Student_P;
		Cur_P -> Next_Student_P = Prev_P;
		Prev_P = Cur_P;
		Cur_P = Next_P;
	}
	*Head = Prev_P;
}

void DB_Middle(DB_Student * Head){
	DB_Student * Fast = Head;
	DB_Student * Slow = Head;
	while(Fast != NULL &&Fast->Next_Student_P!=NULL){
		Fast = Fast -> Next_Student_P;
		if(Fast==NULL)
			return;
		Fast = Fast -> Next_Student_P;
		Slow = Slow -> Next_Student_P;
	}
	printf("\nMiddle Student is: \n");
	printf("ID: %d\n",Slow -> ID);
	printf("Name: %s\n",Slow -> Name);
	printf("Height: %.1f\n",Slow -> Height);
}