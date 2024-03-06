#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
// ����ģ�Ͷ���
struct bicycle {
    char name[10];
    int id;
    char brand[50];
    char model[50];
    char color[20];
    char phonenumber[15];
};
struct User {
    char username[20];
    char password[20];
    
};

// �ڵ㶨��
struct node {
    struct bicycle data;
    struct node* next;
};
struct Usernode {
    struct User currentUser;
    struct Usernode* next;
};

// ȫ������ͷָ��
struct node* head = NULL;
struct Usernode* headUser = NULL;
// ��������
void loginmenu();//��½�˵�����
void menu();//���˵�����
void addbicycle();//������г���Ϣ
void displaybicycles();//��ʾ���г���Ϣ
void saveFile();//���ݱ��浽�ļ�
void loadfromFile();//���ļ��������ݵ�����
void deletebicycle();//ɾ�����г���Ϣ
void modifybicycle();//�޸����г���Ϣ
void sortbicyclesid();//��id����
void querybicyclesId();//ͨ��id��ѯ
void querybicyclesName();//ͨ��������ѯ
void querybicyclescombination();//��ϲ�ѯ
int countBicycles();//ͳ�����г�����
int login();//�˺ŵ�¼
int registerUser();//�˺�ע��
void saveUserFile();//�˺����ݱ���
int loadUserFromFile();//���ļ������˺�


int main() {
  //���ļ������û�����
    if (loadUserFromFile() == 0) {
        printf("�޷������û����ݡ�\n");
        return 1;
    }

    int loggedIn = 0;

    do {
        printf("\n=== ���г�����ϵͳ ===\n");
        printf("1. ��¼\n");
        printf("2. ע��\n");
        printf("0. �˳�\n");

        int choice;
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loggedIn = login();
                break;
            case 2:
                loggedIn = registerUser();
                break;
            case 0:
                printf("�����˳���\n");
                break;
            default:
                printf("��Ч��ѡ��,������0��2֮������֡�\n");
        }

    } while (!loggedIn);

    // ��¼�ɹ��󣬿��Խ�����������

    // �����û����ݵ��ļ�
    

    loadfromFile();
    int sortChoice;
    int choice;
    do {
        menu();
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addbicycle();
                saveFile() ;
                break;
            case 2:
                displaybicycles();
                break;
            case 3:
                deletebicycle();
                saveFile() ;
                break;
            case 4:
                modifybicycle();
                saveFile() ;
                break;
            case 5:
                querybicyclesId();
        
                break;
            case 6:
                querybicyclesName();
                break;
            case 7:
                querybicyclescombination();
                break;
           case 8: 
        do {
            printf("\n=== ����˵� ===\n");
            printf("1. ��ID��������\n");
            printf("2. ��ID��������\n");
            printf("0. �������˵�\n");

            printf("����������ѡ��: ");

            scanf("%d", &sortChoice);

            switch (sortChoice) {
                 case 1:
                    sortbicyclesid(1);  // ��������
                    displaybicycles();
                    break;
                 case 2:
                    sortbicyclesid(2);  // ��������
                    displaybicycles();
                    break;
                 case 0:
                    break;
                 default:
                    printf("��Ч��ѡ��,������0��2֮������֡�\n");
            }

            } while (sortChoice != 0);
                    break;
           
            case 9:
             printf("���г��������: %d\n", countBicycles());
             system("pause");
             system("cls");
                break;
           
            case 0:
                printf("���˳����г���Ź���ϵͳ");
                break;
            default:
                printf("��Ч��ѡ��,������0��9֮������֡�\n");
        }
    } while (choice != 0);
// �����û����ݵ��ļ�

    saveUserFile();
    return 0;
}
void loginmenu() {
    printf("\n=== ���г�����ϵͳ��¼ ===\n");
    printf("1. ��¼\n");
    printf("2. ע��\n");
    printf("0. �˳�\n");
}

