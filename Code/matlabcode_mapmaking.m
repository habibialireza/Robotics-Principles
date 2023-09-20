s = serial('COM5');
s.BaudRate=9600
fopen(s)

i = 0;

while i<180
   A = fgets(s);
   num(i+1) = str2num(A);
   i = i+1;
end
fclose(s)

j = 1

while j<181

    x(j) = num(j)*cosd((j-1))
    y(j) = num(j)*sind((j-1))
    j = j+1
end


plot(x,y)


