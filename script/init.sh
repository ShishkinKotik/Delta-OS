echo "cloning repo"
git clone https://github.com/ShishkinKotik/Delta-OS
cd ~/Delta-OS/sub-system
echo "starting OS..."
mkdir os
gcc term.c start.c commands.c files.c -o os/term
os/term
chmod +x ~/os/term
echo "ending os"
