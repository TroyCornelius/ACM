s = raw_input()
cnt = [0] * 30
for ch in s:
    cnt[ord(ch) - ord('a')] += 1
tot = 0
for i in xrange(26):
    if cnt[i] % 2 != 0:
        tot += 1
if tot == 1 or tot == 0:
    print "First"
else:
    tot = 0
    for i in xrange(26):
        tot += cnt[i]
    if tot % 2 == 0:
        print "Second"
    else:
        print "First"
