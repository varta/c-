---
title: C++ Notes
author: satyavarta@gmail.com
---

# Compiler

```
    clang-format partition.cc
    COMPILER=g++ or clang++
    STANDARD=-std=c++2a or -std=gnu++2a
    $COMPILER++ $STANDART  partition.cc -o partition 2>&1  | less
    ./partition
```

# Debugger


## Build `md` to `pdf`: \`tail -1 cppnotes.md\`
eval $(pandoc -i cppnotes.md --highlight=breezedark --pdf-engine=xelatex -o cppnotes.pdf) && open cppnotes.pdf
