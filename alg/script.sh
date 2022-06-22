for case in ./*.in; do make run < $case | diff -s - ${case:s/in/out/}; done
