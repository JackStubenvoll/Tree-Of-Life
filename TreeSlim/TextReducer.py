##f = open('D:\Python\TextParser\AnimalKigdom.txt', 'r')
with open("D:\Python\TextParser\AnimalKigdom2.txt","r" ,encoding= 'utf8') as f:
    lines = f.readlines()
    f.close()
with open("D:\Python\TextParser\AnimalKingdom.txt","w",encoding= 'utf8' ) as f2:
    for line in lines:
        if line.strip() != "AcanthogyrusThapar,1927[subgenus]":
            f2.write(line)
print("Done")