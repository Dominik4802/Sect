
# Sect

## Problem description:
We've found ourselves in the wrong place at the wrong time. Among n (e.g. n = 20) people (we are numbering from 1) all but you want to commit suicide (unfortunately you do not have time to argue). The guru came up with the following method: you put yourself in a circle and every second person is murdered (the first is not and the second is, the third is not, but the fourth is, the fifth is not, but the sixth is, etc.). Where will you stand (choose between 1 and n)? The time starts now, you have 10 seconds. Who is next? Who will die as a k-th person?
<br><br>
Let n = 10. Then the order is: 2,4,6,8,10,3,7,1,9. Therefore, the 5th person survived. This is equivalent to n = 10 and k = 10. Let n = 10 and k = 6. Then, the person on the spot number 3 will die as the sixth.
<br><br>
We assume the following notation: -1, -2, etc. to denote: the last person, the penultimate person, etc. respectively. Then:
n = 11 and k = 11 give the same result as n = 11 and k = -1,
n = 7 and k = 5 give the same result as n = 7 and k = -3.
<br><br>
**Input:**<br>
In the first line: the number of subsequent lines.
In the following lines: n and k separated by spaces.<br><br>
**Output:**<br>
In the consecutive lines: a place in a circle.