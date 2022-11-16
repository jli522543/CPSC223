echo "Compile RightTriangles.c"
gcc -c -Wall -m64 -no-pie  rightTriangle.c -std=gnu11  -lm
#Note the uncommon standard "GNU of 2011"

echo "Link the object files"
gcc -m64 -no-pie -o current.out rightTriangle.o -std=gnu11 -lm


#Make sure the executable has permission to execute
chmod u+x current.out

echo "Run the program Date and Time:"
./current.out

#Delete some un-needed files
rm *.o
rm *.out

echo "The script file will terminate"



