emcc git_commits.c -o git_commits.js \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS="['_main','_init_commits','_add_commit','_get_commit','_get_commit_count']" \
    -s EXPORTED_RUNTIME_METHODS="['ccall','cwrap']" \
    -s NO_EXIT_RUNTIME=1 \
    -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" \
    -s NO_FILESYSTEM=1 
