import os
import subprocess
import random

def get_map():
	out = subprocess.check_output("ls ../maps/",shell=True)
	maps = out.split("\n")
	return(maps)

maps = get_map()
i = 0
while i < 500:
	length = len(maps)
	if length == 0:
		maps = get_map()
		length = len(maps)
	number = random.randint(0,length-1)
	os.system("../Fdf ../maps/"+maps[number])
	maps.pop(number)
	i += 1
