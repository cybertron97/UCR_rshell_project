#rShell

This project coded here is essentially the composite pattern. We have various header and .cpp files in order for this program to work. All of these header/.cpp files are then implemented in a main.cpp file which actually runs the command that is given by the user.

The program is supposed ot be able to read in a command from the user (whether ls, mkdir, etc). It utilizes an execute function to run bash commands and has a vector of strings for storing its specific commands. These commands can also be connected through connectors such as "||", "&&", and ";". These contain pointers in order to determine the proper execution of the next command in line. If Andand's first command runs successfully, then it shall execute its second, whereas if Oror's first command runs successfully, its second command will not run, as per boolean logic.

First, project gets the input from the user and parses it into separate vectors of strings, which are used to create connector and command objects that are linked to one another and added to its vector. After that, it calls its own execute function that that runs over each Base object, which in turn execute themselves. The user may enter any number of commands until they choose to exit the shell with the "exit" command.

List of known bugs:
1. Some commands work fine in rshell, but don't execute in test shell programs
2. git status is unable to run due to rshell not being a git repository, though this may be due to other factors
3. Some comment tests will result in vector errors, however the program can generally handle most types of comments