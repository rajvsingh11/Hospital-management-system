// Mini project by Raj V. Singh (BTech CSE 2nd yr.)

#include<stdio.h>
#include<stdlib.h>

struct patient{
    int id;
    char patientName[50];
    char patientAddress[50];
    char disease[50];
    char date[12];
}p;

struct doctor{
    int id;
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
}d;

FILE *fp;

void admitPatient();
void patientList();
void dischargePatient();
void addDoctor();
void doctorList();

int main(){

    int ch;

    while(1){
        system("cls");
        printf("WELCOME...!\n");
        printf("\n");
        printf("**** Hospital Management System ****\n\n");
        printf("1.Admit Patient\n");
        printf("2.Patient List\n");
        printf("3.Discharge Patient\n");
        printf("4.Add Doctor\n");
        printf("5.Doctors List\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            admitPatient(); //CALLING MODULE 1
            break;

        case 2:
            patientList();  //CALLING MODULE 2
            break;

        case 3:
            dischargePatient();  //CALLING MODULE 3
            break;

        case 4:
            addDoctor();  //CALLING MODULE 4
            break;

        case 5:
            doctorList();  //CALLING MODULE 5
            break;

        default:
            printf("Invalid Choice...!!\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
        getch();
    }

    return 0;
}

void admitPatient()  //MODULE 1
{

    fp = fopen("patient.txt", "ab");

    printf("Enter Patient id: ");
    scanf("%d", &p.id);

    printf("Enter Patient name: ");
    fflush(stdin);
    gets(p.patientName);

    printf("Enter Patient Address: ");
    fflush(stdin);
    gets(p.patientAddress);

    printf("Enter Patient Disease: ");
    fflush(stdin);
    gets(p.disease);
    
    printf("Enter Date of Admission: ");
    fflush(stdin);
    gets(p.date);

    printf("\nPatient Added Successfully....!!");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void patientList() //MODULE 2
{

    system("cls");
    printf("**** Patient List ****\n\n");
    printf("%-10s %-30s %-30s %-20s %s\n", "Id", "Patient Name", "Address", "Disease", "Date");
    printf("----------------------------------------------------------------------------------------------------------\n");

    fp = fopen("patient.txt", "rb");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-10d %-30s %-30s %-20s %s\n", p.id, p.patientName, p.patientAddress, p.disease, p.date);
    }

    fclose(fp);
}


void dischargePatient() //MODULE 3
{
	    int id, f=0;
    system("cls");
    printf("**** Discharge Patient ****\n\n");
    printf("Enter Patient id to discharge: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.id){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nPatient Discharged Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");

}

void addDoctor()  //MODULE 4
{
    int f=0;

    system("cls");
    printf("**** Add Doctor ****\n\n");

    fp = fopen("doctor.txt", "ab");

    printf("Enter Doctor's id: ");
    scanf("%d", &d.id);

    printf("Enter Doctor's Name: ");
    fflush(stdin);
    gets(d.name);

    printf("Enter Doctor's Address: ");
    fflush(stdin);
    gets(d.address);

    printf("Doctor Specialize in: ");
    fflush(stdin);
    gets(d.specialize);
    
    printf("Date: ");
    fflush(stdin);
    gets(d.date);

    printf("Doctor Added Successfully\n\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}



void doctorList()  //MODULE 5
{
    system("cls");
    printf("**** Doctor List ****\n\n");

    printf("%-10s %-30s %-30s %-30s %s\n", "id", "Name", "Address", "Specialize","Date");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("doctor.txt", "rb");
    while(fread(&d, sizeof(d), 1, fp) == 1){
        printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.name, d.address, d.specialize, d.date);
    }

    fclose(fp);
}
