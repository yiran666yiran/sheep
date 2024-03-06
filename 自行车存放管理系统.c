#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
// 数据模型定义
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

// 节点定义
struct node {
    struct bicycle data;
    struct node* next;
};
struct Usernode {
    struct User currentUser;
    struct Usernode* next;
};

// 全局链表头指针
struct node* head = NULL;
struct Usernode* headUser = NULL;
// 函数声明
void loginmenu();//登陆菜单界面
void menu();//主菜单界面
void addbicycle();//添加自行车信息
void displaybicycles();//显示自行车信息
void saveFile();//数据保存到文件
void loadfromFile();//从文件加载数据到链表
void deletebicycle();//删除自行车信息
void modifybicycle();//修改自行车信息
void sortbicyclesid();//对id排序
void querybicyclesId();//通过id查询
void querybicyclesName();//通过姓名查询
void querybicyclescombination();//组合查询
int countBicycles();//统计自行车数量
int login();//账号登录
int registerUser();//账号注册
void saveUserFile();//账号数据保存
int loadUserFromFile();//从文件加载账号


int main() {
  //从文件加载用户数据
    if (loadUserFromFile() == 0) {
        printf("无法加载用户数据。\n");
        return 1;
    }

    int loggedIn = 0;

    do {
        printf("\n=== 自行车管理系统 ===\n");
        printf("1. 登录\n");
        printf("2. 注册\n");
        printf("0. 退出\n");

        int choice;
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loggedIn = login();
                break;
            case 2:
                loggedIn = registerUser();
                break;
            case 0:
                printf("程序退出。\n");
                break;
            default:
                printf("无效的选择,请输入0到2之间的数字。\n");
        }

    } while (!loggedIn);

    // 登录成功后，可以进行其他操作

    // 保存用户数据到文件
    

    loadfromFile();
    int sortChoice;
    int choice;
    do {
        menu();
        printf("请输入您的选择: ");
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
            printf("\n=== 排序菜单 ===\n");
            printf("1. 按ID升序排序\n");
            printf("2. 按ID降序排序\n");
            printf("0. 返回主菜单\n");

            printf("请输入您的选择: ");

            scanf("%d", &sortChoice);

            switch (sortChoice) {
                 case 1:
                    sortbicyclesid(1);  // 升序排序
                    displaybicycles();
                    break;
                 case 2:
                    sortbicyclesid(2);  // 降序排序
                    displaybicycles();
                    break;
                 case 0:
                    break;
                 default:
                    printf("无效的选择,请输入0到2之间的数字。\n");
            }

            } while (sortChoice != 0);
                    break;
           
            case 9:
             printf("自行车存放数量: %d\n", countBicycles());
             system("pause");
             system("cls");
                break;
           
            case 0:
                printf("已退出自行车存放管理系统");
                break;
            default:
                printf("无效的选择,请输入0到9之间的数字。\n");
        }
    } while (choice != 0);
// 保存用户数据到文件

    saveUserFile();
    return 0;
}
void loginmenu() {
    printf("\n=== 自行车管理系统登录 ===\n");
    printf("1. 登录\n");
    printf("2. 注册\n");
    printf("0. 退出\n");
}

// 函数：检查键是否为回车键
bool isEnterKey(char key) {
    return key == '\n' || key == '\r';
}

// 函数：检查键是否为退格键
bool isBackspaceKey(char key) {
    return key == '\b';
}

// 函数：检查键是否为制表键
bool isTabKey(char key) {
    return key == '\t';
}

// 登录函数
int login() {
    char inputUsername[20];
    char inputPassword[20];

    printf("请输入用户名: ");
    scanf("%s", inputUsername);
    getchar();  // 消耗缓冲区中剩余的换行符

    printf("请输入密码: ");

    int i = 0;
    char ch;
    while (1) {
        ch = getch();  // 使用getch捕获单个按键

        if (isEnterKey(ch)) {  // 对于回车键显示字母数字字符
            printf("\n");
            inputPassword[i] = '\0';  // 在密码末尾加上空字符
            break;
        } else if (isBackspaceKey(ch)) {
            if (i > 0) {
                printf("\b \b");  // 光标回退、擦除一个字符、再次光标回退
                i--;
            }
        } else if (isTabKey(ch)) {
            printf("\t");  // 显示制表键
        } else {
            printf("*");  // 显示其他键的掩码字符
            inputPassword[i++] = ch;
        }
    }

    struct Usernode* currentUser = headUser;

    while (currentUser != NULL) {
        if (strcmp(inputUsername, currentUser->currentUser.username) == 0 &&
            strcmp(inputPassword, currentUser->currentUser.password) == 0) {
            printf("\n登录成功!\n");
            return 1;  // 登录成功返回1
        }
        currentUser = currentUser->next;
    }

    printf("\n登录失败,用户名: %s, 密码: %s。\n", inputUsername, inputPassword);
    return 0;  // 登录失败返回0
}

