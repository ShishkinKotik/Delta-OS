gnome-terminal &
cd Delta-OS/version_0.2.4
mkdir os
gcc term.c start.c commands.c files.c -o term
os/term
echo script is working
