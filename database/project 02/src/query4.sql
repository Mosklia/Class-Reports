SELECT C.cno AS cno, E.sectno AS sectno, COUNT(E.sid) AS cnt
FROM course C
INNER JOIN enroll E ON C.cno = E.cno
GROUP BY C.cno, E.sectno
HAVING COUNT(E.sid) <= 9;
