#include<stdio.h>
#include"SqStack.h"
#include<stdlib.h>
#include<malloc.h>

Status initStack(SqStack *s,int sizes){
        if(s == NULL)return ERROR;
        s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
        s->size = sizes;
        s->top = -1;
        return SUCCESS;
}
        //初始化栈
Status isEmptyStack(SqStack *s){
        if(s->elem == NULL){printf("未初始化无法判定是否为");return SUCCESS;}
        if(s->top == -1)return SUCCESS;
        else return ERROR;
}//判断栈是否为空
Status getTopStack(SqStack *s,ElemType *e){
        if(!(s == NULL&&s->elem == NULL&&s->top == -1))return ERROR;
        *e = s->elem[s->top];
        return SUCCESS;

} //得到栈顶元素
Status clearStack(SqStack *s){
        if(s == NULL||s->elem == NULL)return ERROR;
        s->top = -1;
        return SUCCESS;
}//清空栈
Status destroyStack(SqStack *s){
        ElemType *e = (ElemType*)malloc(sizeof(ElemType));
        if(s == NULL)return ERROR;
        int i;
        for(i = 0;i<s->size;i++){
                e = s->elem;
                free(e);
        }
        s->elem = NULL;
        s->top = -2;
        return SUCCESS;
}//销毁栈
Status stackLength(SqStack *s,int *length){
        if(s == NULL)return ERROR;
        *length = s->top+1;
        return SUCCESS;
}//检测栈长度
Status pushStack(SqStack *s,ElemType data){
        if(s->elem == NULL||s->top == s->size-1)return ERROR;
        s->elem[s->top+1] = data;
        s->top ++;
        return SUCCESS;
}//入栈
Status popStack(SqStack *s,ElemType *data){
        if(s == NULL||s->top == -1)return ERROR;
        *data = s->elem[s->top--];
        return SUCCESS;
}//出栈
