#ifndef GIT_COMMITS_H
#define GIT_COMMITS_H

#include <emscripten.h>
#include <time.h>
#include <string.h>

#define MAX_COMMITS 20
#define MAX_MESSAGE_LENGTH 256
#define MAX_NAME_LENGTH 64
#define SHA_LENGTH 41

// Commit 结构体
typedef struct {
    char sha[SHA_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char author[MAX_NAME_LENGTH];
    time_t date;
} Commit;

// 全局commits数组
extern Commit commits[MAX_COMMITS];
extern int commit_count;

// 导出的函数
EMSCRIPTEN_KEEPALIVE void init_commits();
EMSCRIPTEN_KEEPALIVE void add_commit(const char* sha, const char* message, 
                                    const char* author, time_t date);
EMSCRIPTEN_KEEPALIVE const Commit* get_commit(int index);
EMSCRIPTEN_KEEPALIVE int get_commit_count();

#endif