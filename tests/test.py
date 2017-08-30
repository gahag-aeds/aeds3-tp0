#!/usr/bin/env python3

import os, sys

import tptester


tests_dir = os.path.dirname(os.path.realpath(__file__))


tptester.tp_test(
  os.getcwd() + '/' + sys.argv[1],
  
  indexes = [ '10', '100', '1000', '10000', '100000' ],
  input_file = lambda ix: tests_dir + '/data/bench/' + ix + '.in',
  answer_file = lambda ix: tests_dir + '/data/bench/' + ix + '.out',
  
  args = lambda ix: [ ],
  stdin = lambda ifile: ifile,
  output = lambda ofile, stdout: stdout
)
