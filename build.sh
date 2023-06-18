export MSYSTEM=MINGW64
cd $(dirname $0)
xmake
xmake project -k compile_commands
