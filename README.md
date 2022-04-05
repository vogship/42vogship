# The Vogship v2 Turbo
The Vogship allows you to navigate the vogsphere a lot more freely so you can focus on making and helping easily. \[NOW IN C!\]

```
     / /  |/| |
   / /__   / /
 /____  | | |/|  █  Vogship
      | |                      Made By Developers for Developers
```

## Installation
#### Dependencies
- [Norminette](https://github.com/42School/norminette "42 Norminette")

### Installing
Using vspm:
```sh
vspm -i vogship
```
One Liner:  
```sh
git clone https://github.com/vogship/42vogship.git vogship; make all -C vogship; rm -rf vogship; source ~/.bashrc
```  
line by line:
```sh
git clone https://github.com/vogship/42vogship.git vogship
make all -C vogship
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

For more details on any command you can always check the manual of that command  
`man <command>`

&nbsp;

> Vogship - 2022
> `Create what you love.`