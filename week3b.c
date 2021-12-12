#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_LENGTH 10
#define NAME_LENGTH 20
typedef struct Student_t {
   char id[ID_LENGTH];
   char name[NAME_LENGTH];
   int grade;
   struct Student_t *next;
} Student;

Student *getStudentInfo() {
   Student *temp = (Student *)malloc(sizeof(Student));
   printf("Student's name:");
   scanf("%s", (*temp).name);
   printf("Student's ID:");
   scanf("%s", (*temp).id);
   printf("Student's grade:");
   scanf("%d", &(*temp).grade);
   printf("%d\n", (*temp).grade);
   temp->next = NULL;
   return temp;
}
void add_student(Student *root, Student *to_add) {
   Student *curr_std, *prev_std = NULL;
   if ((*root).next == NULL) {
      root->next = to_add;
      printf("Add success.\n");
      return;
   }
   curr_std = root->next;
   prev_std = root;
   while (curr_std != NULL && to_add->grade < curr_std->grade) {
      prev_std = curr_std;
      curr_std = curr_std->next;
   }
   prev_std->next = to_add;
   to_add->next = curr_std;
   printf("Add success.\n");
}
Student *find_student(Student *root, char *id) {
   Student *to_search = root;
   while (to_search != NULL) {
      if (strcmp(to_search->id, id) == 0) {
         printf("%s | %s | %d\n", (*to_search).id, (*to_search).name, (*to_search).grade);
         return to_search;
      }
      to_search = to_search->next;
   }
   return NULL;
}

Student *change_grade(Student *root, char *id, int new_grade) {
   Student *std = find_student(root, id);
   (*std).grade = new_grade;
}

void show_all_student(Student *root) {
   Student *temp = root->next;
   while (temp != NULL) {
      printf("%s | %s | %d\n", (*temp).id, (*temp).name, (*temp).grade);
      temp = temp->next;
   }
}
void delete_student(Student *root, char *id) {
   Student *to_delete = root;
   Student *before_student;
   while (to_delete != NULL) {
      if (strcmp(to_delete->id, id) == 0) {
         before_student->next = to_delete->next;
         free(to_delete);
         break;
      }
      before_student = to_delete;
      to_delete = to_delete->next;
   }
}
int main() {
   Student root;
   root.next = NULL;
   Student *tmp;
   while (1) {
      printf("\nSelect Options:\n1. Add student .\n2. Search Student by ID");
      printf("\n3. Remove student\n4. Show all students\n");
      int option;
      char id[ID_LENGTH];
      scanf("%d", &option);
      printf("%c", option);
      switch (option) {
      case 1:
         tmp = getStudentInfo();
         add_student(&root, tmp);
         break;
      case 2:
         printf("Insert ID of student:");
         scanf("%s", id);
         find_student(&root, id);
         break;
      case 3:
         printf("Insert ID of student:");
         scanf("%s", id);
         delete_student(&root, id);
         break;
      case 4:
         show_all_student(&root);
         break;
      }
   }
   return 0;
}
