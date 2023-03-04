#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct patient{
    int id;
    char Name[100];
    char Phone[100];
    char Address[100];
    char disease[100];
    struct patient *next;

    }* head;

struct patient* middle(struct patient* start,struct patient* last)
{
    if (start == NULL)
        return NULL;

    struct patient* slow = start;
    struct patient* fast = start -> next;

    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    return slow;
}

struct patient* search(struct patient *head, int value)
{
    struct patient* start = head;
    struct patient* last = NULL;

    do
    {
       struct patient *mid = middle(start, last);
        if (mid == NULL)
            return NULL;
        if (mid -> id == value)
            return mid;
        else if (mid -> id < value)
            start = mid -> next;
        else
            last = mid;

    } while (last == NULL ||
             last != start);

    return NULL;
}

void insert(int id, char* Name, char* Phone,char* Address,char* disease )
{
struct patient * patient = (struct patient *) malloc(sizeof(struct patient));
    patient->id = id;
    strcpy(patient->Name, Name);
    strcpy(patient->Phone, Phone);
    strcpy(patient->Address, Address);
    strcpy(patient->disease, disease);
    patient->next = NULL;

    if(head==NULL){

        head = patient;

 }
    else{
        patient->next = head;
        head = patient;
    }

}

void update(int id)
{

    struct patient * temp = head;
    while(temp!=NULL){
if(temp->id==id){
            printf("Record with id %d Found !!!\n", id);
            printf("Enter new name: ");
            scanf("%s", temp->Name);
            printf("Enter new phone number: ");
            scanf("%s", temp->Phone);
            printf("Enter new address: ");
            scanf("%s",&temp->Address);
            printf("Enter new disease: ");
            scanf("%s",&temp->disease);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("patient with id number %d is not found !!!\n", id);
}
void Delete(int id)
{
    struct patient * temp1 = head;
    struct patient * temp2 = head;
while(temp1!=NULL){

        if(temp1->id==id){

            printf("Record with id number %d Found !!!\n", id);

            if(temp1==temp2){

                head = head->next;
                free(temp1);
            }
            else{

                temp2->next = temp1->next;
                free(temp1);
}

            printf("Record Successfully Deleted !!!\n");
            return;

 }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("Patient with id number %d is not found !!!\n", id);

}


int  display()
{
    int count=0;
    struct patient * temp = head;
    while(temp!=NULL){

        printf("id: %d\n", temp->id);
        printf("Name: %s\n", temp->Name);
        printf("Phone: %s\n", temp->Phone);
        printf("Address: %s\n", temp->Address);
        printf("disease:%s\n", temp->disease);
        temp = temp->next;
        count++;

    }

return count;

}
void swap(struct patient *a, struct patient *b)
{
    int temp = a->id;
    a->id = b->id;
    b->id = temp;
}


void sorting(int count)
{
      int swapped, i;
     struct patient  *ptr1;
     struct patient *lptr = NULL;


    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->id> ptr1->next->id)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);



     int op=0;
     printf ("\nDo you want sorted information(0/1): ");
     scanf("%d",&op);
    if(op==1)
    {
	display();

    }
}


int main()
{
    head = NULL;
    int choice;
    char Name[100];
    int op;
    char Phone[100];
    int kop;
    char Address[100];
    int p;
    char disease[100];
    int id;

        system("cls");
        printf("<== Hospital Management System ==>\n");
    printf("1  insert patient details\n2  search for patient details\n3  delete patient details\n4  update patient details\n5  display all patient details\n6.sorted data");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter id number: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", Name);
                printf("Enter Phone number: ");
                scanf("%s", Phone);
                printf("Enter Address: ");
                scanf("%s", Address);
                printf("Enter Disease: ");
                scanf("%s", disease);

                insert(id, Name, Phone,Address,disease );
                break;

            case 2:
                printf("id number to search: ");
            scanf("%d", &id);

            if (search(head,id) == NULL)
        printf("Value not present\n");
    else
    {
        struct patient * lol=search(head,id);

        printf("id Number: %d\n", lol->id);
        printf("Name: %s\n", lol->Name);
        printf("Phone: %s\n", lol->Phone);
        printf("Address: %s\n", lol->Address);
        printf("Disease: %s\n", lol->disease);



    }
            break;
            case 3:
                printf("Enter id number to delete: ");
                scanf("%d", &id);
                Delete(id);
                break;

case 4:
                printf("Enter id number to update: ");
                scanf("%d", &id);
                update(id);
                break;
 case 5:
              kop=display();
                break;

case 6:
                    sorting(kop);
                    break;
        }

    } while (choice != 0);
}

