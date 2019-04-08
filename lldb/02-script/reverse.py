#!/usr/bin/python

def reverse(debugger, command, result, internal_dict):
    if str(debugger.GetSelectedTarget()) != "No value":
        print "FT_%s" % str(debugger.GetSelectedTarget())[::-1]
    else:
        print "No target!"

def __lldb_init_module(debugger, internal_dict):
    debugger.HandleCommand("command script add -f reverse.reverse reverse") 
