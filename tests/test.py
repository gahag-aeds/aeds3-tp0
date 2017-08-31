#!/usr/bin/env python3

import os, sys

import tptester


tests_dir = os.path.dirname(os.path.realpath(__file__))


tptester.tp_test(
  os.getcwd() + '/' + sys.argv[1],
  
  indexes = [16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144],
  input_file = lambda ix: tests_dir + '/data/bench3/' + str(ix) + '.in',
  answer_file = lambda ix: tests_dir + '/data/bench2/10.out',
  
  args = lambda ix: [ ],
  stdin = lambda ifile: ifile,
  output = lambda ofile, stdout: stdout
)
