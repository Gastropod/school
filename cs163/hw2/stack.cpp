#include "header.h"



Stack::Stack(void){
    top = 0;

}

Stack::~Stack(void){

}

int Stack::push(Message & ref_message){
    Message new_message;
    StackNode * new_stack_node;

    // Do a test clone to fail before allocating array
    if (!new_message.clone(ref_message)){
        // Failed to clone the ref_message
        return 0;
    }

    if (!head){
        head = new StackNode;
        head->messages = new Message[SIZE_STACK_ARRAY];
        head->next = NULL;
    } 
    else if (top == SIZE_STACK_ARRAY){
        new_stack_node = new StackNode;
        new_stack_node->next = head;
        head = new_stack_node;
        head->messages = new Message[SIZE_STACK_ARRAY];
        top = 0;
    }
    head->messages[top].clone(new_message);
    ++top;
}

int Stack::peek(Message & ref_message){


    if (!head) return 0;

    // top points to where the next message should go,
    // the most recent message is at top-1
    if(!ref_message.clone(head->messages[top-1])) return 0;

    return 1;
}

int Stack::pop(Message & ref_message){
    StackNode * old_head;

    if(!peek(ref_message)){
        // Use peek to get a ref of the top message
        return 0;
    }

    if (top==1){
        top = SIZE_STACK_ARRAY;
        old_head = head;
        head = old_head->next;
        delete [] old_head->messages;
        delete old_head;
    } else {
        --top;
    }
    
    return 1;
}

int Stack::display(){

}
