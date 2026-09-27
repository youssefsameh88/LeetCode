SELECT t1.id ,
CASE WHEN t1.p_id IS NULL THEN 'Root'
     WHEN COUNT(t2.p_id) > 0 THEN 'Inner'  ELSE 'Leaf' END
AS type
FROM tree t1
LEFT JOIN tree t2
ON t1.id = t2.p_id
GROUP BY t1.id, t2.p_id, t1.p_id
ORDER BY t1.id
