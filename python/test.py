str = "... actor Bayer arctor time Selly happy ..."

str_list = str.split(' ')
print(str_list)

name_list = []
prefix = []
suffix = []

for word in str_list : 
    if (word[0].isupper()) :
        name_list.append(word)

dic = {}    
for name in name_list:
    idx = str_list.index(name)
    prefix = (str_list[idx-1])
    suffix = (str_list[idx+1])
    if prefix in dic :
        dic[prefix] = dic.get(prefix) + 1
    else 
        dic[prefix] = 1
    dic[suffix] = 1





print(name_list)
print(prefix)
print(suffix)