import math
primes=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997]
for i in range(1001,1000000):
	check=True
	for j in range(len(primes)):
		if(math.sqrt(i)<primes[j]):
			break
		if(i%primes[j]==0):
			check=False
			break
	if(check):
		primes.append(i)
def Search(n):
	global primes
	check=False
	maxLength=0
	for i in range (len(primes)):
		if(primes[i]>n):
			maxLength=i-1
			break
	for i in range (maxLength):
		sum=primes[i]
		for j in range(maxLength-1,i-1,-1):
			if(sum+primes[j]==n):
				print('{} = {} + {}'.format(n,primes[i],primes[j]))
				check=True
				break
			elif(sum+primes[j]<n):
				break
		if(check):
			break
	if(not check):
		print("Goldbach's conjecture is wrong.")
while True:
	try:
		n=input()
	except EOFError:
		break
	if(int(n)==0):
		break
	Search(int(n))
		