// �����������Ƿ�Ϊ�س���
bool isEnterKey(char key) {
    return key == '\n' || key == '\r';
}

// �����������Ƿ�Ϊ�˸��
bool isBackspaceKey(char key) {
    return key == '\b';
}

// �����������Ƿ�Ϊ�Ʊ��
bool isTabKey(char key) {
    return key == '\t';
}

// ��¼����
int login() {
    char inputUsername[20];
    char inputPassword[20];

    printf("�������û���: ");
    scanf("%s", inputUsername);
    getchar();  // ���Ļ�������ʣ��Ļ��з�

    printf("����������: ");

    int i = 0;
    char ch;
    while (1) {
        ch = getch();  // ʹ��getch���񵥸�����

        if (isEnterKey(ch)) {  // ���ڻس�����ʾ��ĸ�����ַ�
            printf("\n");
            inputPassword[i] = '\0';  // ������ĩβ���Ͽ��ַ�
            break;
        } else if (isBackspaceKey(ch)) {
            if (i > 0) {
                printf("\b \b");  // �����ˡ�����һ���ַ����ٴι�����
                i--;
            }
        } else if (isTabKey(ch)) {
            printf("\t");  // ��ʾ�Ʊ��
        } else {
            printf("*");  // ��ʾ�������������ַ�
            inputPassword[i++] = ch;
        }
    }

    struct Usernode* currentUser = headUser;

    while (currentUser != NULL) {
        if (strcmp(inputUsername, currentUser->currentUser.username) == 0 &&
            strcmp(inputPassword, currentUser->currentUser.password) == 0) {
            printf("\n��¼�ɹ�!\n");
            return 1;  // ��¼�ɹ�����1
        }
        currentUser = currentUser->next;
    }

    printf("\n��¼ʧ��,�û���: %s, ����: %s��\n", inputUsername, inputPassword);
    return 0;  // ��¼ʧ�ܷ���0
}

// ע�ắ��
int registerUser() {
    char newUsername[20];
    char newPassword[20];

    printf("���������û���: ");
    scanf("%s", newUsername);
    getchar();
    printf("������������: ");
    int i = 0;
    char ch;
    while (1) {
        ch = getch();  // ʹ��getch���񵥸�����

        if (isEnterKey(ch)) {  // ���ڻس�����ʾ��ĸ�����ַ�
            printf("\n");
            newPassword[i] = '\0';  // ������ĩβ���Ͽ��ַ�
            break;
        } else if (isBackspaceKey(ch)) {
            if (i > 0) {
                printf("\b \b");  // �����ˡ�����һ���ַ����ٴι�����
                i--;
            }
        } else if (isTabKey(ch)) {
            printf("\t");  // ��ʾ�Ʊ��
        } else {
            printf("*");  // ��ʾ�������������ַ�
            newPassword[i++] = ch;
        }
    }

    printf("ע��ɹ�!\n");

    struct Usernode* newUsernode = (struct Usernode*)malloc(sizeof(struct Usernode));
    strcpy(newUsernode->currentUser.username, newUsername);
    strcpy(newUsernode->currentUser.password, newPassword);
    newUsernode->next = headUser;
    headUser = newUsernode;

    saveUserFile();
    return 1;  // ע��ɹ�����1
}

void saveUserFile() {
    FILE* file = fopen("user.txt", "w");
    if (file == NULL) {
        printf("�޷������û����ݵ��ļ���\n");
        return;
    }

    struct Usernode* currentUser = headUser;

    while (currentUser != NULL) {
        fprintf(file, "%s %s\n", currentUser->currentUser.username, currentUser->currentUser.password);
        currentUser = currentUser->next;
    }

    fclose(file);
}

