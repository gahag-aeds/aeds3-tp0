#!/usr/bin/env python3

import os, sys

import tptester


tests_dir = os.path.dirname(os.path.realpath(__file__))


tptester.tp_test(
  os.getcwd() + '/' + sys.argv[1],
  
  indexes = [ '5' ],
  input_file = lambda ix: tests_dir + '/data/in' + ix + '.txt',
  answer_file = lambda ix: tests_dir + '/data/out' + ix + '.txt',
  
  args = lambda ix: [ ],
  stdin = lambda ifile: ifile,
  output = lambda ofile, stdout: stdout
)
