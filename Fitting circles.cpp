/*
You are given a rectangle of length and width. You are required to determine a circle that contains the maximum circumference that fits inside the rectangle.
This type of circle is called a big circle. Your task is to determine the maximum number of big circles that can fit inside the rectangle. 

Input format

    First line: An integer denoting the number of test cases


Output format

For each test case, print the answer on a new line denoting the maximum number of big circles that can fit in the provided rectangle.  

SAMPLE INPUT

1
40 10

SAMPLE OUTPUT

4

Explanation

4 circles of radius 10 can fit inside the rectangle.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		long length,width;
		cin>>length>>width;
        if(length > width)
		cout<<length/width<<endl;
        else if(length <= width)
		cout<<width/length<<endl;

	}
	return 0;
}
