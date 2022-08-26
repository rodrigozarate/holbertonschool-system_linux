#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/user.h>
#include <stdio.h>
#include "syscalls.h"

/**
 * printParams - prints params
 * @regs: pointer
 * Return: 0, 1
 */
void printParams(struct user_regs_struct *regs)
{
	size_t i;
	unsigned long param;
	syscall_t syscall = syscalls_64[regs->orig_rax];

	if (!regs)
		return;

	for (i = 0; i < syscall.n_params; i++)
	{
		if (syscall.params[i] == VOID)
			continue;
		switch (i)
		{
		case 0:
			param = (unsigned long)regs->rdi;
			break;
		case 1:
			param = (unsigned long)regs->rsi;
			break;
		case 2:
			param = (unsigned long)regs->rdx;
			break;
		case 3:
			param = (unsigned long)regs->r10;
			break;
		case 4:
			param = (unsigned long)regs->r8;
			break;
		case 5:
			param = (unsigned long)regs->r9;
			break;
		default:
			return;
		}
		if (syscall.params[i] == VARARGS)
			printf("...");
		else
			printf("%#lx%s", param,
					(i < syscall.n_params - 1) ? ", " : "");
	}
}

/**
 * tracerLoop - tracer
 * @child_pid: pid
 * Return: 0, 1
 */
int tracerLoop(pid_t child_pid)
{
	int status, syscall_return, first_syscall;
	struct user_regs_struct regs;

	syscall_return = 1;
	first_syscall = 1;

	while (1)
	{
		if (wait(&status) == -1)
			return (1);
		if (WIFEXITED(status))
		{
			printf(") = ?\n");
			break;
		}

		if (ptrace(PTRACE_GETREGS, child_pid, NULL, &regs) == -1)
			return (1);

		if (!syscall_return || first_syscall)
		{
			printf("%s", syscalls_64[regs.orig_rax].name);
			printParams(&regs);
			fflush(stdout);
			first_syscall = 0;
		}

		if (syscall_return)
			printf(" = %#lx\n", (unsigned long)regs.rax);

		if (ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL) == -1)
			return (1);

		syscall_return = syscall_return ? 0 : 1;
	}

	return (0);
}


/**
 * main - entry point
 * @argc: count
 * @argv: vector
 * @envp: environmental variables
 * Return: 0,
 */
int main(int argc, char *argv[], char *envp[])
{
	pid_t pid;

	if (argc < 2 || !argv)
	{
		fprintf(stderr, "usage: %s <prog> <prog args>...\n", argv[0]);
		return (1);
	}

	switch (pid = fork())
	{
	case -1:
		return (1);
	case 0:
		if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
			return (1);
		if (execve(argv[1], argv + 1, envp) == -1)
			return (1);
	default:
		break;
	}

	return (tracerLoop(pid));
}
