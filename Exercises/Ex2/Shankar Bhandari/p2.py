import re
import os.path

def main():
        
    fname = 'brilcalc.log'
    try:
        f =  open(os.path.dirname(__file__) + '/../' + fname , "r")
        s = f.readlines()
    except OSError:
        print("Couldn't open file", fname)
        exit()
    
    n=-1
    #Here we find the line in the data where the summary titles are in
    #The values will be in 2 lines below where the summary titles are
    for i, line in enumerate(s):
        if re.search(r'totrecorded', line):
            n = i + 2
            break
    
    if n == -1 :
        print("no totalrecorded(/pb) found in the given file")
    else:
        k = re.findall(r"\d+\.\d+", s[n])
        value = float(k[1])
    #Here we have assumed that the file structure is always such that
    #totalrecorded comes after totaldelivered
    #And also that these both are always floating point numbers (which makes sense).
    f.close()


    print(f"The luminosity in units of f/b is: {value:.1f}" )


if __name__ == "__main__":
    main()
