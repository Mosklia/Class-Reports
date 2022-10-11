SELECT D.dname, D.numphds
FROM dept AS D
WHERE D.dname NOT IN (
    SELECT M.dname
    FROM major M
    WHERE M.sid IN (
        SELECT E.sid
        FROM enroll E
        INNER JOIN course C ON E.cno = C.cno
        WHERE C.cname LIKE "College Geometry*"
    )
);
