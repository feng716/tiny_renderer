target("main")
    set_kind("binary")
    add_files("./src/source/*.cpp")
    add_includedirs("./src/include")

    -- msys settings
    add_includedirs("F:\\Msys2\\mingw64\\include")
    add_linkdirs("F:\\Msys2\\mingw64\\lib")
    -- windows
    add_links("gdi32")

    --debug
    add_cxflags("-g")