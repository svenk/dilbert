#!/bin/bash
#
# Execute this in the dilbert base directory. Assumes you have peano above.
# Consult the README of this file for further details.
# This script is mainly for having a clean view onto the new files instead
# of only diffs.
# SK, 2017

rsync -a -v  src/ ..
