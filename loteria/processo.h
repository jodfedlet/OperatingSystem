#include <stdio.h>
#include <stdlib.h>

struct context{
    uint edi;
    uint esi;
    uint ebx;
    uint ebp;
    uint eip;
};


enum procstate{ UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

//Per - process state
struct proc{
    uint sz;                            //Size of processe memory (bytes)
    pdte_t* pgdir;                      //Page table
    char *kstack;                       //Bottom of Kernel Stack for this process
    enum procstate state;               //Process state
    volatile int pid;                   //Process ID
    struct proc *parent;                //Parent process
    struct trapframe *tf;               //Trap frame for current syscall
    struct context *context;            //switch() here to run process
    void *chan;                         //If non-zero, sleeping on chan
    int killed;                         //If non-zero, have been killed
    struct file *ofile[NOFILE];         //Open files
    struct inode *cwd;                  //Current directory
    char name[16];                      //Process name (debugging)
}