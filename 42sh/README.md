## Project: 42sh @ 42born2code

### Summary
This project is about writing the most stable and most complete UNIX shell possible.
With the 42sh project, you will go even further than minishell and 21sh by adding functionailities such as globbing management, subshells and inhibitor.

### Features

- Prompt display & correct spaces and tabulations monitoring
- `Ctrl+D` and `Ctrl+C` keys combination features for line edition and process execution.
- The `;` command line separator
- Quote handling: `"` (double quote), `'` (simple quote) and `\` (backslash)
- Built-ins `cd`, `echo`, `exit`, `env`, `setenv` and `unsetenv` (with all POSIX standard options)
- Logical operators `&&` and `||`
- Pipes `|`
- Redirections `>`, `>>`, `<` + advanced redirection and aggregation operators (`<<`, `>&`, `<&`)
- Line edition feature using the `termcaps` library (move cursor; edit the line at a specific location; navigate through the command history; cut, copy, and/or paste; ...)
- Run commands with their parameters and PATH monitoring
- Error monitoring, without using `errno`, and return values of commands
- Complete management of the history, `history` and `!` built-ins (with all POSIX standard options)
- Contextual dynamic completion of commands & built-ins

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
./42sh
./42sh < /dev/random
echo "ls -la" | ./42sh
```

### Picture(s)
N/A

### Final grade
**72/100** :white\_check\_mark:

### Task list, for this repository
- [x] create basic README
- [x] add relevant content to README
- [ ] add picture/gif to README
