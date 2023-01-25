rm -f infilebis
cp infile infilebis
make re
echo "START" > tester.log


echo -n "< infilebis grep i | grep e > outfilebis\n\n"
< infilebis grep i | grep e > outfilebis
echo -n "\n\n----------\n\n\n"
echo -n "./pipex infile "grep i" "grep e" outfile\n\n"
valgrind --leak-check=full ./pipex infile "grep i" "grep e" outfile
echo "\n\tDIFF 1:" >> tester.log
diff outfile outfilebis >> tester.log

echo -n "< infilebis i | grep e > outfilebis\n\n"
< infilebis i | grep e > outfilebis
echo -n "\n\n----------\n\n\n"
echo -n "./pipex infile "i" "grep e" outfile\n\n"
valgrind --leak-check=full ./pipex infile "i" "grep e" outfile
echo "\n\tDIFF 2:" >> tester.log
diff outfile outfilebis >> tester.log

echo -n "< infilebis grep i | e > outfilebis\n\n"
< infilebis grep i | e > outfilebis
echo -n "\n\n----------\n\n\n"
echo -n "./pipex infile "grep i" "e" outfile\n\n"
valgrind --leak-check=full ./pipex infile "grep i" "e" outfile
echo "\n\tDIFF 3:" >> tester.log
diff outfile outfilebis >> tester.log

echo -n "< infile ls -l | wc -l > outfile\n\n"
< infilebis ls -l | wc -l > outfilebis
echo -n "\n\n----------\n\n\n"
echo -n "./pipex infile "ls -l" "wc -l" outfile\n\n"
valgrind --leak-check=full ./pipex infile "ls -l" "wc -l" outfile
echo "\n\tDIFF 4:" >> tester.log
diff outfile outfilebis >> tester.log
