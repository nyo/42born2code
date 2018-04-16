## Project: 21sh @ 42born2code

### Summary
You'll have to start from your minishell and make it stronger to get little by littler closer to a real functionnal shell.
You'll add couple of features such as multi-commande management, redirections as well as line edition that will allow you to use arrows for example.

### Features
- `Ctrl+D` and `Ctrl+C` keys combination features for line edition and process execution.
- The `;` command line separator
- Pipes `|`
- Redirections `>`, `>>`, `<` and `<<` + file descriptor aggregation
- Logical operators `&&` and `||`
- Line edition feature using the `termcaps` library (move cursor; edit the line at a specific location; navigate through the command history; cut, copy, and/or paste; ...)
- Builtins `cd`, `echo`, `exit`, `env`, `setenv` and `unsetenv`
- Quote handling: `"` (double quote), `'` (simple quote) and `\` (backslash)

### Installation
```
make
```

available rules:
```
make re
make clean
make fclean
```

### Usage
```
./21sh
./21sh < /dev/random
echo "ls -la" | ./21sh
```

### Picture(s)
N/A

### Final grade
**123/100** :white\_check\_mark:

### Task list, for this repository
- [x] create basic README
- [x] add relevant content to README
- [ ] add picture/gif to README
