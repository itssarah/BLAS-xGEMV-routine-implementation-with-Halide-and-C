import os 
import sys
 
def run_c_program(): 
    print('Compiling xGEMV.c ...')
    os.system("gcc xGEMV.c -o ./xGEMV_c ")
    print('Executing xGEMV_c ...')
    os.system("./xGEMV_c")
    

def run_halide_program(): 
    if (len(sys.argv) > 1) :

        path_halide = sys.argv[1]
        path_h = path_halide + '/include'
        path_lib = path_halide + '/bin'
        print('Compiling xGEMV.cpp ...')
        os.system("g++ xGEMV.cpp -g -I {} -L {} -lHalide -lpthread -ldl -o xGEMV_halide -std=c++17".format(path_h, path_lib))
        print('Executing xGEMV_halide ...')
        os.system("LD_LIBRARY_PATH={} ./xGEMV_halide".format(path_lib))

    else :
        print('Oups ! Specify the path to Halide...')
    

def compare(): 
    run_halide_program()
    print('\n')
    run_c_program()
    print('\n')
    print("Emm... The moment of truth has come !")

    base=os.path.dirname(os.path.dirname(__file__)) 
    print("Reading the C program results...")
    path_result_c = os.path.join(base,"../results/results_c.txt")  
    file_c = open(path_result_c, 'r')
    print("Reading the Halide program results...")
    path_result_halide = os.path.join(base,"../results/result_h.txt")  
    file_halide = open(path_result_halide, 'r')
    print("Checking the results...")
    content_c = (file_c.read()).split(" ")
    content_halide = (file_halide.read()).split("\n")
    
    if (content_c == content_halide): 
        print("Success! Your implementation in Halide matches the one from C.")
        print("Results : ")
        print(content_c[:-1])
        
    else: 
        print("Emm.. the results don't match, something is wrong")
    file_c.close()
    file_halide.close()

print('\n')
print("*******************************  WELCOME  *******************************\n")
print("Are you excited to see our results?..Boom, boom, Drum roll\n")
compare()
print('\n')
print("****************  Thing promised, thing due. We did it!  ****************")
print('\n')
