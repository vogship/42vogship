# The Vogship v1.2.3
The Vogship allows you to navigate the vogsphere a lot more freely so you can focus on making and helping easily.

```
     / /  |/| |
   / /__   / /
 /____  | | |/|  █  Vogship
      | |                      Made By Developers for Developers
```

## Disclaimer
The Installation process overwrites the ``~/.bashrc`` file. proceed with caution
### Installation

Command:

``curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/Installer.sh;chmod a+x Installer.sh;./Installer.sh;source ~/.bashrc`` 

Step by step:
1. Download `curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/Installer.sh`
2. Allow `chmod a+x Installer.sh`
3. Install `./Installer.sh`
4. Run `source ~/.bashrc`
**Thats it!**

Updates:
`vogship -u[f]` in versions v1.2.1 onward you can update vogship using the main vogship command. the `f` flag is to force a reinstallation of the latest update.

### Commands
The Vogship adds the following commands:
- `car <file/files>` compiles, runs, and returns. perfect for slight debugging.
- `clsyc` Cleans up the system trying to clean up temp files that get left behind.
- `cls` Clears the screen \[Eqv. `clear`\].
- `compile [-<gcc parameters>] <file/files>` Compiles *.c* files using gcc.
- `genhead <files>` This implements the :Stdheader into any files specified without duplicates.
- `medir <name>` Create and Enter a directory.
- `norm <file/files>` Checks the files through 'The Norminette' both file types run with specific flags.
- `vogship <flags>` Main command with limited features.

**Legacy Commands**
- `updateVogship` ___v1.2.0___ Runs Installer if there is a new update. \[Eqv `vogship -u`\]

***Coming Soon***
- `devogr <lang> <file/files>` Simple Debugger. ___Implementation Date UNKNOWN___.
