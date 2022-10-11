SELECT P.pname
FROM prof P, dept D
WHERE P.dname = D.dname AND D.numphds < 50;
