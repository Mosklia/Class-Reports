SELECT Tmp.sname, Tmp.dname
FROM (
    SELECT S.sname AS sname, S.sid AS sid, M.dname AS dname
    FROM student S
    INNER JOIN major M ON M.sid = S.sid
) AS Tmp
WHERE Tmp.sid IN (
    SELECT E.sid AS sid
    FROM enroll E
    INNER JOIN course C ON E.cno = C.cno
    WHERE C.cname LIKE "College Geometry*"
);
