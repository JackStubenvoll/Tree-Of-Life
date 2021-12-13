##from typing import Counter
encodingLines = []
EncodedArray = []
with open('D:\Python\TextParser\AnimalKigdom2.txt', encoding='utf8') as infile:
    encodingLines = infile.readlines()
for i in range(0,len(encodingLines)):
    f = encodingLines[i].split(" ")
    j = 0
    counter = 0
    while f[j] == " ":
        j=+1


