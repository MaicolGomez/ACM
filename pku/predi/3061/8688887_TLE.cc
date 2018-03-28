 #include <iostream>
 using namespace std;
 int v[100000];
 int nums,N,S;
 
 void Input(int nums)
 {
  
 	for(int i=0; i<nums; i++)
 		cin >> v[i];
 }
 
 int Average()
 {
 	int sum = 0;
 	for (int i=0; i<N; i++)
 		sum += v[i];
 	int average = sum / N;  
 	return average;
 }
 
 bool Solve(const int length)
 {
 	int sum = 0; // sum of nums of length
 	for (int i=0; i<length; i++)
 		sum += v[i];
 	for (int i=0; i<N-length+1; i++)
 	{
 		if (sum >= S) return true;
 		sum += v[i+length] - v[i];
 	}
 	return false;
 }
 
 int main()
 {	
 	cin >> nums;
 	while(nums--)
 	{
 		cin >> N >> S;
 		Input(N);
 		/* minimal_length */
 		int minimal_length  = S / Average();
 		if ( Solve(minimal_length) == true )
 		while(1) 
 		{
 			minimal_length--;  
 			if ( Solve(minimal_length) == false ) {minimal_length++; break; }
 		}
 		else if ( Solve(minimal_length) == false )
 		while(1) 
 		{
 			minimal_length++;  
 			if ( Solve(minimal_length) == true) break;
 		}
 		/* minimal_length */
 		cout << minimal_length << endl;
 	}
 	return 0;
 }