// 注册函数
int registerUser() {
    char newUsername[20];
    char newPassword[20];

    printf("请输入新用户名: ");
    scanf("%s", newUsername);
    getchar();
    printf("请输入新密码: ");
    int i = 0;
    char ch;
    while (1) {
        ch = getch();  // 使用getch捕获单个按键

        if (isEnterKey(ch)) {  // 对于回车键显示字母数字字符
            printf("\n");
            newPassword[i] = '\0';  // 在密码末尾加上空字符
            break;
        } else if (isBackspaceKey(ch)) {
            if (i > 0) {
                printf("\b \b");  // 光标回退、擦除一个字符、再次光标回退
                i--;
            }
        } else if (isTabKey(ch)) {
            printf("\t");  // 显示制表键
        } else {
            printf("*");  // 显示其他键的掩码字符
            newPassword[i++] = ch;
        }
    }

    printf("注册成功!\n");

    struct Usernode* newUsernode = (struct Usernode*)malloc(sizeof(struct Usernode));
    strcpy(newUsernode->currentUser.username, newUsername);
    strcpy(newUsernode->currentUser.password, newPassword);
    newUsernode->next = headUser;
    headUser = newUsernode;

    saveUserFile();
    return 1;  // 注册成功返回1
}

void saveUserFile() {
    FILE* file = fopen("user.txt", "w");
    if (file == NULL) {
        printf("无法保存用户数据到文件。\n");
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
        return 0;  // 无法加载用户数据
    }

    while (!feof(file)) {
        struct Usernode* newUsernode = (struct Usernode*)malloc(sizeof(struct Usernode));
        if (fscanf(file, "%s %s", newUsernode->currentUser.username, newUsernode->currentUser.password) == 2) {
            newUsernode->next = headUser;
            headUser = newUsernode;
        }
    }

    fclose(file);
    return 1;  // 加载用户数据成功
}

void menu() {
    printf("\n=== 自行车存放管理系统 ===\n");
    printf("1. 添加自行车信息\n");
    printf("2. 显示自行车信息\n");
    printf("3. 删除自行车信息\n");
    printf("4. 修改自行车信息\n");
    printf("5. 按ID查询自行车信息\n");
    printf("6. 按姓名查询自行车信息\n");
    printf("7. 组合查询自行车信息\n");
    printf("8. 按ID排序\n");
    printf("9. 统计存放车的数量\n");
    printf("0. 退出\n");
}

void addbicycle() {
    int number ;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("请输入自行车车主姓名: ");
    scanf("%s", newnode->data.name);
 again:   printf("请输入六位自行车ID: ");
    scanf("%d", &number);
    if(number<99999||number>999999){
        printf("输入错误,请输入正确地六位id\n");
        goto again;
    }
    struct node* current = head;
    while (current != NULL)
    { 
        if(current->data.id==number)
        {
            printf("id已经存在,请你重新输入\n");
            goto again;
        }
        current = current->next;
    }
    newnode->data.id=number;
    
    printf("请输入品牌: ");
    scanf("%s", newnode->data.brand);
    printf("请输入型号: ");
    scanf("%s", newnode->data.model);
    printf("请输入颜色: ");
    scanf("%s", newnode->data.color);
    printf("请输入电话号码: ");
    scanf("%s", newnode->data.phonenumber);

    newnode->next = head;
    head = newnode;

    printf("自行车信息添加成功！\n");
     system("pause");
    system("cls");
}

