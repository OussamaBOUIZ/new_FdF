import os
import subprocess
import time
import random



i = 0

print("Killer...")
while i < 100:
	
	time.sleep(1)
	out = subprocess.check_output("ps | grep Fdf | cut -d ' ' -f1",shell=True)
	out_line = out.split("\n")
	pid = int(out_line[0])
	os.system("kill " + str(pid))
	

