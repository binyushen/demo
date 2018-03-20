// shenbinyu 2018-03-20

#include <stdio.h>
#include <stdlib.h>

#include "hashTable.h"

struct Student {
    int age;
    float score;
    char name[32];
    char data[1024 * 1024 * 10];
};

static void free_student(void *stu) {
    free(stu);
}

static void show_student(struct Student *stu) {
    if(NULL == stu) {
        printf("%s|%d>>NULL == stu\n", __FILE__, __LINE__);
    } else {
        printf("name:%s, age:%d, score:%.2f\n", stu->name, stu->age, stu->score);
    }
}

int main() {
    int i =0;
    char name[32];
    HashTable *ht = hash_table_new();
    struct Student *stu = NULL;
    if(NULL == ht) {
        return -1;
    }
    
    for(i = 0; i < 100; i++) {
        stu = (struct Student *)malloc(sizeof(struct Student));
        stu->age = 18 + rand() % 5;
        stu->score = 50.0f + rand() % 100;
        sprintf(stu->name, "ÐÕÃû%d", i);
        hash_table_put2(ht, stu->name, stu, free_student);
    }
    
    for(i = 0; i <= 100; i++) {
        sprintf(name, "ÐÕÃû%d", i);
        stu = (struct Student *)hash_table_get(ht, name);
        show_student(stu);
    }
    
    hash_table_delete(ht);
    
    return 0;
}
