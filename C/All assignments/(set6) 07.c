#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20

// TODO define a struct called 'person' containing name and age
struct person{
    char name[NAME_LENGTH];
    int age;
};

FILE *open_file(const char *path,char *mode);

// Sort the array of structs alphabetically
void sort_by_name(struct person *people, int size);

// Sort the array of structs by age, lowest to highest
void sort_by_age(struct person *people, int size);

// Find and return the age of a person, given their name
int find_age_of_person(struct person *people, int size, const char *name);

// Find all people older than a given age, and print their names
void print_older_than(struct person *people, int size, int age_threshold);

void print_listan(struct person *people,int size);
int main() {
    
    // TODO declare an array called 'people' to store information 
    struct person people[10];
    // Read the file
    char path[150]="/home/idelbi/Desktop/C_assignments/set6/set6/ex_people/people.txt";
    FILE *f=open_file(path,"r");
    // TODO: Add path to file location!
    // TODO: Store the names and ages of each person in 'people'
    int n=0;
    while(n<10&&fscanf(f,"%s %d",people[n].name,&people[n].age)==2){
        n++;
    }
    printf("Type a name to chech if it is in the list : \n");
    char search_name[50];
    fgets(search_name,50,stdin);
    search_name[strcspn(search_name,"\n")]='\0';
    int age_of = find_age_of_person(people,n,search_name);
    printf("Age of %s is : %d\n",search_name,age_of);

    printf("\nListan innna sort by name: \n");
    print_listan(people,n);
    // TODO: Sort the array 'people' by name alphabetically
    sort_by_name(people, n);
    printf("\nListan efter sort by name func \n");
    print_listan(people,n);
    // TODO: Search for the person 'Elsa' and print her age
    
    // TODO: Resort the array 'people' by age
    sort_by_age(people,n);
    printf("\nlistan efter sort by age\n");
    print_listan(people,n);
    int age_threshold = 30;
    printf("People older than %d:\n", age_threshold);
    // TODO: Print names of people older than the age threshold
    print_older_than(people,n,age_threshold);
    fclose(f);
    return 0;
}

FILE *open_file(const char *path, char *mode){
    FILE *file=fopen(path,mode);
    if(file==NULL){
        printf("Something went wrong. File did not opened ! ! !\n");
        exit(EXIT_FAILURE);
    }
    return file;
}
void sort_by_name(struct person *people, int size) {
    // TODO
    for(int j=0;j<size-1;j++){
        for(int i=0;i<size-1-j;i++){
            if(strcmp(people[i].name,people[i+1].name)>0){
            int age;
            char temp[10];
            strcpy(temp,people[i].name);
            strcpy(people[i].name,people[i+1].name);
            strcpy(people[i+1].name,temp);
            age=people[i].age;
            people[i].age =people[i+1].age;
            people[i+1].age=age;

        }   
    }
    }
    
}
    
    
void sort_by_age(struct person *people, int size) {
    // TODO
    for(int j=0;j<size-1;j++){
        for(int i=0;i<size-1-j;i++){
            int age=0;
            if(people[i].age>people[i+1].age){
                age=people[i].age;
                people[i].age=people[i+1].age;
                people[i+1].age=age;
                char temp[20];
                strcpy(temp,people[i].name);
                strcpy(people[i].name,people[i+1].name);
                strcpy(people[i+1].name,temp);
            }
        }
    }
}

int find_age_of_person(struct person *people, int size, const char *name) {
    // TODO
    for(int i=0;i<size;i++){
        if(strcmp(people[i].name,name)==0){
            return people[i].age;
        }
    }
    return -1;
}

void print_older_than(struct person *people, int size, int age_threshold) {
    // TODO
    for(int i=0;i<size;i++){
        if(people[i].age>age_threshold){
            printf("%s\n", people[i].name);
        }
    }

}
void print_listan(struct person *people,int size){
    for(int i=0;i<size;i++){
        printf("%s %d\n", people[i].name,people[i].age);
    }
    printf("\n");
}
