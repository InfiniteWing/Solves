def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        print('{} and {} sitting in the tree'.format(arr[0], arr[1]))
main()