WeekOfDay=["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
DaysOfMonth=[0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
Month=["","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"]
def GetDays(y1,m1,d1):
	global WeekOfDay
	global DaysOfMonth
	days = -1
	end_month = 0
	end_day = 0
	for y in range(1,y1+1):
		end_month = 12
		if (y == y1):
			end_month = m1
		for m in range(1,end_month+1):
			end_day = DaysOfMonth[m]
			if (m == 2):
				if ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0):
					end_day = 29
				if(y<1753):
					if(y%4==0):
						end_day=29
			if (m == m1 and y == y1):
				end_day = d1
			d=1
			while(d<=end_day):
				days+=1
				if(y==1752 and m==9 and d==2):
					d=14
				else:
					d+=1
	return WeekOfDay[(days+5)%7]
def NotValid(y,m,d):
	print("{}/{}/{} is an invalid date.".format(m,d,y))
while 1:
	s=input()
	s=s.split()
	y=int(s[2])
	m=int(s[0])
	d=int(s[1])
	if(y==0 and m==0 and d==0):
		break
	if(y==1752 and m==9  and d>2 and d<14):
		NotValid(y,m,d)
		continue
	if(m>12):
		NotValid(y,m,d)
		continue
	if(d>DaysOfMonth[m]):
		if(m == 2):
			if ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0):
				if(d>29):
					NotValid(y,m,d)
					continue
			else:
				NotValid(y,m,d)
				continue
		else:
			NotValid(y,m,d)
			continue
	print("{} {}, {} is a {}".format(Month[m],d,y,GetDays(y,m,d)))