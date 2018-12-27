from sys import stdout
def main():
    ml = -1
    sentences = []
    while True:
        try:
            s = input()
        except EOFError:
            break
        sentences.append(s)
        if(len(s) > ml):
            ml = len(s)
    for i in range(len(sentences)):
        if(len(sentences[i]) < ml):
            arr = [' ' for _ in range(ml - len(sentences[i]))]
            sentences[i] += ''.join(arr)
    for i in range(ml):
        arr = []
        for j in range(len(sentences)-1, -1,-1):
            arr.append(sentences[j][i])
        stdout.write(''.join(arr)+'\n')
main()