SELECT MAX(S.age) - MIN(S.age) AS agediff
FROM student S
INNER JOIN major M ON M.sid = S.sid
WHERE M.dname = "Computer Sciences";