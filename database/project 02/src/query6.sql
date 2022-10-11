SELECT DISTINCT M.dname
FROM (
    SELECT S.sid AS sid
    FROM student S
    WHERE S.age <= 18
) AS Tmp
INNER JOIN major M ON M.sid = Tmp.sid;
