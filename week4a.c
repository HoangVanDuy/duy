#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NameLENGTH 20
#define PhoneLENGTH 12
#define EmailLENGTH 20
typedef struct Address {
   char name[NameLENGTH];
   char telephone_number[PhoneLENGTH];
   char email_address[EmailLENGTH];
   struct Address *next;
} ad;

ad *push(ad *current, char name[], char phoneNumber[], char email[]) {
   ad *temp;
   temp = (ad *)malloc(sizeof(ad));
   strcpy(temp->name, name);
   strcpy(temp->email_address, email);
   strcpy(temp->telephone_number, phoneNumber);
   temp->next = current;
   current = temp;
   return temp;
}

ad pop(ad **current) {
   ad *tmp = *current;
   ad data = **current;
   if (*current == NULL) {
      printf("Stack empty!");
      exit(0);
   }
   *current = (*current)->next;
   // tmp->next = NULL;
   free(tmp);
   return data;
}

ad *root = NULL;
int main() {
   FILE *input = fopen("Address1.txt", "r");
   FILE *output = fopen("Address2.txt", "w");
   int n;
   fscanf(input, "%d", &n);
   for (int i = 0; i < n; i++) {
      char name[NameLENGTH], email[EmailLENGTH], phone[PhoneLENGTH];
      fscanf(input, "%s", name);
      fscanf(input, "%s", phone);
      fscanf(input, "%s", email);
      root = push(root, name, phone, email);
   }

   for (int i = 0; i < n; i++) {
      ad temp = pop(&root);
      char name[NameLENGTH], email[EmailLENGTH], phone[PhoneLENGTH];
      strcpy(name, temp.name);
      strcpy(email, temp.email_address);
      strcpy(phone, temp.telephone_number);
      fprintf(output, "%s\n%s\n%s\n", name, phone, email);
   }
   fclose(input);
   fclose(output);
}
