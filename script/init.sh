echo "cloning repo"
git clone https://github.com/ShishkinKotik/Delta-OS
cd ~/Delta-OS/sub-system
echo "✓starting OS..."
$STATUS_BOOTING
$STATUS_VERSION
$STATUS_OS
echo "✓status: version=v.0.0.0.9-a $STATUS_VERSION"
echo "✓status: booting=true $STATUS_BOOTING"
echo "✓status: OS=DeltaOS Linux $STATUS_OS"
mkdir os
clang term.c commands.c files.c simple_comms.c -o os/term
os/term
chmod +x ~/os/term
echo "✓ending os"
