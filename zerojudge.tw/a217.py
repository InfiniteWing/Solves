import math
while True:
    try:
        s = input()
    except EOFError:
        break
    tag = ['?','!','.',' ',',']
    s = list(s)
    sn = []
    first = False
    last_tag = False
    for i, _s in enumerate(s):
        if(_s in tag):
            if(_s != ',' and _s != ' '):
                last_tag = True
        else:
            if(not first):
                first = True
                last_tag = False
                _s = _s.upper()
            else:
                if(last_tag):
                    last_tag = False
                    _s = _s.upper()
                else:
                    if(_s == 'i'):
                        if(i < len(s)-1):
                            if(s[i+1] in tag):
                                if(s[i-1] in tag):
                                   _s = _s.upper() 
                        else:
                            if(s[i-1] in tag):
                               _s = _s.upper()
        sn.append(_s)
    print(''.join(sn))