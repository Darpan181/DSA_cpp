# Write your MySQL query statement below
WITH cntUser AS(
    SELECT
        COUNT(*) AS totalUser
    FROM 
        Users
)
SELECT 
    r.contest_id,
    ROUND(COUNT(*) * 100 / c.totalUser , 2) AS percentage
FROM 
    Register r
CROSS JOIN
    cntUser c
GROUP BY
    contest_id
ORDER BY
    percentage DESC,
    r.contest_id ASC;
