# An implementation of tiny renderer
## build
this project is based on [xmake](https://github.com/xmake-io/xmake) in msys2.
to build the project,run
```bash
xmake
```
to configure your msys2 env,edit the lines below in xmake.lua
```lua
add_includedirs("your msys2 include dir")
add_linkdirs("your msys2 lib dir")
```
and add MSYS_PATH env to your system
```
MSYS_PATH=your msys2 dir
```