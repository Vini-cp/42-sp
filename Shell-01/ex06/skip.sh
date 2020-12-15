#!/bin/sh
ls -l | sed -n '2d;p;n'
# 'n;d'