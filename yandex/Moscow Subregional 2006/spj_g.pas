{$H+}
uses testlib,SysUtils;

var
ca,ja,s: string;
lc,lj: longint;
b,l: longint;
i,j: longint;
begin
	ja := ans.readstring;
	ca := trim(ouf.readstring);
	s  := inf.readstring;
	lc := length(ca);
	lj := length(ja);
	l  := length(s);
	if lc <= 0 then quit(_pe,'Empty output');
	for i:=1 to lc do begin
		if (ca[i] < '0') or (ca[i] > '7') then
			quit(_pe,'Incorrect symbol');
	end;
	if lc > lj then
		quit(_wa,'Not optimal');
	if ca[lc] <> '0' then
		quit(_wa,'Not correct');
	b := 0;
	for i:=1 to lc-1 do begin
		b := b + ord(ca[i]) - ord('0') - 1;
		if b < 0 then
			quit(_wa,'Not correct');
	end;
	if b <> 0 then
		quit(_wa,'Not correct');
	j := 1;
	for i := 1 to lc do begin
		if j > l then break;
		if s[j] = ca[i] then inc(j);
	end;
	if j <= l then
		quit(_wa,'Not correct');
	if lc < lj then
		quit(_fail,'Contestant''s answer is better');
	quit(_ok,'Ok!!!');
end.

