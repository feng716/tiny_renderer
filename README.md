# An implementation of tiny renderer
## build
this project is based on [xmake](https://github.com/xmake-io/xmake) in msys2.
to build the project,run
```bash
xmake
```
to configure your msys2 env in xmake.lua
```lua
add_includedirs("your msys2 include dir")
add_linkdirs("your msys2 lib dir")
```