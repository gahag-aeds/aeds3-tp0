#!/usr/bin/env python3

import os, sys

import tptester


tests_dir = os.path.dirname(os.path.realpath(__file__))


tptester.tp_test(
  os.getcwd() + '/' + sys.argv[1],
  
  indexes = ['10','20','30','40','50','60','70','80','90','100','110','120','130','140','150','160','170','180','190','200','210','220','230','240','250','260','270','280','290','300','310','320','330','340','350','360','370','380','390','400','410','420','430','440','450','460','470','480','490','500'],
  input_file = lambda ix: tests_dir + '/data/bench2/' + ix + '.in',
  answer_file = lambda ix: tests_dir + '/data/bench2/' + ix + '.out',
  
  args = lambda ix: [ ],
  stdin = lambda ifile: ifile,
  output = lambda ofile, stdout: stdout
)
