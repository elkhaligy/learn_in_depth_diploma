/*
 * 	Database.c
 *
 *  Created on: 2 Dec 2023
 *  Author: Shehab Elkhaligy
 */
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Database.h"
#include "fifo.h"


void Get_Data_File(Queue_T *Database_Queue){
	FILE *File;
	char Buffer[500];
	File = fopen("D:\\Documents\\Personal\\Learn In Depth Diploma\\Code\\Project 2 Student Database\\Data.txt", "r");
    if (File == NULL) {
        printf("[ERROR] Unable to open file\n");
        return;
    }

	Student_T New_Student;
    while (fgets(Buffer, sizeof(Buffer), File) != NULL) {
		New_Student.Roll_Number = atoi(Buffer);
		sscanf(Buffer,"%d %s %s %f %d %d %d %d %d",&New_Student.Roll_Number,New_Student.First_Name,New_Student.Last_Name,&New_Student.GPA,&New_Student.Course_ID[0],&New_Student.Course_ID[1],&New_Student.Course_ID[2],&New_Student.Course_ID[3],&New_Student.Course_ID[4]);

		// Check if roll number already exist
		int Flag=0;
		Student_T * Temp_Pointer = Database_Queue->Tail;
		for (int i = 0; i < Database_Queue->Count; i++){
			if(Temp_Pointer->Roll_Number == New_Student.Roll_Number){
				printf("[ERROR] Roll Number %d Already Exist.\n",New_Student.Roll_Number);
				Flag=1;
			}
			Temp_Pointer++;
		}
		if(Flag == 0){
			FIFO_Enqueue(Database_Queue, New_Student);
			printf("[INFO] Added Student With Roll Number %d Successfully.\n",New_Student.Roll_Number);
		}
		
    }
	Find_Students_Count(Database_Queue);
   	fclose(File);
}

void Get_Data_Manually(Queue_T *Database_Queue){
	char Temp[50];
	Student_T New_Student;
	printf("Add the Students Details Manually\n");

	printf("Enter the Roll Number:");
	Read(Temp);
	New_Student.Roll_Number = atoi(Temp);
	// Check if roll number already exist
	Student_T * Temp_Pointer = Database_Queue->Tail;
	for (int i = 0; i < Database_Queue->Count; i++){
		if(Temp_Pointer->Roll_Number == New_Student.Roll_Number){
			printf("[ERROR] Roll Number %d Already Exist.\n",New_Student.Roll_Number);
			return;
		}
		Temp_Pointer++;
	}
	printf("Enter the First Name of the Student:");
	Read(Temp);
	strcpy(New_Student.First_Name,Temp);

	printf("Enter the Last Name of the Student:");
	Read(Temp);
	strcpy(New_Student.Last_Name,Temp);

	printf("Enter the GPA:");
	Read(Temp);
	New_Student.GPA = atof(Temp);

	printf("Enter Course ID of Each Course\n");
	for (int i = 0; i < 5; i++){
		printf("Course %d ID:",i+1);
		Read(Temp);
		New_Student.Course_ID[i] = atoi(Temp);
	}
	FIFO_Enqueue(Database_Queue, New_Student);
	printf("[INFO] Student Details Added Successfully :)\n");
	Find_Students_Count(Database_Queue);
}

