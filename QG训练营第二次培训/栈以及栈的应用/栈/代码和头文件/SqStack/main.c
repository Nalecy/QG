#include <stdio.h>
#include "SqStack.h"
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


        int c = 0,size = 0;
        SqStack* s = (SqStack*)malloc(sizeof(SqStack));
        s->elem = NULL;
        ElemType *e = (ElemType*)malloc(sizeof(ElemType));
        int *l = (int*)malloc(4);*l = 0;
        int data;
        int *d = (int*)malloc(4);
        while(1){
                printMenu();
                scanf("%d",&c);

                switch(c){
                case 1:
                        printf("请输入长度：");
                        scanf("%d",&size);
                        if(initStack(s,size))printf("初始化成功\n");
                        else printf("初始化失败\n");
                        break;
                case 2:
                        if(isEmptyStack(s))printf("空\n");
                        else printf("不为空\n");
                        break;
                case 3:
                        if(getTopStack(s,e))printf("栈顶元素为%d\n",*e);
                        else printf("获取失败\n");
                        break;
                case 4:
                        if(clearStack(s))printf("清空成功\n");
                        else printf("清空失败\n");
                        break;
                case 5:
                        if(destroyStack(s))printf("销毁成功\n");
                        else printf("销毁失败\n");
                        break;
                case 6:
                        if(stackLength(s,l))printf("长度：%d\n",*l);
                        else printf("获取长度失败\n");
                        break;
                case 7:
                        printf("请输入想入栈的数：\n");
                        scanf("%d",&data);
                        if(pushStack(s,data))printf("入栈成功\n");
                        else printf("入栈失败\n");
                        break;
                case 8:
                        if(popStack(s,d))printf("出栈成功,出栈的值为：%d\n",*d);
                        else printf("出栈失败\n");
                        break;

                default:printf("请检查输入\n");
                }
                system("pause");
                system("cls");
        }
}
