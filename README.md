# BLAS-xGEMV-routine-implementation-with-Halide-and-C
 This is an implementation of a BLAS (Basic Linear Algebra Subprograms) routine from the second level which is the general matrix-vector multiplication "xGEMV", of the form ``` alpha*A*x + beta*y ``` using both Halide and C.

## 1. Requirements
You'll need Halide to run this project, you can either: <br/>
Install Halide from source or use the binaries. Check the documentation for more information  : (https://github.com/halide/Halide/blob/master/README.md). <br/><br/>
Below, we provide a small installation guide for Linux, the one we used : 
### Linux Installation Guide
Download the binaries directly from here https://github.com/halide/Halide/releases, depending on your architecture and then extract it or build Halide using LLVM :
#### Acquiring & building LLVM
- Start by cloning the repository : ``` git clone --depth 1 --branch llvmorg-13.0.0 https://github.com/llvm/llvm-project.git ```
- Then build it like so : 
``` 
cmake -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_ENABLE_PROJECTS="clang;lld;clang-tools-extra" \     
  -DLLVM_TARGETS_TO_BUILD="X86;ARM;NVPTX;AArch64;Mips;Hexagon;WebAssembly" \
  -DLLVM_ENABLE_TERMINFO=OFF -DLLVM_ENABLE_ASSERTIONS=ON \
  -DLLVM_ENABLE_EH=ON -DLLVM_ENABLE_RTTI=ON -DLLVM_BUILD_32_BITS=OFF \
  -S llvm-project/llvm -B llvm-build
cmake --build llvm-build
cmake --install llvm-build --prefix llvm-install
```
```
export LLVM_ROOT=$PWD/llvm-install
export LLVM_CONFIG=$LLVM_ROOT/bin/llvm-config
```
#### Acquiring & building Halide
- Start by cloning the repository ```git clone https://github.com/halide/Halide.git``` <br/>
- Run ``` make -f Makefile ``` in the Halide directory.
## 2. Usage
- First clone this repository :
``` git clone https://github.com/itssarah/BLAS-xGEMV-routine-implementation-with-Halide-and-C ```
- Go to the repository using ``` cd BLAS-xGEMV-routine-implementation-with-Halide-and-C ```
- Go to the "src" directory ``` cd src ```
- Run the script.py with the absolute path of Halide as a parameter : 
```
python script.py absolute_path_to_Halide_folder
For example : python script.py '~/Halide' 
```
**Note** : the script we provide can only be used with Halide installed from sources.
To use it with Halide installed with binaries, you need to modify the script as  follows :
- Open script.py 
- Go to line 16.
- Replace 'bin' with 'lib'.
The script will compile both programs and run them, it will also check if the results are the same. If everything is okay, the output will be :
```
*******************************  WELCOME  *******************************
 
Are you excited to see our results?..Boom, boom, Drum roll
 
Compiling xGEMV.cpp ...
Executing xGEMV_halide ...
Youpiiii, multiplication terminado in Halide! 
  
Compiling xGEMV.c ...
Executing xGEMV_c ...
Youpiiii, multiplication terminado in C! 
  
Emm... The moment of truth has come !
Reading the C program results...
Reading the Halide program results...
Checking the results...
Success! Your implementation in Halide matches the one from C.
Results : 
['197', '565']
 
****************  Thing promised, thing due. We did it!  ****************
```

# ©️ License
Team : <br/>
- Melissa TESSA : https://www.linkedin.com/in/melissa-tessa-5a838a1b1/
- Sarah ABCHICHE : https://www.linkedin.com/in/sarah-abchiche/ <br/>
<br/>
For more informations please refer to one of the members of the team. **It's totally free for use.**


 
