SELECT E.cno AS cno, E.sectno AS sectno, AVG(S.gpa) AS avggpa
FROM student S
INNER JOIN enroll E ON E.sid = S.sid
WHERE E.dname = "Computer Sciences"
GROUP BY E.cno, E.sectno;
