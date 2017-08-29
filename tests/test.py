#!/usr/bin/env python3

import os, sys

import tptester


tests_dir = os.path.dirname(os.path.realpath(__file__))


tptester.tp_test(
  os.getcwd() + '/' + sys.argv[1],
  
  indexes = [ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10' ],
  input_file = lambda ix: tests_dir + '/data/in/' + ix + '.in',
  answer_file = lambda ix: tests_dir + '/data/out/' + ix + '.in',
  
  args = lambda ix: [ ],
  stdin = lambda ifile: ifile,
  output = lambda ofile, stdout: stdout
)
