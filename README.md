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
one liner:  
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
- `car <file/files>` compiles, runs, and returns. perfect for slight debugging.
- `clsyc` Cleans up the system trying to clean up temp files that get left behind.
- `cls` Clears the screen \[Eqv. `clear`\].
- `compile [-<gcc parameters>] <file/files>` Compiles *.c* files using gcc.
- `genhead <files>` This implements the :Stdheader into any files specified without duplicates.
- `rsthead <files>` This clears all :Stdheaders from any file specified.
- `medir <name>` Create and Enter a directory.
- `norm <file/files>` Checks the files through 'The Norminette' both file types run with specific flags.
- `vogship <flags>` Main command with limited features.

***Coming Soon***
- `vspm <package name>` see [VSPM](https://github.com/vogship/vspm) repository
