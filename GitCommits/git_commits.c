// git_commits.c
#include <emscripten.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_COMMITS 20
#define MAX_MESSAGE_LENGTH 256
#define MAX_NAME_LENGTH 64
#define SHA_LENGTH 41

typedef struct {
    char sha[SHA_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char author[MAX_NAME_LENGTH];
    time_t date;
} Commit;

static Commit commits[MAX_COMMITS];
static int commit_count = 0;

EMSCRIPTEN_KEEPALIVE
void init_commits() {
    commit_count = 0;
}

EMSCRIPTEN_KEEPALIVE
void add_commit(const char* sha, const char* message, const char* author, time_t date) {
    if (commit_count >= MAX_COMMITS) return;
    
    Commit* commit = &commits[commit_count];
    strncpy(commit->sha, sha, SHA_LENGTH - 1);
    strncpy(commit->message, message, MAX_MESSAGE_LENGTH - 1);
    strncpy(commit->author, author, MAX_NAME_LENGTH - 1);
    commit->date = date;
    
    commit_count++;
}

EMSCRIPTEN_KEEPALIVE
const Commit* get_commit(int index) {
    if (index < 0 || index >= commit_count) return NULL;
    return &commits[index];
}

EMSCRIPTEN_KEEPALIVE
int get_commit_count() {
    return commit_count;
}

int main() {
    // 初始化
    init_commits();
    return 0;
}