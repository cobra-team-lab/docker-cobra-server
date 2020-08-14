#!/bin/sh
cd $HOME/hlserver/dods-competitive
./srcds_run -game dod +map dod_donner -port 27015 -autoupdate -steam_dir ~/dods-competitive -steamcmd_script ~/dods_competitive.txt $@
