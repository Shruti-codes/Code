
S = "The quick brown fox jumped over the lazy dog"
res=""
vow = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

for word in S.split():
  if word[0] in vow:
    word+="ma"
  else:
   temp = word[0]
   word = word[1:]
   word+=temp+"ma"

   res+=word+" "

i=1
S=""
for word in res.split():
  word+='a'*i
  S+=word+" "
  i+=1

S = S[:len(S)-1]
print(S)

