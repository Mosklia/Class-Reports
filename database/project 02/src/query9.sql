SELECT S.sname
FROM student AS S
WHERE S.sid IN (
    SELECT E.sid
    FROM enroll E
    INNER JOIN course C ON E.cno = C.cno
    WHERE C.dname = "Mathematics" AND E.sid IN (
        SELECT E.sid
        FROM enroll E
        INNER JOIN course C ON E.cno = C.cno
        WHERE C.dname = "Computer Sciences"
    )
);
