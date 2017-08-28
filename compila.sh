SRC=`ls *.cpp`
TGT=${SRC%.cpp}
g++ -g -Wall $SRC -o $TGT
./$TGT && cat output.txt

