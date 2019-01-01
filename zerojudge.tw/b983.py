def decode(encode_s, key):
    en = 'abcdefghijklmnopqrstuvwxyz'
    decode_arr = []
    j = 0
    for i in range(len(encode_s)):
        dif = ord(key[j].lower()) - 97
        s = ord(encode_s[i].lower()) - dif - 97
        s += 26 if s < 0 else 0
        decode_arr.append(en[s])
        if(encode_s[i].isupper()): decode_arr[-1] = decode_arr[-1].upper()
        j += 1
        if(j >= len(key)): j = 0
    return ''.join(decode_arr)
def main():
    while True:
        try:
            key = input()
        except EOFError:
            break
        encode_s = input()
        decode_s = decode(encode_s, key)
        print(decode_s)
main()