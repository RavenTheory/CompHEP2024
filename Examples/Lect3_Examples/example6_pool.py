#!/usr/bin/env python

import multiprocessing
import os
import sys
import time
import psutil # sudo pip install psutil

MAX_WORKERS = max(multiprocessing.cpu_count()-1,1)

def hello(name,i_str):
    i = int(i_str)
    timedelay = 3*(i+1)

    print('Hello world',name,i_str)
    print('timedelay  ',timedelay)
    print('pid        ',os.getpid())
    print('parent pid ',os.getppid())

    time.sleep(timedelay) #seconds

    print('Hello world',name,i_str,"finished")

def main():

    t0 = time.time()

    pool = multiprocessing.Pool(MAX_WORKERS)

    pids = []
    lock = multiprocessing.Lock()

    # submit processes
    for i in range(5):
        p = multiprocessing.Process(target=hello, args=("testi",i))
        p.start()
        pids.append(p.pid)

    # monitor progress
    nalive = len(pids)
    print("\033[35mMonitoring\033[0m")
    print("\rProcesses running",nalive) # \r shifts your cursor to the beginning of the string or line.

    os.system('setterm -cursor off')
    i = 0
    while nalive > 0:
        al = 0
        for pid in pids:
            if psutil.Process(pid).status() != psutil.STATUS_ZOMBIE:
                al = al+1
        nalive = al
        dt = time.time()-t0
        lock.acquire()
        sys.stdout.write("\rProcesses running %s/%s, time used %s min %s s             "%(nalive,len(pids),int(dt/60),int(dt%60)))
        sys.stdout.flush()
        lock.release()

    sys.stdout.write("\n")
    os.system('setterm -cursor on')


if __name__ == "__main__":
    main()

