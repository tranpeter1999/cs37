//class8.cpp

/*
in C++, we have get and set functions
			  v        v
     returns value of   sets value of
	one and only one	one and only one
	data member		data member
	
get and set are used to modify private data members
you can control how they're modified

for example
add 5 points extra credit to t2

main
one.t2 += 5; DOESN'T WORK BECAUSE t2 IS PRIVATE

we do it with a set function
one.setTest2(one.getTest2 + 5);
*/