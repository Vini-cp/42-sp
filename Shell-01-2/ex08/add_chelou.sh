#!/bin/sh
echo "obase=13; ibase=5; $(echo "obase=5;ibase=5; $(echo $FT_NBR1 + $FT_NBR2 | tr 'mrdoc' 01234 | tr \' 0 | tr '\\' 1 | tr \"\?\! 234)" | bc -l)" | bc | tr 0123456789ABC 'gtaio luSnemf'
