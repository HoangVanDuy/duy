#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHONE_LENGTH 12
#define NAME_LENGTH 20
#define EMAIL_LENGTH 20
struct phoneAddress {
   struct phoneAddress *next;
   char number[PHONE_LENGTH];
   char name[NAME_LENGTH];
   char email[EMAIL_LENGTH];
};
struct phoneAddress *NUL;
struct phoneAddress *createNewPhoneAddress(struct phoneAddress *current) {
   struct phoneAddress *new;
   new = (struct phoneAddress *)malloc(sizeof(struct phoneAddress));
   new->next = NUL;
   (*current).next = new;
   return new;
}
void removeAllPhoneAddress(struct phoneAddress *root) { (*root).next = NUL; }
void insertPhoneAddress(struct phoneAddress *root) {
   printf("Ban muon nhap bao nhieu so? \n");
   int n;
   scanf("%d", &n);
   struct phoneAddress *temp = root;
   while ((*temp).next != NUL) {
      temp = (*temp).next;
   }
   while (n--) {
      temp = createNewPhoneAddress(temp);
      printf("%x: ", temp);
      char num[PHONE_LENGTH], name[NAME_LENGTH], email[EMAIL_LENGTH];
      printf("Nhap so dien thoai: ");
      scanf("%s", num);
      strcpy((*temp).number, num);
      printf("Nhap ten: ");
      scanf("%s", name);
      strcpy((*temp).name, name);
      printf("Nhap dia chi email: ");
      scanf("%s", email);
      strcpy((*temp).email, email);
   }
}
void showAllPhoneAddress(struct phoneAddress *root) {
   struct phoneAddress *temp = (*root).next;
   while (temp != NUL) {
      printf("%x: ", temp);
      printf("%s  | %s | %s\n", (*temp).name, (*temp).number, (*temp).email);
      temp = (*temp).next;
   }
}

int main() {
   struct phoneAddress root;
   root.next = NUL;
   int n;
   while (1) {
      printf("\nChon chuong trinh:\n1. Nhap danh sach.\n2. In ra danh sach\n 3. Xoa danh sach\n");
      int option;
      scanf("%d", &option);
      switch (option) {
      case 1:
         insertPhoneAddress(&root);
         break;
      case 2:
         showAllPhoneAddress(&root);
         break;
      case 3:
         removeAllPhoneAddress(&root);
         break;
      }
   }
}
