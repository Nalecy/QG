#include <stdio.h>
#include "LinkStack.h"
#include <stdlib.h>
#include <malloc.h>

void printMenu(){
        printf("1、初始化栈\n");
        printf("2、判断栈是否为空\n");
        printf("3、得到栈顶元素\n");
        printf("4、清空栈\n");
        printf("5、销毁栈\n");
        printf("6、检测栈长度\n");
        printf("7、入栈\n");
        printf("8、出栈\n");
}
int main(){


        int c = 0;
        LinkStack* s = NULL;
        ElemType *e = (ElemType*)malloc(sizeof(ElemType));
        int *l = (int*)malloc(4);*l = 0;
        int data;
        int *d = (int*)malloc(4);
        while(1){
                printMenu();
                scanf("%d",&c);

                switch(c){
                case 1:
                        s = (LinkStack*)malloc(sizeof(LinkStack));
                        if(initLStack(s))printf("初始化成功\n");
                        else printf("初始化失败\n");
                        break;
                case 2:
                        if(isEmptyLStack(s))printf("空\n");
                        else printf("不为空\n");
                        break;
                case 3:
                        if(getTopLStack(s,e))printf("栈顶元素为%d\n",*e);
                        else printf("获取失败\n");
                        break;
                case 4:
                        if(clearLStack(s))printf("清空成功\n");
                        else printf("清空失败\n");
                        break;
                case 5:
                        if(destroyLStack(s))printf("销毁成功\n");
                        else printf("销毁失败\n");
                        s = NULL;
                        break;
                case 6:
                        if(LStackLength(s,l))printf("长度：%d\n",*l);
                        else printf("获取长度失败\n");
                        break;
                case 7:
                        printf("请输入想入栈的数：\n");
                        scanf("%d",&data);
                        if(pushLStack(s,data))printf("入栈成功\n");
                        else printf("入栈失败\n");
                        break;
                case 8:
                        if(popLStack(s,d))printf("出栈成功,出栈的值为：%d\n",*d);
                        else printf("出栈失败\n");
                        break;

                default:printf("请检查输入\n");
                }
                system("pause");
                system("cls");
        }
}