int loadUserFromFile() {
    FILE* file = fopen("user.txt", "r");
    if (file == NULL) {
        return 0;  // �޷������û�����
    }

    while (!feof(file)) {
        struct Usernode* newUsernode = (struct Usernode*)malloc(sizeof(struct Usernode));
        if (fscanf(file, "%s %s", newUsernode->currentUser.username, newUsernode->currentUser.password) == 2) {
            newUsernode->next = headUser;
            headUser = newUsernode;
        }
    }

    fclose(file);
    return 1;  // �����û����ݳɹ�
}

void menu() {
    printf("\n=== ���г���Ź���ϵͳ ===\n");
    printf("1. ������г���Ϣ\n");
    printf("2. ��ʾ���г���Ϣ\n");
    printf("3. ɾ�����г���Ϣ\n");
    printf("4. �޸����г���Ϣ\n");
    printf("5. ��ID��ѯ���г���Ϣ\n");
    printf("6. ��������ѯ���г���Ϣ\n");
    printf("7. ��ϲ�ѯ���г���Ϣ\n");
    printf("8. ��ID����\n");
    printf("9. ͳ�ƴ�ų�������\n");
    printf("0. �˳�\n");
}

void addbicycle() {
    int number ;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("���������г���������: ");
    scanf("%s", newnode->data.name);
 again:   printf("��������λ���г�ID: ");
    scanf("%d", &number);
    if(number<99999||number>999999){
        printf("�������,��������ȷ����λid\n");
        goto again;
    }
    struct node* current = head;
    while (current != NULL)
    { 
        if(current->data.id==number)
        {
            printf("id�Ѿ�����,������������\n");
            goto again;
        }
        current = current->next;
    }
    newnode->data.id=number;
    
    printf("������Ʒ��: ");
    scanf("%s", newnode->data.brand);
    printf("�������ͺ�: ");
    scanf("%s", newnode->data.model);
    printf("��������ɫ: ");
    scanf("%s", newnode->data.color);
    printf("������绰����: ");
    scanf("%s", newnode->data.phonenumber);

    newnode->next = head;
    head = newnode;

    printf("���г���Ϣ��ӳɹ���\n");
     system("pause");
    system("cls");
}

