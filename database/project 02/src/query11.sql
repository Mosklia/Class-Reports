SELECT Tmp.dname, Tmp.avggpa
FROM (
    SELECT M.dname AS dname, AVG(S.gpa) AS avggpa
    FROM major M
    INNER JOIN student S ON M.sid = S.sid
    GROUP BY M.dname
) AS Tmp
WHERE Tmp.dname IN (
    SELECT DISTINCT M.dname AS dname
    FROM major M
    INNER JOIN student S ON M.sid = S.sid
    WHERE S.gpa <= 1.0
);
