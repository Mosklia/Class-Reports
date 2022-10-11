SELECT S.sname, S.sid
FROM (
    SELECT E.sid AS sid, COUNT(E.cno) AS cnt
    FROM enroll E
    GROUP BY E.sid
) AS Tmp
INNER JOIN student AS S ON S.sid = Tmp.sid
WHERE Tmp.cnt IN (
    SELECT MAX(Tmp2.cnt)
    FROM (
        SELECT COUNT(E2.cno) AS cnt
        FROM enroll E2
        GROUP BY E2.sid
    ) AS Tmp2
);
