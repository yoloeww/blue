#include<iostream>
#include<assert>
#define PROCESS_NUM 5

int main() {
    for (int i = 0;i < PROCESS_NUM; i++) {
        int fds[2];
        int n = pipe(fds);
        assert(n == 0);
        (void)n;
        pid_t id = fork();
        if (id == 0) {
            close(fds[1]);
            exit(0);
        }
        close(fds[0]);
    }
    return 0;
}
