def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        ipv4 = []
        while len(ipv4)<4:
            ipv4.append(str(n%256))
            n = int(n/256)
        ipv4.reverse()
        print('.'.join(ipv4))
main()