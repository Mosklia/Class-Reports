SELECT S.sname
FROM student S
WHERE S.gpa IN (
    SELECT MIN(S2.gpa)
    FROM student S2
);
