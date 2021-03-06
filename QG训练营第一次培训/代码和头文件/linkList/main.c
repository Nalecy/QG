#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void printData(ElemType e){
        printf(" %d",e);
}
void printMenu(){
        printf("输入你的选择：\n");
        printf("退出\t\t\t0\n");
        printf("初始化链表\t\t1\n");
        printf("销毁链表\t\t2\n");
        printf("插入节点\t\t3\n");
        printf("删除节点\t\t4\n");
        printf("遍历链表\t\t5\n");
        printf("查询节点\t\t6\n");
        printf("反转链表\t\t7\n");
        printf("判断成环\t\t8\n");
        printf("反转偶节点\t\t9\n");
        printf("查询中点值\t\t10\n");
}
LNode* searchNodeByData(LinkedList *L,int data){
        LNode *p1 = *L;
        while(p1 != NULL){
                if(data == p1->data)break;
                p1 = p1->next;
        }
        return p1;
}

int main(){
        int choice;
        LinkedList p = (LinkedList)malloc(sizeof(LNode));
        LinkedList *L = &p;
        p->next = NULL;
        int a3,b3,a4,*e = (ElemType*)malloc(sizeof(ElemType));
        LNode *p3;
        void (*f)(ElemType e)= printData;
        printMenu();
        DestroyList(L);
        while(scanf("%d",&choice)&&choice != 0){
                switch(choice){
                        case 1:if(InitList(L))printf("初始化成功\n");
                                else printf("初始化失败");
                                break;
                        case 2:if((*L) == NULL){printf("请先初始化\n");break;}
                                DestroyList(L);
                                break;
                        case 3:p3 = (LinkedList)malloc(sizeof(LNode));
                                if((*L) == NULL){printf("请先初始化\n");break;}
                                if((*L)->next == NULL){
                                        printf("目前链表为空，请增加值为？的节点");
                                        int a3;
                                        scanf("%d",&a3);
                                        p3->data = a3;
                                        if(InsertList(*L,p3))printf("插入成功\n");
                                        else printf("插入失败");

                                }
                                else{
                                        printf("你想在值为？的节点后面插入？ 请输入值\n");
                                        int a3,b3;
                                        if(searchNodeByData(L,(scanf("%d %d",&a3,&b3),a3))==NULL)printf("请检查输入\n");
                                        else {
                                                p3->data = b3;
                                                p3->next = NULL;
                                                if(InsertList(searchNodeByData(L,a3),p3))printf("插入成功\n");
                                                else printf("插入失败");
                                        }
                                }
                                break;
                        case 4:if((*L) == NULL){printf("请先初始化\n");break;}
                                printf("你想删除在值为？的节点后面的第一个节点 请输入值\n");
                                if(searchNodeByData(L,(scanf("%d",&a4),a4))==NULL)printf("请检查输入");
                                else{
                                        if(DeleteList(searchNodeByData(L,a4),e))printf("删除成功，您删除的节点值为%d\n",*e);
                                        else printf("删除失败");
                                }
                                break;
                        case 5:if((*L) == NULL){printf("请先初始化\n");break;}
                                TraverseList(*L,f);
                                printf("\n");
                                break;
                        case 6:{if((*L) == NULL){printf("请先初始化\n");break;}
                                printf("你想查找是否有值为？的节点 请输入值\n");
                                ElemType e;
                                scanf("%d",&e);
                                if(SearchList(*L, e))printf("存在值为%d节点\n",e);
                                else printf("不存在值为%d节点\n",e);
                                }
                                break;
                        case 7: if((*L) == NULL){printf("请先初始化\n");break;}
                                if(ReverseList(L))printf("反转成功\n");
                                else printf("反转失败");
                                break;
                        case 8:if((*L) == NULL){printf("请先初始化\n");break;}
                                if(IsLoopList(*L))printf("有环\n");
                                else printf("无环\n");
                                break;
                        case 9:if((*L) == NULL){printf("请先初始化\n");break;}
                                if(ReverseEvenList(L))printf("反转成功\n");
                                else printf("反转失败");
                                break;
                        case 10:if((*L) == NULL){printf("请先初始化\n");break;}
                                {
                                LNode* p;
                                if((p = FindMidNode(L))!=NULL)printf("中点值为%d\n",p->data);
                                else printf("查询失败");
                                }
                                break;
                        default:printf("请检查数字\n");
                }
                system("pause");
                system("cls");
                printMenu();
        }
        return 0;
}
