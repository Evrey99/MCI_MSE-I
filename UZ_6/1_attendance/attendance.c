#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0
#define DEBUG_PRINT 0
#define DEBUG_PRINT_DETAILS_1 0
#define DEBUG_PRINT_DETAILS_2 0
#define MAX_COURSE_LEN 10
#define STRUCT_LEN 20
#define COURSE_COUNT 4
#define MAX_ROWS 30
#define BUFFER_SIZE 1024

typedef struct {
    char vorname[STRUCT_LEN];
    char nachname[STRUCT_LEN];
    char course[COURSE_COUNT][STRUCT_LEN];
    int time;
} person;

person students[MAX_ROWS];

typedef struct {
    char vorname[STRUCT_LEN];
    char nachname[STRUCT_LEN];
    int start_time;
    int end_time;
} person_time;

person_time student_attendance[MAX_ROWS];

void get_student_data(){

    FILE * datei = fopen("students.txt", "r");
    if (datei == NULL){
        perror("Fehler");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int counter = 0;
    while( (fgets(buffer, sizeof(buffer),datei)!=NULL) && (counter<MAX_ROWS) ){
        
        memset(&students[counter], 0, sizeof(person));
        char buffer2[BUFFER_SIZE];
        char* ptr = buffer2;
        int offset = 0;
        int i = 0;

        sscanf(buffer,\
            "%[^;];%[^;];%[^\n]\n",\
            students[counter].vorname,\
            students[counter].nachname,\
            buffer2);
        while(sscanf(ptr, "%[^,\n],%n",students[counter].course[i],&offset)==1){
            
            #if DEBUG_PRINT_DETAILS_1
            printf("Name: %s %s, Kurs: %s, Offset %d\n", students[counter].vorname, students[counter].nachname, students[counter].course[i], offset);
            #endif

            ptr += offset;
            i++;
        }
        
        counter++;
    }

    fclose (datei);

}

void get_attendance_data(){
    FILE * datei = fopen("webinar.txt", "r");
    if (datei == NULL){
        perror("Fehler");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int counter = 0;
    while( (fgets(buffer, sizeof(buffer),datei)!=NULL) && (counter<MAX_ROWS) ){
        memset(&student_attendance[counter], 0, sizeof(person_time));
        sscanf(buffer,\
            "%[^:]:%[^:]:%d:%d\n",\
            student_attendance[counter].vorname,\
            student_attendance[counter].nachname,\
            &student_attendance[counter].start_time,\
            &student_attendance[counter].end_time);

        #if DEBUG_PRINT_DETAILS_2
        printf("Name: %s %s, Startime %d, Endtime %d\n", student_attendance[counter].vorname,student_attendance[counter].nachname,student_attendance[counter].start_time,student_attendance[counter].end_time);
        #endif
     
        counter++;
    }
    fclose(datei);
}

void find_student_min(int studentid){
    for (int i = 0; i < MAX_ROWS; i++){
        if((strcmp(students[studentid].vorname,student_attendance[i].vorname) == 0) && (strcmp(students[studentid].nachname,student_attendance[i].nachname)==0)){
            students[studentid].time = (student_attendance[i].end_time - student_attendance[i].start_time)/60;
            break;
        }
    }
    
}

void get_attendance_for_course(char *course, int att_time){
    

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int x = 0; x < COURSE_COUNT; x++) {
            if(strcmp(course, students[i].course[x]) == 0){
                find_student_min(i);

                if (students[i].time == 0){
                    printf("%s %s: nicht anwesend\n", students[i].vorname, students[i].nachname);
                }else if(students[i].time < att_time){
                    printf("%s %s: %d Minuten\n", students[i].vorname, students[i].nachname, students[i].time);
                }
                break;
            }
        }
    }
}

int main(int argc, char **argv){

    #if DEBUG //zum Debuggen werden fixe Paramenter übergeben, für die finale Version werden die Kommandozeilenparameter übernommen

        char course[MAX_COURSE_LEN] = "OBWL";
        int minutes = 120;

    #else

        if (argc != 3){
            fprintf(stderr, "Eingabefehler");
            return EXIT_FAILURE;
        }
        
        char * course = argv[1];
        int minutes = atoi(argv[2]);

    #endif

    #if DEBUG_PRINT

        //zum Debuggen, überprüfen, welche eingabeparameter übernommen wurden
        printf("Fach %s, minutes %d\n", course, minutes);

    #endif

    get_student_data();
    get_attendance_data();
    get_attendance_for_course(course, minutes*0.75);

return EXIT_SUCCESS;

}