#!/usr/bin/env python3


def main():

    #Making this in python since I am most familiar with this which saves me bit of time in these busy times =) 

    filename = "rawdata.txt"
    
    try: 
        with open(filename, 'r') as f:
            lines = f.readlines()
        
        k = 0
        for i, line in enumerate(lines):
            if "End PYTHIA Event Listing" in line:
                k = i+1
                break

        newlines = [lines[i] for i in range(len(lines)) if i >= k]

        
        newfileName = "data.txt"
        with open(newfileName, 'w') as g:
            g.writelines(newlines)
            

    except FileNotFoundError:
        print(f"{filename} not found")
    
    
    
if __name__ == "__main__":
    main()
