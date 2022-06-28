#ifndef _SIG_H_
#define _SIG_H_

typedef void (*sighandler_t)(int);

void s_handler(int signalnum);
int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exist(pid_t pid);

#endif /* _SIG_H_ */
