make
echo -n "Results on " > run.log
date >> run.log
echo >> run.log

pipex_in=".runsh_pipexin"
pipex_out=".runsh_pipexout"
fd_in=".runsh_fdin"
fd_out=".runsh_fdout"

rm -f $pipex_in $pipex_out $fd_in $fd_out

cmd0="sleep 1"
cmd1="cat"
cmd2="wc -l"
cmd3="pwd"
cmd4="echo coquelicot"
cmd5="cat run.sh"
cmd6="grep e"
cmd7="grep i"
cmd8="find . pipex"
cmd9="ls"
cmd10="printf salut"

# v=""
v="valgrind"

echo "PART 1"
# No input file && No output file
	echo "No input file && No output file" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 > $fd_out
	echo -n "\tDIFF 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd3" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd3 > $fd_out
	echo -n "\tDIFF 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 > $fd_out
	echo -n "\tDIFF 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd6" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd6 > $fd_out
	echo -n "\tDIFF 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd0" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd0 > $fd_out
	echo -n "\tDIFF 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd8" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd8 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd10" "$cmd2" "$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 | $cmd1 | $cmd2 > $fd_out
	echo -n "\tBONUS 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd0" "$cmd1" "$cmd2" "$cmd3" "$cmd4" "$cmd5" "$pipex_out"
	<		$fd_in 			$cmd0 | $cmd1 | $cmd2 | $cmd3 | $cmd4 | $cmd5 > $fd_out
	echo -n "\tBONUS 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd6" "$cmd7" "$cmd8" "$cmd9" "$cmd10" "$pipex_out"
	<		$fd_in			$cmd6 | $cmd7 | $cmd8 | $cmd9 | $cmd10 > $fd_out
	echo -n "\tBONUS 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$cmd2" "$cmd7" "$cmd2" "$cmd8" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 | $cmd2 | $cmd7 | $cmd2 | $cmd8 > $fd_out
	echo -n "\tBONUS 5:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

	echo >> run.log
	rm -f $pipex_in $pipex_out $fd_in $fd_out

echo "Titouan" > $pipex_in ; echo "Victor" > $pipex_in ; echo "Pierre" > $pipex_in ; echo "Nicolas" > $pipex_in 
cp $pipex_in $fd_in
echo "PART 2"
# Input file but no output file
	echo "Input file but no output file" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 > $fd_out
	echo -n "\tDIFF 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd3" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd3 > $fd_out
	echo -n "\tDIFF 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 > $fd_out
	echo -n "\tDIFF 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd6" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd6 > $fd_out
	echo -n "\tDIFF 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd0" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd0 > $fd_out
	echo -n "\tDIFF 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd8" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd8 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd10" "$cmd2" "$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 | $cmd1 | $cmd2 > $fd_out
	echo -n "\tBONUS 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd0" "$cmd1" "$cmd2" "$cmd3" "$cmd4" "$cmd5" "$pipex_out"
	<		$fd_in 			$cmd0 | $cmd1 | $cmd2 | $cmd3 | $cmd4 | $cmd5 > $fd_out
	echo -n "\tBONUS 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd6" "$cmd7" "$cmd8" "$cmd9" "$cmd10" "$pipex_out"
	<		$fd_in			$cmd6 | $cmd7 | $cmd8 | $cmd9 | $cmd10 > $fd_out
	echo -n "\tBONUS 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$cmd2" "$cmd7" "$cmd2" "$cmd8" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 | $cmd2 | $cmd7 | $cmd2 | $cmd8 > $fd_out
	echo -n "\tBONUS 5:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

	echo >> run.log
	rm -f $pipex_in $pipex_out $fd_in $fd_out

echo "Titouan" > $pipex_in ; echo "Victor" > $pipex_in ; echo "Pierre" > $pipex_in ; echo "Nicolas" > $pipex_in 
cp $pipex_in $fd_in
touch $pipex_out $fd_out
chmod a-w $pipex_out ; chmod a-w $fd_out
echo "PART 3"
# Input file but no rights on output file
	echo "Input file but no rights on output file" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 > $fd_out
	echo -n "\tDIFF 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd3" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd3 > $fd_out
	echo -n "\tDIFF 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 > $fd_out
	echo -n "\tDIFF 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd6" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd6 > $fd_out
	echo -n "\tDIFF 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd0" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd0 > $fd_out
	echo -n "\tDIFF 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd8" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd8 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd10" "$cmd2" "$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 | $cmd1 | $cmd2 > $fd_out
	echo -n "\tBONUS 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd0" "$cmd1" "$cmd2" "$cmd3" "$cmd4" "$cmd5" "$pipex_out"
	<		$fd_in 			$cmd0 | $cmd1 | $cmd2 | $cmd3 | $cmd4 | $cmd5 > $fd_out
	echo -n "\tBONUS 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd6" "$cmd7" "$cmd8" "$cmd9" "$cmd10" "$pipex_out"
	<		$fd_in			$cmd6 | $cmd7 | $cmd8 | $cmd9 | $cmd10 > $fd_out
	echo -n "\tBONUS 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$cmd2" "$cmd7" "$cmd2" "$cmd8" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 | $cmd2 | $cmd7 | $cmd2 | $cmd8 > $fd_out
	echo -n "\tBONUS 5:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

	echo >> run.log
	rm -f $pipex_in $pipex_out $fd_in $fd_out

