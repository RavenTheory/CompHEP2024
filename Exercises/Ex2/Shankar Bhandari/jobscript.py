
import subprocess

def main():

    n = int(input("Give an integer n: "))
    for i in range(n):
        p = subprocess.Popen("echo " + str(i+1) + " | ./a.out > job"+str(i+1)+".txt &", shell=True)
    

    p.wait()
 
    subprocess.call(["echo", "all done"])
#Following code for when not printing in a file:
#
#    for i in range(n):
#        k = subprocess.Popen("echo " + str(i+1) + " | ./a.out  &" , shell=True)        
#    k.wait()   
#  
#I tested this program with n=20000 and it indeed does do parallel processing

if __name__ == "__main__":
    main()