void displaybicycles() {
    struct node* current = head;
    if (current == NULL) {
        printf("未找到自行车信息。\n");
        return;
         system("pause");
    system("cls");
    }

    printf("\n自行车信息列表:\n");
     printf("姓名\tID\t品牌\t型号\t颜色\t电话号码\n");
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
        printf("打开文件失败。\n");
        return;
    }

    struct node* current = head;
    while (current != NULL) {
        fprintf(file, "%s %d %s %s %s %s\n",current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        current = current->next;
    }

    fclose(file);
    printf("数据保存成功！\n");
     system("pause");
    system("cls");
}

void loadfromFile() {
    FILE* file = fopen("bicycles.txt", "r");
    if (file == NULL) {
        printf("未找到现有的数据文件。\n");
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
    printf("数据加载成功！\n");
    
    system("cls");
}

void deletebicycle() {
    int needid;
    printf("请输入要删除的自行车ID: ");
    scanf("%d", &needid);

    struct node* current = head;
    struct node* prev = NULL;

    while (current != NULL && current->data.id != needid) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("未找到自行车信息。\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("自行车信息删除成功！\n");
     system("pause");
    system("cls");
}

void modifybicycle() {
    int needId;
    printf("请输入要修改的自行车ID: ");
    scanf("%d", &needId);

    struct node* current = head;

    while (current != NULL && current->data.id != needId) {
        current = current->next;
    }

    if (current == NULL) {
        printf("未找到自行车信息。\n");
        return;
    }
    printf("请输入自行车车主姓名: ");
    scanf("%s", current->data.name);
    printf("请输入新的品牌: ");
    scanf("%s", current->data.brand);
    printf("请输入新的型号: ");
    scanf("%s", current->data.model);
    printf("请输入新的颜色: ");
    scanf("%s", current->data.color);
    printf("请输入新的电话号码: ");
    scanf("%s", current->data.phonenumber);

    printf("自行车信息修改成功！\n");
     system("pause");
    system("cls");
}

void sortbicyclesid(int sortOrder){
    if (head == NULL || head->next == NULL) {
        return;  // 链表为空或只有一个元素，无需排序
    }

    struct node* current = head;
    //struct node* prev = NULL;

    while (current != NULL) {
        struct node* temp = current->next;

        while (temp != NULL) {
            bool swapNeeded = (sortOrder == 1 && current->data.id > temp->data.id) ||
                               (sortOrder == 2 && current->data.id < temp->data.id);

            if (swapNeeded) {
                // 交换节点数据
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
    printf("请输入要查询的自行车ID: ");
    scanf("%d", &needId);

    struct node* current = head;
    int found = 0;

    printf("\n查询结果:\n");
    printf("姓名\tID\t品牌\t型号\t颜色\t电话号码\n");

    while (current != NULL) {
        if (current->data.id == needId) {
            found = 1;
            printf("%s\t%d\t%s\t%s\t%s\t%s\n", current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        }
        current = current->next;
    }

    if (!found) {
        printf("未找到符合条件的自行车信息。\n");
    }
     system("pause");
    system("cls");
}

void querybicyclesName() {
    char needName[10];
    printf("请输入要查询的自行车车主姓名: ");
    scanf("%s", needName);

    struct node* current = head;
    int found = 0;

    printf("\n查询结果:\n");
    printf("姓名\tID\t品牌\t型号\t颜色\t电话号码\n");

    while (current != NULL) {
        if (strcmp(current->data.name, needName) == 0) {
            found = 1;
             printf("%s\t%d\t%s\t%s\t%s\t%s\n", current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        }
        current = current->next;
    }

    if (!found) {
        printf("未找到符合条件的自行车信息。\n");
    }
     system("pause");
    system("cls");
}

void querybicyclescombination() {
    int needId;
    char needName[50];

    printf("请输入要查询的自行车ID: ");
    scanf("%d", &needId);

    printf("请输入要查询的自行车车主姓名: ");
    scanf("%s", needName);

    struct node* current = head;
    int found = 0;

    printf("\n查询结果:\n");
    printf("姓名\tID\t品牌\t型号\t颜色\t电话号码\n");

    while (current != NULL) {
        if (current->data.id == needId && strcmp(current->data.name, needName) == 0) {
            found = 1;
             printf("%s\t%d\t%s\t%s\t%s\t%s\n", current->data.name, current->data.id, current->data.brand, current->data.model, current->data.color, current->data.phonenumber);
        }
        current = current->next;
    }

    if (!found) {
        printf("未找到符合条件的自行车信息。\n");
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