echo "PART 4"
touch $pipex_out $fd_out
chmod a-w $pipex_out ; chmod a-w $fd_out
# No input file and no rights on output file
	echo "No input file and no rights on output file" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 > $fd_out
	echo -n "\tDIFF 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd3" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd3 > $fd_out
	echo -n "\tDIFF 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 > $fd_out
	echo -n "\tDIFF 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd6" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd6 > $fd_out
	echo -n "\tDIFF 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd0" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd0 > $fd_out
	echo -n "\tDIFF 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd8" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd8 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd10" "$cmd2" "$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 | $cmd1 | $cmd2 > $fd_out
	echo -n "\tBONUS 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd0" "$cmd1" "$cmd2" "$cmd3" "$cmd4" "$cmd5" "$pipex_out"
	<		$fd_in 			$cmd0 | $cmd1 | $cmd2 | $cmd3 | $cmd4 | $cmd5 > $fd_out
	echo -n "\tBONUS 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd6" "$cmd7" "$cmd8" "$cmd9" "$cmd10" "$pipex_out"
	<		$fd_in			$cmd6 | $cmd7 | $cmd8 | $cmd9 | $cmd10 > $fd_out
	echo -n "\tBONUS 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$cmd2" "$cmd7" "$cmd2" "$cmd8" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 | $cmd2 | $cmd7 | $cmd2 | $cmd8 > $fd_out
	echo -n "\tBONUS 5:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

	echo >> run.log
	rm -f $pipex_in $pipex_out $fd_in $fd_out

echo "PART 5"
echo "Titouan" > $pipex_in ; echo "Victor" > $pipex_in ; echo "Pierre" > $pipex_in ; echo "Nicolas" > $pipex_in 
cp $pipex_in $fd_in
touch $pipex_out $fd_out
chmod a-w $pipex_out ; chmod a-w $fd_out ; chmod a-r $pipex_in ; chmod a-r $fd_in
# No rights on input file and no rights on output file
	echo "No rights on input file and no rights on output file" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 > $fd_out
	echo -n "\tDIFF 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd3" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd3 > $fd_out
	echo -n "\tDIFF 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 > $fd_out
	echo -n "\tDIFF 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd6" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd6 > $fd_out
	echo -n "\tDIFF 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd0" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd0 > $fd_out
	echo -n "\tDIFF 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 0:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd8" "$cmd7" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd8 | $cmd7 | $cmd2 > $fd_out
	echo -n "\tBONUS 1:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd10" "$cmd2" "$cmd1" "$cmd2" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd2 | $cmd1 | $cmd2 > $fd_out
	echo -n "\tBONUS 2:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd0" "$cmd1" "$cmd2" "$cmd3" "$cmd4" "$cmd5" "$pipex_out"
	<		$fd_in 			$cmd0 | $cmd1 | $cmd2 | $cmd3 | $cmd4 | $cmd5 > $fd_out
	echo -n "\tBONUS 3:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd6" "$cmd7" "$cmd8" "$cmd9" "$cmd10" "$pipex_out"
	<		$fd_in			$cmd6 | $cmd7 | $cmd8 | $cmd9 | $cmd10 > $fd_out
	echo -n "\tBONUS 4:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

$v	./pipex	"$pipex_in"		"$cmd1" "$cmd4" "$cmd2" "$cmd7" "$cmd2" "$cmd8" "$pipex_out"
	<		$fd_in 			$cmd1 | $cmd4 | $cmd2 | $cmd7 | $cmd2 | $cmd8 > $fd_out
	echo -n "\tBONUS 5:\n" >> run.log
	diff "$pipex_out" "$fd_out" >> run.log

	echo >> run.log
	rm -f $pipex_in $pipex_out $fd_in $fd_out

echo
cat run.log