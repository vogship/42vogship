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
- [42header](https://github.com/42Paris/42header "42header vim plugin")

### Installing
one liner:  
```sh
git clone https://github.com/IsCoffeeTho/42vogship.git /tmp/vogship; make all -C /tmp/vogship; rm -rf /tmp/vogship;source ~/.bashrc
```  
  
line by line:
```sh
git clone https://github.com/IsCoffeeTho/42vogship.git /tmp/vogship;
make all -C /tmp/vogship;
rm -rf /tmp/vogship;
source ~/.bashrc
```

Install location: `~/.vogship/`

## Updates
Updates:
Fixed some issues that mac run

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

**Legacy Commands**
- `updateVogship` ___v1.2.0___ Runs Installer if there is a new update. \[Eqv `vogship -u`\]

***Coming Soon***
- `vpm <package name>` Vogship Package Manager ran by students from around the world (hopefully).
