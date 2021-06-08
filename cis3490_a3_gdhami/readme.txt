Gurtej Dhami
0969863
CIS 3490 Assignment 3

To run program type "make"

To execute part 1 of the assignment (Brute force anagram count and pre sort anagram count) type:
./part1 Data4.txt

"Data4.txt" can be replaced with any txt file containing data of the same format.


To execute part 2 of the assignment (Brute force string match, Horspool string match and Boyer-Moore string match) type:
./part2 Data5.txt

"Data5.txt" can be replaced with any .txt file containing data of the same format.


type "make clean" to remove the "part1" and "part2" executable files
type "make tar" to create a tar folder with all of the assignments deliverables

Part 2.4) Analysis of Brute Force and Horspool String Search Algorithm for Different Pattern Lengths:

Brute Force Time Efficiency: O(n^2)
Horspool Time Efficiency: O(n/m)

Brute Force number of shifts:	Brute Force search time:	Horspool number of shifts:	Horspool search time:
3168446 			29.000000 mS			1131656				34.000000 mS
3256544				33.000000 mS			3300593				61.000000 mS
3124398				23.000000 mS			812922				29.000000 mS
2860110				25.000000 mS			408375				25.000000 mS
2904158				27.000000 mS			348512				22.000000 mS
2904158				25.000000 mS			420161				24.000000 mS
3256544				27.000000 mS			3300593				58.000000 mS
2948206				26.000000 mS			455440				27.000000 mS
3256544				30.000000 mS			3300593				60.000000 mS
2904158				24.000000 mS			348048				24.000000 mS

Brute Force Ratio:	Horspool Ratio:

109256 shifts/mS	33284 shifts/mS
98683 shifts/mS		54108 shifts/mS
135843 shifts/mS	28031 shifts/mS
114404 shifts/mS	16335 shifts/mS
107561 shifts/mS	15841 shifts/mS
116166 shifts/mS	17506 shifts/mS
120612 shifts/mS	56906 shifts/mS
113392 shifts/mS	16868 shifts/mS
108551 shifts/mS	55009 shifts/mS
121006 shifts/mS	14502 shifts/mS

Brute Force Average Ratio: 114547 shifts/mS
Horspool Average Ratio: 30839 shifts/mS

In general it can be seen that for smaller search patterns like single words or digits that require many pattern shifts, the bruteforce algorithm executes much faster. For less common search patterns like whole sentences the Horspool algorithm executes much quicker
than the Bruteforce method.


