#!/usr/bin/env python

import os, shutil, glob
import time

path = '/mnt/quizor/submit/'

date = time.strftime("%b-%d_%H:%M" , time.localtime())
name = os.getlogin()
lpath = os.getcwd().split('/')

cls = ""
lab = ""

for p in lpath:
    if "CS" in p:
        cls = p
    if "Lab" in p:
        lab = p

path += name + '/' + cls + '/' + lab + '/' + name + '_' + date

try:
    os.makedirs(path)
except OSError as e:
    pass

files = glob.glob("*.h")
for f in files:
    try:
        shutil.copyfile(f, path+'/'+f)
    except IOError:
        print f, "could not be copied."
files = glob.glob("*.cpp")
for f in files:
    try:
        shutil.copyfile(f, path+'/'+f)
    except IOError:
        print f, "could not be copied."

print "Lab Submitted"

