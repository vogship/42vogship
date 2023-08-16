# The Vogship v2.1.1 Turbo
The Vogship Tool allows you to navigate the vogsphere a lot more freely so you can focus on making and helping more.

```
     / /  |/| |
   / /__   / /
 /____  | | |/|  █  Vogship v2.1.1 Turbo
      | |           Made By Developers for Developers
```

## Installation
#### Dependencies
- [Norminette](https://github.com/42School/norminette "42 Norminette")

### Installing
#### Without vspm:
One Liner:  
```sh
git clone https://github.com/vogship/42vogship.git vogship; make all -s -C vogship; rm -rf vogship; source ~/.bashrc
```  
line by line:
```sh
git clone https://github.com/vogship/42vogship.git vogship
make all -s -C vogship
rm -rf vogship
source ~/.bashrc
```
Install location: `~/.vogship/`

## Commands
The Vogship adds the following commands:
- `car <file/files>` compiles, runs, and returns. perfect for simple one file debugging.
- `clsyc` Cleans up the system by trying to clean up temp files that get left behind.
- `cls` Clears the screen \[Eqv. `clear`\].
- `compile [-<gcc parameters>] <file/files>` Compiles *.c* files using gcc with `-Wall -Werror -Wextra`.
- `genhead <files>` This implements the :Stdheader into any files specified without duplicates.
- `rsthead <files>` This clears all :Stdheaders from any file specified.
- `medir <name>` Makes and Enters a directory.
- `norm <file/files>` Checks the files through the 'Norminette' both file types run with specific flags.
- `vogship <flags>` The Vogship command helping you soar through 42 Terminal.

Additions to regular commands:
- `git reverse` reverses a workspace to the last commit. same as `git reset --hard HEAD`

For more details on any command you can always check the manual of that command  
`man <command>`

&nbsp;

![Create what you love.](https://vogship.web.app/cwyl-text.png "Create what you love.")