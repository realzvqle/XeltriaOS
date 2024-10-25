@echo off

cd kernel
xmake f --toolchain=aarch64-toolchain
cd ..