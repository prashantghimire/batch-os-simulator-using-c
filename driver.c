#include <stdio.h>
#include <dirent.h> 
#include <string.h>
#include <stdlib.h>

void printJobs();
void doAllJobs();

int main()
{
	int choice;
	char path[30] = "jobs/";
	char program[30];
	do{
		printf("----------------------\nEnter a choice: \n");
		printf("[1] - List jobs\n[2] - Set jobs directory (Ex. sample_path/)\n[3] - Compile and run specific program\n[4] - Shutdown\n[5] - List program options\n[6] - help\n[7] - Perform all jobs!\n----------------------\n");
		scanf("%d", &choice);
		
		if(choice == 1){
			printf("Listing jobs ....\n");
			printf("Current jobs path: %s\n", path);
			printJobs(path);
		}
		else if(choice == 2){
			printf("Setting jobs directory ....\n");
			printf("Enter a job path: ");
			scanf("%s", path);
			printf("New jobs path: %s\n", path);
		}
		else if(choice == 3){
			printf("Compiling and running program ....\nEnter a program to run: ");
			scanf("%s", program);
			char run[50];
			char out[50];
			strcpy(run, "gcc -o");
			strcat(run, path);	
			strcat(run, program);
			strcat(run, ".out ");
			strcat(run, path);
			strcat(run, program);
			system(run);

			strcpy(out, path);
			strcat(out, program);
			strcat(out, ".out");

			system(run);
			printf("Job output: \n");
			system(out);
			printf("Job done!!\n\n");
		}
		else if(choice == 4){
			printf("Shutting down ....\n");
			choice = 0;
		}
		else if(choice == 5){
			printf("Listing program options ....\n");
		}
		else if(choice == 6){
			printf("Loading help ....\n");
			printf("Welcome to Batch OS simulator Program .... \n Hit:\n - 1 to list all the jobs\n - 2 to set jobs directory\n - 3 to compile and run specific program in current job path\n - 4 to shutdown the program\n - 5 to list program options\n - 6 to open help menu\n - 7 to perform all jobs\n");
			printf("\n");
		} else if(choice == 7){
			printf("\ndoing all jobs...\n");
			doAllJobs(path);
		}
		else{
			printf("Nothing that matches!\n");
		}
	} while(choice != 0);
	return(0);
}

void printJobs(char * path){
	DIR *d;
	struct dirent *dir;
	d = opendir(path);
	if (d){
		while ((dir = readdir(d)) != NULL){
			char * file = dir->d_name;
			if(strstr(file, ".c") != NULL){
				printf("%s\n", file);
			}
		}
		closedir(d);
	}
}

void doAllJobs(char * path){
	DIR *d;
	struct dirent *dir;
	d = opendir(path);
	if (d){
		while ((dir = readdir(d)) != NULL){
			char * file = dir->d_name;


			char *e;
			int index;
			e = strchr(file, '.');
			index = (int)(e - file);
			int len = strlen(file);
			int pos = len - index;

			if(pos == 2 && strstr(file, ".c") != NULL){
				printf("Running : %s\n", file);
				
				char run[50];
				char out[50];

				strcpy(run, "gcc -o");
				strcat(run, path);
				strcat(run, file);
				strcat(run, ".out ");
				strcat(run, path);
				strcat(run, file);
				system(run);

				strcpy(out, path);
				strcat(out, file);
				strcat(out, ".out");

				system(run);
				system(out);
				printf("\n----------------------\n");
				sleep(1);

			}
		}
		printf("All jobs in the batch are done!\n");
		closedir(d);
	}
}