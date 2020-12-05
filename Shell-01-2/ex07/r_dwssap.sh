#!/bin/sh
sed 's/:.*//' /etc/passwd | sed -n '1d;p;n' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | sed ':a;N;$!ba;s/\n/, /g' | tr "\n" "."