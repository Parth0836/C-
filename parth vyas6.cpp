 #include<iostream>
 
using namespace std;
 
// Function to find the median of two sorted array of equal length.
void median(float arr1[], int s1, int e1, float arr2[], int s2, int e2)
{
	float med1, med2;
	// If the length of the sub arrays is even.
	if((e1-s1+1)%2 == 0)
	{
		// If only two element left in the array then the median can be found.
		if(e1-s1 == 1)
		{
			// median of the array will be the average of the maximum of the smaller elements and minimum of the greater element.
			med1 = ((arr1[s1]<arr2[s2]?arr1[s1]:arr2[s2])+(arr1[e1]>arr2[e2]?arr1[e1]:arr2[e2]))/2;
			cout<<med1;
			return;
		}
 
		// If more element are there then the individual median will be the average of mid data element of each array.
		med1 = (arr1[(e1+s1)/2]+arr1[(e1+s1)/2+1])/2;
		med2 = (arr2[(e2+s2)/2]+arr2[(e2+s2)/2+1])/2;
 
		// If the calculated individual medians are equal then the combined median will also be same.
		if(med1 == med2 )
		{
			cout<<med1;
			return;
		}
		else
		{
			// If median of the first array is greater than the second one then-
			// The combined median will be either in the first half of the first array or in the second half of the other array.
			if(med1 > med2)
				median(arr1, s1, (e1+s1)/2+1, arr2, (e2+s2)/2, e2);
			// Otherwise the combined median will be either in second half of first array or in the first half of the other array.
			else
				median(arr1, (e1+s1)/2, e1, arr2, s2, (e2+s2)/2+1);
		}
	}
	// If the length of the sub array is odd.
	else
	{
		if(e1-s1 == 0)
		{
			med1 = (arr1[s1]+arr2[s2])/2;
			cout<<med1;
			return;
		}
 
		// If more element are there then the individual median will be the mid data element of each array.
		med1 = arr1[(e1+s1)/2];
		med2 = arr2[(e2+s2)/2];
 
		// If the calculated individual medians are equal then the combined median will also be same.
		if(med1 == med2 )
		{
			cout<<med1;
			return;
		}
		else
		{
			// If median of the first array is greater than the second one then-
			// The combined median will be either in the first half of the first array or in the second half of the other array.
			if(med1 > med2)
				median(arr1, s1, (e1+s1)/2, arr2, (e2+s2)/2, e2);
			// Otherwise the combined median will be either in second half of first array or in the first half of the other array.
			else
				median(arr1, (e1+s1)/2, e1, arr2, s2, (e2+s2)/2);
		}
	}
	return;
}
 
int main()
{
	int n, i;
	cout<<"Enter the length of the arrays: ";
	cin>>n;
	float arr1[n], arr2[n];
 
	// Take the input of second sequence.
	cout<<"\nEnter the first sorted sequence :\n";
	for(i = 0; i < n; i++)
	{
		cout<<"Enter "<<i+1<<" value: ";
		cin>>arr1[i];
	}
 
	// Take the input of second sequence.
	cout<<"\nEnter the second sorted sequence :\n";
	for(i = 0; i < n; i++)
	{
		cout<<"Enter "<<i+1<<" value: ";
		cin>>arr2[i];
	}
 
	// Print the combined array.
	cout<<"\n\nthe median of the arrays is: ";
	median(arr1, 0, n-1, arr2, 0, n-1);
 
	return 0;
}
