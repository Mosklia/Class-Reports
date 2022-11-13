SELECT I.item, Tmp.cnt
FROM item I
INNER JOIN (
    SELECT VAL(S.selection) AS sel, COUNT(*) as cnt
    FROM selection S
    WHERE S.question_id = 1
    GROUP BY S.selection
) AS Tmp ON Tmp.sel = I.item_id;
