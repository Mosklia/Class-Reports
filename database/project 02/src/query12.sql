SELECT S.sid, S.sname, S.gpa
FROM student S
INNER JOIN (
    SELECT Tmp.sid AS sid, COUNT(Tmp.cno) AS ccnt
    FROM (
        SELECT DISTINCT E.sid AS sid, E.cno AS cno
        FROM enroll E
        INNER JOIN course C ON C.cno = E.cno
        WHERE C.dname = "Civil Engineering"
    ) AS Tmp
    GROUP BY Tmp.sid
) AS Tmp2 ON Tmp2.sid = S.sid
WHERE Tmp2.ccnt IN (
    SELECT COUNT(C.cno)
    FROM course C
    WHERE C.dname = "Civil Engineering"
);
