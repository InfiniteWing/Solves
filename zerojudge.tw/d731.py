
while True:
    try:
        n=int(input())
    except EOFError:
        break
    for i in range(n):
        m=int(input())
        red=[]
        blue=[]
        for j in range(m):
            t=int(input())
            if(t<0):
                red.append(-t)
            else:
                blue.append(t)
        red=sorted(red,reverse=True)
        blue=sorted(blue,reverse=True)
        if(len(red)==0 or len(blue)==0):
            print(1)
        else:
            tall=1
            current_size=0
            current_color=0
            current_red_index=0
            current_blue_index=0
            if(red[0]>blue[0]):
                current_size=red[0]
                current_color=1 #red
            else:
                current_size=blue[0]
                current_color=2 #blue
            while True:
                had_add=False
                if(current_color==1):
                    for i in range(current_blue_index,len(blue)):
                        if(current_size>blue[i]):
                            current_color=2
                            current_blue_index=i
                            current_size=blue[i]
                            had_add=True
                            break
                else:
                    for i in range(current_red_index,len(red)):
                        if(current_size>red[i]):
                            current_color=1
                            current_red_index=i
                            current_size=red[i]
                            had_add=True
                            break
                if(had_add):
                    tall+=1
                else:
                    break
            #print(red)
            #print(blue)
            print(tall)
                
            