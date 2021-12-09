 def taxonyfilemaker(searchterm):

    with open('D:\Python\TextParser' +searchterm+ 'AnimalKigdom.txt', 'w',encoding='utf8') as f2:
        f2.writelines(newlines)
newlines = []
templn = []
with open('D:\Python\TextParser\AnimalKigdom2.txt',encoding='utf8') as f:
    searchterm = input()
    
    for i in range(0, len(templn)):
        lines = f.readline()
print("done")