void displaybicycles() {
    struct node* current = head;
    if (current == NULL) {
        printf("δ�ҵ����г���Ϣ��\n");
        return;
         system("pause");
    system("cls");
    }

    printf("\n���г���Ϣ�б�:\n");
     printf("����\tID\tƷ��\t�ͺ�\t��ɫ\t�绰����\n");
    while (current != NULL) {
         printf("%s\t%d\t%s\t%s\t%s\t%s\n", current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        current = current->next;
    }
     system("pause");
    system("cls");
}

void saveFile() {
    FILE* file = fopen("bicycles.txt", "w");
    if (file == NULL) {
        printf("���ļ�ʧ�ܡ�\n");
        return;
    }

    struct node* current = head;
    while (current != NULL) {
        fprintf(file, "%s %d %s %s %s %s\n",current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        current = current->next;
    }

    fclose(file);
    printf("���ݱ���ɹ���\n");
     system("pause");
    system("cls");
}

void loadfromFile() {
    FILE* file = fopen("bicycles.txt", "r");
    if (file == NULL) {
        printf("δ�ҵ����е������ļ���\n");
        return;
    }

    while (!feof(file)) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (fscanf(file, "%s %d %s %s %s %s", newnode->data.name, &newnode->data.id, newnode->data.brand, newnode->data.model, newnode->data.color, newnode->data.phonenumber) == 6) {
            newnode->next = head;
            head = newnode;
        }
    }

    fclose(file);
    printf("���ݼ��سɹ���\n");
    
    system("cls");
}

void deletebicycle() {
    int needid;
    printf("������Ҫɾ�������г�ID: ");
    scanf("%d", &needid);

    struct node* current = head;
    struct node* prev = NULL;

    while (current != NULL && current->data.id != needid) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("δ�ҵ����г���Ϣ��\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("���г���Ϣɾ���ɹ���\n");
     system("pause");
    system("cls");
}

void modifybicycle() {
    int needId;
    printf("������Ҫ�޸ĵ����г�ID: ");
    scanf("%d", &needId);

    struct node* current = head;

    while (current != NULL && current->data.id != needId) {
        current = current->next;
    }

    if (current == NULL) {
        printf("δ�ҵ����г���Ϣ��\n");
        return;
    }
    printf("���������г���������: ");
    scanf("%s", current->data.name);
    printf("�������µ�Ʒ��: ");
    scanf("%s", current->data.brand);
    printf("�������µ��ͺ�: ");
    scanf("%s", current->data.model);
    printf("�������µ���ɫ: ");
    scanf("%s", current->data.color);
    printf("�������µĵ绰����: ");
    scanf("%s", current->data.phonenumber);

    printf("���г���Ϣ�޸ĳɹ���\n");
     system("pause");
    system("cls");
}

void sortbicyclesid(int sortOrder){
    if (head == NULL || head->next == NULL) {
        return;  // ����Ϊ�ջ�ֻ��һ��Ԫ�أ���������
    }

    struct node* current = head;
    //struct node* prev = NULL;

    while (current != NULL) {
        struct node* temp = current->next;

        while (temp != NULL) {
            bool swapNeeded = (sortOrder == 1 && current->data.id > temp->data.id) ||
                               (sortOrder == 2 && current->data.id < temp->data.id);

            if (swapNeeded) {
                // �����ڵ�����
                struct bicycle tempData = current->data;
                current->data = temp->data;
                temp->data = tempData;
            }

            temp = temp->next;
        }

        current = current->next;
    }
             system("pause");
             system("cls");
}



void querybicyclesId() {
    int needId;
    printf("������Ҫ��ѯ�����г�ID: ");
    scanf("%d", &needId);

    struct node* current = head;
    int found = 0;

    printf("\n��ѯ���:\n");
    printf("����\tID\tƷ��\t�ͺ�\t��ɫ\t�绰����\n");

    while (current != NULL) {
        if (current->data.id == needId) {
            found = 1;
            printf("%s\t%d\t%s\t%s\t%s\t%s\n", current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        }
        current = current->next;
    }

    if (!found) {
        printf("δ�ҵ��������������г���Ϣ��\n");
    }
     system("pause");
    system("cls");
}

void querybicyclesName() {
    char needName[10];
    printf("������Ҫ��ѯ�����г���������: ");
    scanf("%s", needName);

    struct node* current = head;
    int found = 0;

    printf("\n��ѯ���:\n");
    printf("����\tID\tƷ��\t�ͺ�\t��ɫ\t�绰����\n");

    while (current != NULL) {
        if (strcmp(current->data.name, needName) == 0) {
            found = 1;
             printf("%s\t%d\t%s\t%s\t%s\t%s\n", current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        }
        current = current->next;
    }

    if (!found) {
        printf("δ�ҵ��������������г���Ϣ��\n");
    }
     system("pause");
    system("cls");
}

void querybicyclescombination() {
    int needId;
    char needName[50];

    printf("������Ҫ��ѯ�����г�ID: ");
    scanf("%d", &needId);

    printf("������Ҫ��ѯ�����г���������: ");
    scanf("%s", needName);

    struct node* current = head;
    int found = 0;

    printf("\n��ѯ���:\n");
    printf("����\tID\tƷ��\t�ͺ�\t��ɫ\t�绰����\n");

    while (current != NULL) {
        if (current->data.id == needId && strcmp(current->data.name, needName) == 0) {
            found = 1;
             printf("%s\t%d\t%s\t%s\t%s\t%s\n", current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        }
        current = current->next;
    }

    if (!found) {
        printf("δ�ҵ��������������г���Ϣ��\n");
    }
    system("pause");
    system("cls");

}
int countBicycles() {
    int count = 0;
    struct node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;

}