set_languages("c++23")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

add_repositories("myrepo local-repo", {rootdir = os.scriptdir()})

add_requires("miniaudio", {configs = {headeronly = true, avx2 = true, mp3 = true}})
add_requires("glfw")
add_requires("glm")
add_requires("stb")
add_requires("skia-local", {configs = {gpu = true}})

if is_os("windows") then
    add_links("user32", "gdi32", "kernel32")
    add_defines("VK_USE_PLATFORM_WIN32_KHR", "_WIN32")
else
    add_defines("VK_USE_PLATFORM_WAYLAND_KHR")
end

target("RPG-demo")
    set_kind("binary")
    add_includedirs("include/")
    add_headerfiles("include/**.hpp")
    add_files("src/**.cpp")
    add_packages("miniaudio", "glfw", "glm", "skia-local", "stb")