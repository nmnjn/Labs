x=-1
echo "Enter a number"
read number
x=`expr $number \% 2`
if [ $x -eq 0 ]
then echo "EVEN"
else echo "ODD"
fi
