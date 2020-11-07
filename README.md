# Arcade Toolkit

This is a light weight game library developped on my free time. It includes recent APIs and libs like vulkan or glfw.

It consists on independent modules : 
- "Main" : basic objects/structures/functions/... used in sources
- "Orion" : graphic module (vulkan)
- "Math" : mathematical module
- "Desktop" : inputs/window/... (glfw3)
- "Asset" : models/images/... (assimp/stb-image)

It can be built on Gnu-Linux based systems but it should be easy to update this code for Windows.

## Build

Modules can be choosen with these options in CMake : ATK_MOD_ORION, ATK_MOD_ASSET, ATK_MOD_DESKTOP, ATK_MOD_MATH 
(see also .vscode/cmake_build_#.sh files)

_to be completed_
