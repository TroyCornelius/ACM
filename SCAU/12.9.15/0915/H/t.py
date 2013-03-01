import os
import string

route = os.getcwd()
for dir in os.listdir(route):
	subpath = os.path.join(route, dir)
	if not os.path.isfile(subpath): continue
	lst = subpath.split(".")
	if lst[-1] not in ["in", "out"] or lst[0][len(lst[0]) - 1] == "H": continue
	t = dir.split(".")
	caseno = int(t[0])
	if caseno % 3 == 0: continue
	filename = "H" + "." + lst[-1]
	input, output = open(dir), open(filename, "a") 
	print input, output
	try:
		text = input.read()
		output.write(text)
	finally:
		input.close()
		output.close()
	#raw_input("next")
raw_input("...")