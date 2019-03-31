#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s){

        //s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(s == NULL)return ERROR;
	s->count = -1;
	s->top = NULL;
	return SUCCESS;
}   //初始化

Status isEmptyLStack(LinkStack *s){
        if(s == NULL){printf("未初始化无法判定是否为");return SUCCESS;}
        if(s->count == -1)return SUCCESS;
        return ERROR;
}  //判断链栈是否为空

Status getTopLStack(LinkStack *s,ElemType *e){
        if(!(s != NULL&&s->top != NULL))return ERROR;
        *e = s->top->data;
        return SUCCESS;
}  //得到栈顶元素

Status clearLStack(LinkStack *s){
        if(!(s == NULL))return ERROR;
        s->count = -1;
        return SUCCESS;
}   //清空栈


Status destroyLStack(LinkStack *s){
        if(s == NULL)return ERROR;
        /*LinkStackPtr p = s->top;
        while(p!=NULL){
                p=p->next;
                free(s->top);
                s->top = p;
        }*/
        free(s);
        return SUCCESS;
}   //销毁栈

Status LStackLength(LinkStack *s,int *length){
        if(s == NULL)return ERROR;
        *length = s->count+1;
        return SUCCESS;
}    //检测栈长度

Status pushLStack(LinkStack *s,ElemType data){
        if(s == NULL)return ERROR;
        LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
        s->count += 1;
        p->data = data;
        p->next = s->top;
        s->top = p;
        return SUCCESS;

}   //入栈

Status popLStack(LinkStack *s,ElemType *data)
{
        if(s == NULL||s->top == NULL)return ERROR;
        *data = s->top->data;
        LinkStackPtr p = s->top;
        s->top = p->next;
        free(p);
        s->count--;
        return SUCCESS;
}   //出栈
