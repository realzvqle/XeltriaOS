target("kernel")
    -- on_build(function(target)
    --     os.run("aarch64-none-elf-as -o ./boot.o ./src/boot.asm")
    -- end)
    set_kind("binary")
    set_arch("aarch64")
    set_filename("kernel.elf")
    set_toolchains("aarch64-toolchain")
    add_files("src/*.c", "src/*.S")
    add_files("src/**/*.c", "src/**/*.S")
    add_includedirs("src")
    set_objectdir("obj")
    add_cflags("-ffreestanding")
    set_targetdir(".")

    add_ldflags("--nostdlib -Tlinker.ld", { force = true })
    before_link(function (target)
        local result = os.run("aarch64-none-elf-as -o boot.o src/boot.asm")
        if result ~= 0 then
            print("Warning while building boot.asm. Continuing with the build...")
        end
    end)
    

toolchain("aarch64-toolchain")
    set_kind("standalone")
    set_toolset("cc", "aarch64-none-elf-gcc")
    set_toolset("as", "aarch64-none-elf-gcc")
    set_toolset("ld", "aarch64-none-elf-ld")
toolchain_end()


