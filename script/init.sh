cd ~/Delta-OS/sub-system
mkdir os
gcc term.c start.c commands.c files.c -o os/term
os/term
chmod +x ~/os/term
echo script is working
