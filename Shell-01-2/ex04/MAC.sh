#!/bin/sh
ifconfig | sed -n '/.*ether/p' | sed 's/.*ether //'