void Find_By_Roll_Number(Queue_T *Database_Queue){
	char Temp[10];
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	printf("Enter the Roll Number of The Student: ");
	Read(Temp);
	Student_T * Temp_Pointer = Database_Queue->Tail;
	for (int i = 0; i < Database_Queue->Count; i++){
		if(Temp_Pointer->Roll_Number == atoi(Temp)){
			printf("[INFO] Found the Student With Roll Number: %d\n",atoi(Temp));
			Show_A_Student(Temp_Pointer);
			Flag = Found;
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		printf("[ERROR] Roll Number %d Not Found.\n",atoi(Temp));
}

void Find_By_First_Name(Queue_T *Database_Queue){
	char Temp[10];
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	printf("Enter the First Name of The Student: ");
	Read(Temp);
	Student_T * Temp_Pointer = Database_Queue->Tail;
	for (int i = 0; i < Database_Queue->Count; i++){
		if( !strcmp(Temp_Pointer->First_Name,Temp) ){
			printf("[INFO] Found the Student With First Name: %s\n",Temp);
			Show_A_Student(Temp_Pointer);
			Flag = Found;
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		printf("[ERROR] First Name %s Not Found.\n",Temp);
}

void Find_Course(Queue_T *Database_Queue){
	char Temp[50];
	printf("Enter the ID of The Course: ");
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	Read(Temp);
	Student_T * Temp_Pointer = Database_Queue->Tail;
	for (int i = 0; i < Database_Queue->Count; i++){
		for (int j = 0; j < 5; j++){
			if( Temp_Pointer->Course_ID[j] == atoi(Temp) ){
				Show_A_Student(Temp_Pointer);
				Flag = Found;
			}
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		printf("[ERROR] Course ID %d Not Found.\n",atoi(Temp));
}

void Find_Students_Count(Queue_T *Database_Queue){
	printf("[INFO] Number of Students In the Database: %d\n",Database_Queue->Count);
	printf("[INFO] You Can Add Up To %d More Students.\n",50-Database_Queue->Count);
}

void Delete_By_Roll_Number(Queue_T *Database_Queue){
	char Temp[10];
	printf("Enter the Roll Number To Delete: ");
	Read(Temp);
	Student_T * Temp_Pointer = Database_Queue->Tail;
	for (int i = 0; i < Database_Queue->Count; i++){
		if(Temp_Pointer->Roll_Number == atoi(Temp)){
			printf("[INFO] Found the Student With Roll Number: %d\n",atoi(Temp));
			// Copy First Element To Dequeue in This Element
			Temp_Pointer->Roll_Number=Database_Queue->Tail->Roll_Number;
			for (int i = 0; i < 5; i++)
				Temp_Pointer->Course_ID[i]	= Database_Queue->Tail->Course_ID[i];
			Temp_Pointer->GPA = Database_Queue->Tail->GPA;
			strcpy(Temp_Pointer->First_Name,Database_Queue->Tail->First_Name);
			strcpy(Temp_Pointer->Last_Name,Database_Queue->Tail->Last_Name);
			FIFO_Dequeue(Database_Queue);
			return;
		}
		Temp_Pointer++;
	}
	printf("[ERROR] Roll Number %d Not Found.\n",atoi(Temp));
}

void Update_By_Roll_Number(Queue_T *Database_Queue){
	char Temp[10];
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	printf("Enter the Roll Number To Update: ");
	Read(Temp);
	Student_T * Temp_Pointer = Database_Queue->Tail;
	for (int i = 0; i < Database_Queue->Count; i++){
		if(Temp_Pointer->Roll_Number == atoi(Temp)){
			printf("[INFO] Found the Student With Roll Number: %d\n",atoi(Temp));
			printf("What Do You Want To Update?:\n");
			printf("1. First Name\n2. Last Name\n3. Roll Number\n4. GPA\n5. Courses\n");
			Read(Temp);
			switch(atoi(Temp)){
				case 1:
					printf("Enter the New First Name: ");
					Read(Temp);
					strcpy(Temp_Pointer->First_Name,Temp);
					printf("[INFO ]Updated!\n");
					break;
				case 2:
					printf("Enter the New Last Name: ");
					Read(Temp);
					strcpy(Temp_Pointer->Last_Name,Temp);
					printf("[INFO ]Updated!\n");
					break;
				case 3:
					printf("Enter the New Roll Number: ");
					Read(Temp);
					Temp_Pointer->Roll_Number = atoi(Temp);
					printf("[INFO ]Updated!\n");
					break;
				case 4:
					printf("Enter the New GPA: ");
					Read(Temp);
					Temp_Pointer->GPA = atof(Temp);
					printf("[INFO ]Updated!\n");
					break;
				case 5:
					for (int i = 0; i < 5; i++){
						printf("Enter the Course %d New ID:",i+1);
						Read(Temp);
						Temp_Pointer->Course_ID[i] = atoi(Temp);
					}
					break;
				default:
					printf("[ERROR] Wrong Entry, Try Again.\n");
			}
			Show_A_Student(Temp_Pointer);
			Flag = Found;
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		printf("[ERROR] Roll Number %d Not Found.\n",atoi(Temp));
}

void Show_All_Students(Queue_T *Database_Queue){
	if(Database_Queue->Count==0){
		printf("[ERROR] Empty Database\n");
		return;
	}
	Student_T * Temp_Pointer = Database_Queue->Tail;
	printf("Student Details Are:\n");
	for (int i = 0; i < Database_Queue->Count; i++){
		printf("The First Name: %s\n",Temp_Pointer->First_Name);
		printf("The Last Name: %s\n",Temp_Pointer->Last_Name);
		printf("The Roll Number: %d\n",Temp_Pointer->Roll_Number);
		printf("The GPA: %.2f\n",Temp_Pointer->GPA);
		for (int i = 0; i < 5; i++)
			printf("Course %d ID: %d\n",i+1,Temp_Pointer->Course_ID[i]);
		printf("----------\n");
		Temp_Pointer++;
	}
}

void Show_A_Student(Student_T *Student){
	printf("Student Details Are:\n");
	printf("The First Name: %s\n",Student->First_Name);
	printf("The Last Name: %s\n",Student->Last_Name);
	printf("The Roll Number: %d\n",Student->Roll_Number);
	printf("The GPA: %.2f\n",Student->GPA);
	for (int i = 0; i < 5; i++){
		printf("Course %d ID: %d\n",i+1,Student->Course_ID[i]);
	}
	printf("----------\n");
}
