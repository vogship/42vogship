# The Vogship v1.2.1
The Vogship allows you to navigate the vogsphere a lot more freely so you can focus on making and helping easily.
___
### Installation

**Dislaimer:**
The Installation process overwrites the ``~/.bashrc`` file. proceed with caution

Command:
``curl -L -o Installer.sh https://bit.ly/vogshipInstall;chmod a+x Installer.sh;./Installer.sh;source ~/.bashrc`` 

Step by step:
1. Download `curl -L -o Installer.sh https://bit.ly/vogshipInstall`
2. Verify `chmod a+x Installer.sh`
3. Install `./Installer.sh`
4. Apply `source ~/.bashrc`
**Thats it!**

### Commands
The Vogship adds the following commands:
- `car <file/files>` compiles, runs, and returns. perfect for slight debugging.
- `cls` Clears the screen \[Eqv. `clear`\].
- `compile [-<gcc parameters>] <file/files>` Compiles *.c* files using gcc.
- `genhead <files>` This implements the :Stdheader into any files specified without duplicates.
- `medir <name>` Create and Enter a directory.
- `norm <file/files>` Checks the files through 'The Norminette'.
- `vogship <flags>` Main command with limited features.

**Legacy Commands**
- `updateVogship` ___v1.2.0___ Runs Installer if there is a new update. eqv `vogship -u`

***Coming Soon***
- `devogr <lang> <file/files>` Simple Debugger. ___Implementation Date UNKNOWN___.
